cmake_minimum_required(VERSION 2.6)
project(aio_bindings)

add_executable(aio_bindings main.cpp)

install(TARGETS aio_bindings RUNTIME DESTINATION bin)
