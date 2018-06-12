#include "game.h"
#include "entity.h"
#include "textureManager.h"

TextureId tilesetTextureId = 0;
EntityManager entityManager;

Game::Game() 
  : IsRunning(false),
    Window(nullptr),
    Renderer(nullptr),
    dt(0.0f)
  {}

Game::~Game() {}


void Game::Init(const char *title, 
                const int x, const int y, 
                const int width, const int height, 
                const bool fullscreen)
{
  IsRunning = true;
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { IsRunning = false; return; }

  Uint32 flags = fullscreen 
    ? SDL_WINDOW_FULLSCREEN 
    : 0;
  Window = SDL_CreateWindow(title, x, y, width, height, flags);
  if (!Window) { IsRunning = false; return; }
  Renderer = SDL_CreateRenderer(Window, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!Renderer) { IsRunning = false; return; }
  tilesetTextureId = TextureManager::LoadTexture(".\\data\\tileset.png", Renderer);
  
}

void Game::HandleEvents()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
      {
        IsRunning = false;
      } break;
    }
  }
}

void Game::_calculateDeltaTime() {
  static Uint32 lastTime = SDL_GetTicks();
  Uint32 thisTime = SDL_GetTicks();
  dt = (float)(thisTime - lastTime) / 1000.0f;
  lastTime = thisTime;
}

void Game::Update()
{
  _calculateDeltaTime();

}

void Game::Render()
{

  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
  SDL_RenderClear(Renderer);
  SDL_RenderCopy(Renderer, TextureManager::GetTexture(tilesetTextureId), 0, 0);
  SDL_RenderPresent(Renderer);
}

void Game::DeInit()
{
  TextureManager::FreeAll();
  if (Renderer) { SDL_DestroyRenderer(Renderer); }
  if (Window) { SDL_DestroyWindow(Window); }
  SDL_Quit();
}
