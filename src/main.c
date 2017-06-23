/*

  Project: Cube
  
  Description: A simple voxel renderer written in C using OpenGL for rendering


 */


// Includes
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <kazmath/vec3.h>

// Defines
#define NAME "Cube"
#define WIDTH 800
#define HEIGHT 600

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  

int main() {
  printf("%s initialized\n", NAME);

  // Setup GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, NAME, NULL, NULL);

  if (window == NULL) {
    printf("Failed to create GLFW Window\n");
    glfwTerminate();

    return -1;
  }

  glfwMakeContextCurrent(window);

  // Load extensions
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      printf("Failed to initialize GLAD\n");
      return -1;
  }   

  glViewport(0, 0, WIDTH, HEIGHT);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

  // Render loop
  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();    
  }

  
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  
