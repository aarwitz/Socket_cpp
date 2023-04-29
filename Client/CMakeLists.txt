cmake_minimum_required(VERSION 3.13)

project(client)

add_library(client client.cpp)

set_target_properties(client PROPERTIES PUBLIC_HEADER ../socket.hpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -I. -c")
install(TARGETS client LIBRARY DESTINATION lib
		PUBLIC_HEADER DESTINATION include)
