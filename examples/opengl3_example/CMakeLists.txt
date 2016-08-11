find_package(OpenGL)
find_package(PkgConfig)
pkg_search_module(glfw3 REQUIRED glfw3)

add_library(gl3w
  ../libs/gl3w/GL/gl3w.c
)
target_include_directories(gl3w
  PUBLIC
  ../libs/gl3w/
)

target_link_libraries(gl3w ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY} dl)

add_library(imgui_gl3
  imgui_impl_glfw_gl3.cpp
)
target_include_directories(imgui_gl3 PUBLIC ${IMGUI_PATH})

target_link_libraries(imgui_gl3 imgui gl3w)
