cmake_minimum_required(VERSION 3.12)
project(FreeLibraryIssue)

add_library(shared_lib SHARED src/shared_lib.cpp)

add_executable(app src/main.cpp)

# Change the working dir as by default MSVC working dir is not where we expect for this test
set_target_properties(app PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/Debug")