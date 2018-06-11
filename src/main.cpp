#include "game.h"

int main(int argc, char *argv[])
{
  Game game;
  game.Init("Hope Engine",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    1280, 720, 
    false
  );

  while (game.IsRunning)
  {
    game.HandleEvents();
    game.Update();
    game.Render();
  }

  game.DeInit();

  return 0;
}