SET(INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/Include)
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})
SET(INCLUDE_FILES Include/Math/Math.hpp Include/Math/Vector3.hpp)
SET(SOURCE_FILES Source/Vector3.cpp)
ADD_LIBRARY(Math STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
# Export the include directory.
SET(MATH_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

# Make a unit test holder for the Math library.
IF(BUILD_UNIT_TESTS)
    ADD_GMOCK_TEST(_TestMath
        Tests/Main.cpp
        Tests/TestAll.hpp
        Tests/TestConstruction.hpp
    )
    TARGET_LINK_LIBRARIES(_TestMath Math)
ENDIF(BUILD_UNIT_TESTS)
