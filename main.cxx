#include "main.hxx"

int main(int argc, char ** argv) {
  GLFWwindow * window;

  if(!glfwInit()) {
    std::cout << "Não consegui inicializar o framework OpenGL." << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_DEPTH_BITS, 8);
  window = glfwCreateWindow(640, 480, "Space Invader", 0, 0);

  if(!window) {
    std::cout << "Não pude criar a janela com contexto OpenGL." << std::endl;
    return -2;
  }

  glewExperimental = GL_TRUE;
  if(!glewInit() != GLEW_OK) {
    std::cout << "Não pude inicializar o GLEW." << std::endl;
    return -3;
  }

  std::thread();

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyboardCallback);

  while(!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    renderWorld(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}

void keyboardCallback(GLFWwindow * window, int key, int scancode, int action, int mode) {

  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS && mode == 0)
    glfwSetWindowShouldClose(window, GL_TRUE);
  else {
    std::cout << "key => " << key;
    std::cout << " | ";
    std::cout << "scancode => " << scancode;
    std::cout << " | ";
    std::cout << "action => " << action;
    std::cout << " | ";
    std::cout << "mode => " << mode;
    std::cout << std::endl;
  }

  renderWorld(window);
}

void renderWorld(GLFWwindow * window) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -100, 100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBegin(GL_QUADS);
  glColor3f(0.9f, 0.9f, 0.0f);
  glVertex2f(-0.5, -70.0);
  glVertex2f(0.5, -70.0);
  glVertex2f(0.5, -65.0);
  glVertex2f(-0.5, -65.0);
  glEnd();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -100, 100);

  glTranslatef(50.0f, 0.0f, 0.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBegin(GL_QUADS);
  glColor3f(0.5f, 0.0f, 0.0f);
  glVertex2f(-10.0, -90.0);
  glVertex2f(10.0, -90.0);
  glVertex2f(10.0, -80.0);
  glVertex2f(-10.0, -80.0);
  glEnd();
}

void framebufferSizeCallback(GLFWwindow * window, int width, int height) {
  glViewport(0, 0, width, height);
}
