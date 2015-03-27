CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
PROJECT("To Do List")

# Allow unit tests to be disabled via command line or the CMake GUI.
OPTION(BUILD_UNIT_TESTS "Build unit tests." ON)
# Enable the CMake built in CTest system if unit tests are enabled.
IF(BUILD_UNIT_TESTS)
    ENABLE_TESTING()
ENDIF(BUILD_UNIT_TESTS)

IF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(WARNINGS "-Wall -Wextra -Werror")
ELSEIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    SET(WARNINGS "/W4 /WX /EHsc")
ENDIF()
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS}")

ADD_EXECUTABLE(ToDo Main.cpp ToDo.cpp)
ADD_TEST(ToDoTest ToDo)
