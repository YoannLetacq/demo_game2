cmake_minimum_required(VERSION 3.26)
project(litle_word)

set(CMAKE_CXX_STANDARD 17)

add_executable(litle_word main.cpp
        character.cpp
        prop.h
        prop.cpp
        enemy.h
        enemy.cpp
        base_character.h
        base_character.cpp
)
target_link_libraries(litle_word raylib)
