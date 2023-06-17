cmake_minimum_required(VERSION 3.22.1)

project(clientEx)

add_executable(clientEx clientEx.cpp)

#target_link_libraries(muhderp mearlymath)
target_link_libraries(clientEx client)
