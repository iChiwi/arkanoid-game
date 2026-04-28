cmake_minimum_required(VERSION 3.20)
project(arkanoid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(arkanoid)

target_sources(arkanoid
    PRIVATE
        src/main.cpp
        src/Game.cpp
        src/Input.cpp
)

target_include_directories(arkanoid
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(arkanoid PRIVATE freeglut opengl32)
