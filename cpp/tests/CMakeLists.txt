find_package(GTest REQUIRED)

set(TESTS
    type_sequence_test.cpp
    type_helpers_test.cpp
    bit_flag_test.cpp
    macros_test.cpp
)

add_executable(gtests ${TESTS})
target_link_libraries(gtests GTest::gtest GTest::gtest_main pthread)
target_include_directories(gtests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
