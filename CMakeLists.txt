cmake_minimum_required(VERSION 3.9)
project(Cavestory)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cavestory main.cpp headers/Graphics.h src/Graphics.cpp headers/Game.h src/Game.cpp headers/Input.h src/Input.cpp headers/Sprite.h src/Sprite.cpp headers/globals.h headers/AnimatedSprite.h src/AnimatedSprite.cpp headers/Player.h src/Player.cpp headers/Level.h src/Level.cpp)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(Cavestory ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})