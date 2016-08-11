// TODO add permissive license here
#ifndef IMGUI_GL_WRAPPER
#define IMGUI_GL_WRAPPER

#include <imgui.h>
#include "imgui_impl_glfw_gl3.h"
#include <stdio.h>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

/*
int imgui_window_init(int width, int height, const char* title, GLFWwindow* window)
{
    // Setup window
    assert(window != nullptr);
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return 1;
    window = glfwCreateWindow(NULL, NULL);
    glfwMakeContextCurrent(window);

    // Setup ImGui binding
    ImGui_ImplGlfw_Init(window, true);
    return 0;
}

void imgui_window_shutdown()
{
    ImGui_ImplGlfw_Shutdown();
    glfwTerminate();
}

void imgui_window_render(GLFWwindow* window, ImVec4& clear_color)
{
    // Rendering
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    glfwSwapBuffers(window);
}
*/

bool imgui_gl3_window_init(int width, int height, const char* title, GLFWwindow* window)
{
    if (window != NULL)
    {
      return false;
    }
    // Setup window
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return false;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);
    gl3wInit();

    // Setup ImGui binding
    ImGui_ImplGlfwGL3_Init(window, true);

    return true;
}
void imgui_gl3_window_shutdown()
{
    // Cleanup
    ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();
}

void imgui_gl3_window_render(GLFWwindow* window, ImVec4 & clear_color)
{
    // Rendering
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    glfwSwapBuffers(window);
}


#endif  // IMGUI_GL_WRAPPER
