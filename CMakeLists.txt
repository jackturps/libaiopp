cmake_minimum_required( VERSION 3.2.2 )
project( aio_bindings )

set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

add_executable( aio_bindings main.cc AIOContext.cc )

target_link_libraries( aio_bindings aio )