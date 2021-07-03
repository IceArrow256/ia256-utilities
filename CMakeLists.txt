cmake_minimum_required(VERSION 3.20)

project(ia256-utilities VERSION 0.2.0)

find_package(Catch2 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(ia256-utilities)

target_sources(ia256-utilities PRIVATE
              ${CMAKE_CURRENT_SOURCE_DIR}/src/system.cpp
              ${CMAKE_CURRENT_SOURCE_DIR}/src/dirs.cpp
              )

target_include_directories(ia256-utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(tests EXCLUDE_FROM_ALL)
target_sources(tests PRIVATE
              ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp
              ${CMAKE_CURRENT_SOURCE_DIR}/src/system.cpp
              ${CMAKE_CURRENT_SOURCE_DIR}/src/dirs.cpp
              )
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tests PRIVATE Catch2::Catch2)

add_custom_target(run-tests COMMAND $<TARGET_FILE:tests>)
add_dependencies(run-tests tests)
