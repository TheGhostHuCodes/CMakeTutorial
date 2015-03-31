CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
PROJECT("To Do List")

# Look in here for googlemock.
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/External/CMake/Modules)

# Allow unit tests to be disabled via command line or the CMake GUI.
OPTION(BUILD_UNIT_TESTS "Build unit tests." ON)
# Enable the CMake built in CTest system if unit tests are enabled.
IF(BUILD_UNIT_TESTS)
    ENABLE_TESTING()
    INCLUDE(gmock)
ENDIF(BUILD_UNIT_TESTS)

# Find Boost.
IF(APPLE OR WIN32)
    set(Boost_USE_STATIC_LIBS TRUE)
ENDIF(APPLE OR WIN32)
FIND_PACKAGE(Boost 1.57 REQUIRED COMPONENTS program_options)
INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIRS})

IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(WARNINGS "-Wall -Wextra -Werror")
ELSEIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    SET(WARNINGS "/W4 /WX /EHsc")
ENDIF()
IF(NOT CONFIGURED_ONCE)
    SET(CMAKE_CXX_FLAGS "${WARNINGS}"
        CACHE STRING "Flags used by the compiler during all build types."
        FORCE)
ENDIF(NOT CONFIGURED_ONCE)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
ADD_SUBDIRECTORY(ToDoCore)

ADD_EXECUTABLE(ToDo Main.cpp)
TARGET_LINK_LIBRARIES(ToDo ToDoCore ${Boost_LIBRARIES})

SET(CONFIGURED_ONCE TRUE CACHE INTERNAL
        "A flag showing that CMake has configured at least once.")
