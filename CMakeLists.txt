cmake_minimum_required(VERSION 3.10)



project(cxxproject1 VERSION 0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14")





add_subdirectory(src)



target_include_directories(main PUBLIC /usr/include/allegro5)
