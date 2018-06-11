#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <stdio.h>

struct Game {
  Game();
  ~Game();

  void Init(const char* title, const int x, const int y, const int width, const int height, const bool fullscreen);
  void HandleEvents();
  void Update();
  void Render();
  void DeInit();

  bool IsRunning;
  SDL_Window *Window;
  SDL_Renderer *Renderer;

private:
  void _calculateDeltaTime();
  float dt;
  
};

#endif