add_executable(metrology_unit_tests
  test_framework_info.cpp
)

target_link_libraries(metrology_unit_tests
  PRIVATE
    metrology_core
    GTest::gtest_main
)

target_compile_features(metrology_unit_tests PRIVATE cxx_std_17)

include(GoogleTest)
gtest_discover_tests(metrology_unit_tests)
