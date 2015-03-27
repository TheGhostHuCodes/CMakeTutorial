CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
PROJECT("To Do List")

# Allow unit tests to be disabled via command line or the CMake GUI.
OPTION(BUILD_UNIT_TESTS "Build unit tests." ON)
# Enable the CMake built in CTest system if unit tests are enabled.
IF(BUILD_UNIT_TESTS)
    ENABLE_TESTING()
ENDIF(BUILD_UNIT_TESTS)

ADD_EXECUTABLE(ToDo Main.cpp ToDo.cpp)
ADD_TEST(ToDoTest ToDo)
