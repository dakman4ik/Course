cmake_minimum_required(VERSION 3.16)
project(CourseTests LANGUAGES CXX)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG v2.5.3
)
FetchContent_MakeAvailable(doctest)

enable_testing()
add_executable(course_tests tests/test_course.cpp)
target_include_directories(course_tests PRIVATE .)
target_link_libraries(course_tests PRIVATE doctest::doctest)
add_test(NAME course_tests COMMAND course_tests)