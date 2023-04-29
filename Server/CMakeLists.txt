cmake_minimum_required(VERSION 3.13)

project(server)

add_library(server server.cpp)

set_target_properties(server PROPERTIES PUBLIC_HEADER ../socket.hpp)

install(TARGETS server LIBRARY DESTINATION lib
		PUBLIC_HEADER DESTINATION include)