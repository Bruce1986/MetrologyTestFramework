include(FetchContent)

option(METROLOGY_USE_SYSTEM_GTEST "Link against an existing GoogleTest installation if available" OFF)

if(METROLOGY_USE_SYSTEM_GTEST)
  find_package(GTest CONFIG REQUIRED)
else()
  if(NOT TARGET GTest::gtest)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        v1.15.2
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
  endif()
endif()

# Placeholder hook for additional dependencies. Vendor SDKs that are unavailable in
# open-source environments should define stub implementations guarded behind
# dedicated CMake options. Keep all `find_package` logic and related configuration
# here so contributors can reason about dependency management in a single file.
function(metrology_register_optional_dependency dependency_name)
  message(STATUS "Optional dependency requested: ${dependency_name}")
  # Future work: extend this helper to locate vendor libraries or activate mocks.
endfunction()
