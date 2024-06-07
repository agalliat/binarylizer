#define SDL_MAIN_HANDLED

#include "Core/Application.hpp"

int main() {
  App::Application app{"App"};
  app.run();

  return 0;
}
