cmake_minimum_required(VERSION 3.17)
project(cpp-calendar)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(calendar calendar.cpp)
target_link_libraries(calendar ${CONAN_LIBS})