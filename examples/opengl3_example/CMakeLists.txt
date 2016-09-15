find_package(OpenGL)
find_package(glfw3)

if (NOT ${glfw3_FOUND})
  message(WARNING "glfw3 not found, not building visualization example")
  set(imgui_glfw3_BUILT FALSE)
  return()
endif()
set(imgui_glfw3_BUILT TRUE)

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
