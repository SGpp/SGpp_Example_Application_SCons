import os
project_root = os.path.dirname(os.path.abspath('SConstruct'))
project_include = project_root + '/include'
project_build = project_root + '/build'
project_src = project_root + '/src'

env=Environment(CPPPATH=project_include,
               CPPDEFINES=[],
               LIBS=[])

if ARGUMENTS.get('debug', 0):
    env.Append(CCFLAGS = ' -g')

env.SConscript('src/SConscript', variant_dir='build', exports='env', duplicate=0, CPPPATH='include')
