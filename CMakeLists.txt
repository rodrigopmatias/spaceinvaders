cmake_minimum_required(VERSION 3.5)

project(spi)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_library(Threads REQUIRED)

add_executable(spi
  main.cxx
  game/object.cxx
  game/world.cxx
  game/aircraft.cxx
  game/bullet/bullet.cxx
  game/enemy/enemy.cxx
  game/enemy/boss.cxx
  game/enemy/corbi.cxx
  game/enemy/darbi.cxx
  game/enemy/morbi.cxx)

target_link_libraries(${CMAKE_PROJECT_NAME}
  glfw
  GLEW
  GLU
  GL
  pthread)
