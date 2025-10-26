cmake_minimum_required(VERSION 3.10)
project(service_a LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(service_a src/server.cpp)
target_include_directories(service_a PRIVATE ${CMAKE_SOURCE_DIR}/include)
