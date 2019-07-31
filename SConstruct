import os
from subprocess import call
import multiprocessing

#================================================================================================================================================
# General setup
#================================================================================================================================================

# Create Scons environment 
env=Environment(CPPPATH=[],
               CPPDEFINES=[],
               LIBS=[])

# Relevant directories
project_root = os.path.dirname(os.path.abspath('SConstruct'))
project_include = project_root + '/include'
project_dependencies_sgpp = project_root + '/external_dependencies/SGpp'

#================================================================================================================================================
# Setup and build SGpp as a dependency of the actual application project
#================================================================================================================================================

# Add option to build sgpp
AddOption('--build-sgpp',
          dest='build-sgpp',
          nargs=1, type='string',
          action='store',
          metavar='DIR',
          help='installation prefix')

# Does the SGpp submodule directory exist? If not, print error and exit
if not os.path.exists(project_dependencies_sgpp):
    print("FATAL_ERROR! Could not find the SConstruct file within the SGpp directory!\n"\
            "To fix this error, clone to SGpp submodule by running the following command"\
            "within the project root directory:\n"\
            "git submodule update --init external_dependencies/SGpp")
    quit()
# If build-sgpp flag is set to True, build SGpp again
if GetOption('build-sgpp') == 'True':
    # Get processor count for parallel builds
    parallel_builds = multiprocessing.cpu_count()
    # Build SGpp 
    # We build all modules to demonstrate how it is done - to save compile time you might want to deactivate some modules
    call(["scons", "SG_BASE=1", "SG_DATADRIVEN=1", "SG_COMBIGRID=1", "SG_OPTIMIZATION=1", # Flags for which SGpp modules to build
          "SG_QUADRATURE=1", "SG_SOLVER=1", "SG_PDE=1", "SG_MISC=1",               # Flags for which SGpp modules to build
          "SG_JAVA=0", "SG_PYTHON=0", "SG_MATLAB=0",                               # Which language wrappers should be created
          "RUN_BOOST_TESTS=0", "RUN_PYTHON_TESTS=0",                               # Do not run any unit tests
          "OPT=1",                                                                 # Create optimized build
          "PRINT_INSTRUCTIONS=0", "VERBOSE=0", "-j" + str(parallel_builds)],       # Convienience flags for silent and fast build
         cwd=project_dependencies_sgpp)                                            # Working directory (submodule folder)      


# Add SGpp Header paths, one path per SGpp Module
env.Append(CPPPATH=[project_dependencies_sgpp + "/base/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/datadriven/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/combigrid/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/optimization/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/quadrature/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/solver/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/pde/src"])
env.Append(CPPPATH=[project_dependencies_sgpp + "/misc/src"])

# Add SGpp Module Libraries - if you deactivate one SG++ module, you have to remove the respective line as well
# since the library file won't be there
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppbase.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppdatadriven.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppcombigrid.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppoptimization.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppquadrature.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppsolver.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgpppde.so")])
env.Append(LIBS=[File(project_dependencies_sgpp + "/lib/sgpp/libsgppmisc.so")])

#================================================================================================================================================
# Setup and build application
#================================================================================================================================================

# We want to have at least C++11
env.Append(CXXFLAGS="-std=c++11")

# Include application headers
env.Append(CPPPATH=[project_include])

# Call Sconscript in the src directory -> do the build in the build directory with variant_dir
env.SConscript('src/SConscript', variant_dir='build', exports='env', duplicate=0, CPPPATH='include')
