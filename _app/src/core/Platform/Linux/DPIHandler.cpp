#include "Core/DPIHandler.hpp"

#include <SDL2/SDL.h>
#include <imgui.h>

#include "Core/Window.hpp"

namespace App {

float DPIHandler::get_scale() {
  constexpr int display_index{0};
  const float default_dpi{96.0F};
  float dpi{default_dpi};

  SDL_GetDisplayDPI(display_index, nullptr, &dpi, nullptr);

  return dpi / default_dpi;
}

WindowSize DPIHandler::get_dpi_aware_window_size(const Window::Settings& settings) {
  return {settings.width, settings.height};
}

void DPIHandler::set_global_font_scaling([[maybe_unused]] ImGuiIO* io) {
  // do nothing
}

}  // namespace App
