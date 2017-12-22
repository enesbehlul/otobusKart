cmake_minimum_required(VERSION 3.9)
project(otobusKart)

set(CMAKE_CXX_STANDARD 11)

add_executable(otobusKart main.cpp user.cpp user.h person.cpp person.h admin.cpp admin.h card.cpp card.h)