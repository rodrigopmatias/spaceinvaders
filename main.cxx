#include "main.hxx"

GameWorld * world;

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

  std::thread tickerThread(ticker, window);
  std::thread statusThread(statusLog, window);

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyboardCallback);

  world = new GameWorld(window);

  while(!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    world->turn();
    world->draw();

    glfwSwapBuffers(window);
    frameCount++;

    glfwPollEvents();
  }

  tickerThread.join();
  statusThread.join();

  delete world;
  glfwTerminate();

  return 0;
}

void keyboardCallback(GLFWwindow * window, int key, int scancode, int action, int mode) {

  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS && mode == 0)
    glfwSetWindowShouldClose(window, GL_TRUE);
  else if(key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == 2))
    world->turnLeft();
  else if(key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == 2))
    world->turnRight();
  else if(key == GLFW_KEY_SPACE && (action == GLFW_PRESS || action == 2))
    world->turnFire();
  else {
    std::cout << "key => " << key;
    std::cout << "; ";
    std::cout << "scancode => " << scancode;
    std::cout << "; ";
    std::cout << "action => " << action;
    std::cout << "; ";
    std::cout << "mode => " << mode;
    std::cout << std::endl;
  }

  if(world)
    world->draw();
}

void framebufferSizeCallback(GLFWwindow * window, int width, int height) {
  glViewport(0, 0, width, height);
}

void ticker(GLFWwindow * window) {
  while(!glfwWindowShouldClose(window)) {
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + frame_duration(100);
    std::this_thread::sleep_until(end_time);
  }
}

void statusLog(GLFWwindow * window) {
  while(!glfwWindowShouldClose(window)) {
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + frame_duration(1000);

    std::cout << "rate: \033[1m\033[32m" << frameCount << "\033[0m fps" << std::endl;
    frameCount = 0;
    std::this_thread::sleep_until(end_time);
  }
}
