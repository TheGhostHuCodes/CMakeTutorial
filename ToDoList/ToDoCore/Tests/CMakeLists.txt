# ADD_GMOCK_TEST(<target> <sources>...)
#
# Adds a googlemock based test executable, <target>, built from <sources> and
# adds the test so that CTest will run it. Both the executable and the test
# will be named <target>.
FUNCTION(ADD_GMOCK_TEST TARGET)
    ADD_EXECUTABLE(${TARGET} ${ARGN})
    TARGET_LINK_LIBRARIES(${TARGET} gmock)
    INCLUDE_DIRECTORIES(${GMOCK_INCLUDE_DIRS})
    ADD_TEST(${TARGET} ${TARGET})
ENDFUNCTION(ADD_GMOCK_TEST)

ADD_GMOCK_TEST(ToDoTest ToDoTest.cpp)
TARGET_LINK_LIBRARIES(ToDoTest ToDoCore)
