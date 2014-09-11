cmake_minimum_required(VERSION 2.8)
# Project Name
PROJECT(simulation)

#########################################################
# Include Files
#########################################################
file(GLOB exec_source "src/*.cpp" "include/*.h*")
#add_executable(main src/main.cpp src/agent.cpp src/target.cpp src/simulation.cpp src/visualization.cpp)
add_executable(main ${exec_source})
########################################################
# Linking & stuff
#########################################################
set(CMAKE_MODULE_PATH "PATH_TO/CMakeModules;${CMAKE_MODULE_PATH}") 
FIND_PACKAGE(OpenThreads)
FIND_PACKAGE(OSG)
FIND_PACKAGE(osgDB)
FIND_PACKAGE(osgViewer)
include_directories(${OSG_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(main ${OSG_LIBRARY} ${OSGUTIL_LIBRARY}
${OSGDB_LIBRARY} ${OSGVIEWER_LIBRARY} ${OPENTHREADS_LIBRARY})
