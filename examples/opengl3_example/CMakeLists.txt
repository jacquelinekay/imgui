find_package(OpenGL)

add_library(gl3w
  ../libs/gl3w/GL/gl3w.c
)
target_include_directories(gl3w
  PUBLIC
  ../libs/gl3w/
)

target_link_libraries(gl3w ${OPENGL_gl_LIBRARIES})

add_library(imgui_gl3
  imgui_impl_glfw_gl3.cpp
)
target_include_directories(imgui_gl3 PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(imgui_gl3 imgui gl3w)
