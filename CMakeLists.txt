cmake_minimum_required(VERSION 3.5)

project(spi)

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

find_library(Threads REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME} glut GLU GL ${CMAKE_THREAD_LIB_INIT})
