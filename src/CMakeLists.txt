add_library(metrology_core STATIC
  framework_info.cpp
)

target_include_directories(metrology_core
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(metrology_core PUBLIC cxx_std_17)

add_executable(metrology_app main.cpp)

target_link_libraries(metrology_app PRIVATE metrology_core)
