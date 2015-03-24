CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
IF(APPLE)
    ADD_COMPILE_OPTIONS(-std=c++11)
ENDIF(APPLE)
PROJECT(CMakeEnvironment)
# Allow unit tests to be disabled via command line or the CMake GUI.
OPTION(BUILD_UNIT_TESTS "Build unit tests." ON)

#IF(APPLE)
#    INCLUDE_DIRECTORIES(External/CMake/GMock)
#ENDIF(APPLE)

INCLUDE(External/CMakeLists.txt)
INCLUDE(Libraries/CMakeLists.txt)
ADD_SUBDIRECTORY(Applications)
ADD_SUBDIRECTORY(Tools)
