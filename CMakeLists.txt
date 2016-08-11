cmake_minimum_required(VERSION 2.6)

project(dear_imgui)

add_library(imgui
  imgui.cpp
  imgui_demo.cpp
  imgui_draw.cpp
)

add_subdirectory(examples/opengl3_example)

install(TARGETS imgui
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION lib
)

install(
  FILES imgui.h
  DESTINATION include
)
