CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
IF(APPLE)
    ADD_COMPILE_OPTIONS(-std=c++11)
ENDIF(APPLE)
PROJECT(CMakeEnvironment)

# Look in here for googlemock.
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/External/CMake/Modules)

# Allow unit tests to be disabled via command line or the CMake GUI.
OPTION(BUILD_UNIT_TESTS "Build unit tests." ON)
# Enable the CMake built in CTest system if unit tests are enabled.
IF(BUILD_UNIT_TESTS)
    ENABLE_TESTING()
    INCLUDE(gmock)
ENDIF(BUILD_UNIT_TESTS)

#INCLUDE(External/CMakeLists.txt)
INCLUDE(Libraries/CMakeLists.txt)
ADD_SUBDIRECTORY(Applications)
ADD_SUBDIRECTORY(Tools)
