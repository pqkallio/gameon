cmake_minimum_required (VERSION 3.10)

project(gameon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(ExternalProject)
include(GNUInstallDirs)
enable_testing()

# Add SFML
ExternalProject_Add(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG "2.5.1"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/sfml
)

link_directories(${CMAKE_BINARY_DIR}/googletest/${CMAKE_INSTALL_LIBDIR} ${CMAKE_BINARY_DIR}/sfml/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/googletest/${CMAKE_INSTALL_INCLUDEDIR} ${CMAKE_BINARY_DIR}/sfml/${CMAKE_INSTALL_INCLUDEDIR})

file(GLOB gameon_src
    RELATIVE ${PROJECT_SOURCE_DIR}
    "src/main.cpp"
    "src/game/*.cpp"
)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,clang-analyzer-*,google-*,modernize-*,performance-*,readability-*,readability-magic-numbers,cert-*,bugprone-*,misc-* -warnings-as-errors=-*,clang-analyzer-*,google-*,hicpp-*,modernize-*,performance-*,readability-*,readability-magic-numbers,cert-*,bugprone-*,misc-*,fuchsia-*)

# Executable name to be built
add_executable(${PROJECT_NAME} ${gameon_src})
add_dependencies(${PROJECT_NAME} sfml)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-system
    sfml-window
    sfml-graphics
)

# Compiler options per platform
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 -O2)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -O2)
endif()

unset(CMAKE_CXX_CLANG_TIDY)

ExternalProject_Add(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/googletest
)

set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

find_package(Threads REQUIRED)

# Use all .cpp files in the test folder
file(GLOB_RECURSE TEST_SOURCES
    RELATIVE ${PROJECT_SOURCE_DIR}
    CONFIGURE_DEPENDS
    src/test/*.cpp)

set(PROJECT_TESTER_NAME ${PROJECT_NAME}_test)
add_executable(${PROJECT_TESTER_NAME} ${TEST_SOURCES})
add_dependencies(${PROJECT_TESTER_NAME} googletest)
target_link_libraries(${PROJECT_TESTER_NAME} gtest gtest_main Threads::Threads)

add_test(${PROJECT_TESTER_NAME} ${PROJECT_TESTER_NAME})

# Add make tester that builds tests and runs them
add_custom_target(tester
    COMMAND ${PROJECT_TESTER_NAME} || true # suppress verbose errors
    DEPENDS ${PROJECT_TESTER_NAME})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
