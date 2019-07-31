# SGpp_Example_Application_SCons

[![Build Status](https://travis-ci.org/SGpp/SGpp_Example_Application_SCons.svg?branch=master)](https://travis-ci.org/SGpp/SGpp_Example_Application_SCons)

## Purpose of this repository

This repository is the SCons variant of [another repository](https://github.com/SGpp/SGpp_Example_Application_CMake) that shows the exact same example application but is using CMake instead of SCons.
Both repositories are meant to serve as a starting point for people who want to use [SG++](https://github.com/SGpp/SGpp) in a project of their own. 
This one demonstrates how to use git submodules to include SG++ as an external dependency and how to use SCons to both build SG++ and the project itself.

Feel free to use the code in this repository as you see fit!

## How to build

To build this application, you need to fullfill all [required dependencies](https://github.com/SGpp/SGpp/wiki/Linux-(GCC-Clang-ICC)#dependencies) of SG++. 

### 1. Clone repository
`git clone https://github.com/SGpp/SGpp_Example_Application_SCons.git`

`cd my_example`
### 2. Checkout SGpp submodule
`git submodule update --init external_dependencies/SGpp`

The submodule is not checked out during a normal git clone. Thus, we do it this way.

### 3. Variant 1: Run SCons building both the application and the SG++ submodule
`scons --build-sgpp=True`

This command will both build the project as well as SG++. As this compiles SG++ from scratch, this will take time! The SG++ unit tests, however, are switched off to save time. In this example, we build all modules of SG++ in order to demonstrate how to include the headers and link the libraries of all SG++ modules with your own application. Thus, you can reduce the compile time further by deactivating modules (see section below) that you do not need for your own project.

After the command is done, you can call the application within the build directory with `./build/quadrature`
### 3. Variant 2: Run SCons to only build the application
`scons`

This command will only build the actual example application. It will not build SG++ again in order to save compilation time.

## How to modify the SG++ build
The utilized SG++ version can simply be changed by going to the (checked out) submodule folder external_dependencies/SGpp and changing the commit there as one would in a normal git repository. Afterwards, SG++ needs to be build again with `scons --build-sgpp=True` as shown above.

To change the way SG++ is built, you need to modify the SConstruct file given in this repositoy. Here, you will find a subprocess call which is starting SCons in the SG++ submodule directory. By modifying this SCons command you can change the way SG++ is built. For example you could deactivate the datadriven module by changing the flag SG_DATADRIVEN=0 and by further removing the library libsgppdatadriven.so from the LIBS list.

There are plenty of other things to change about the SG++ build, for example you may want to activate the python wrappers.
To see all ways to configure SCons for SG++, go to the (checked out) submodule directory and run
`scons -h`

or visit the respective [SG++ Wiki page](https://github.com/SGpp/SGpp/wiki/Linux-(GCC-Clang-ICC)#compilation-with-scons) for more information.

## About the utilized example
The application itself shows how to integrate functions in SG++, using both direct integration of a sparse grid function and the use of Monte Carlo integration.
It is heavily based on the SG++ example [quadrature.cpp](https://github.com/SGpp/SGpp/blob/master/base/examples/quadrature.cpp) (see also the [full example doc]( http://sgpp.sparsegrids.org/example_quadrature_cpp.html) from the [SG++ doxygen documentation](http://sgpp.sparsegrids.org/index.html)). However, unlike the quadrature example alone, this repository further shows how to build your own projects utilizing SG++.
