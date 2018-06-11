#include "textureManager.h"

#include "SDL_image.h"

static TextureId _NextId = 0;
static SDL_Texture* Textures[32];

const TextureId TextureManager::LoadTexture(const char *filename, SDL_Renderer *renderer)
{
  SDL_Surface *tmpSurface = IMG_Load(filename);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  Textures[_NextId] = texture;
  return _NextId++;
}

SDL_Texture* TextureManager::GetTexture(const TextureId id)
{
  return Textures[id];
}

void TextureManager::FreeTexture(const TextureId id)
{
  SDL_Texture *texture = TextureManager::GetTexture(id);
  if (texture != NULL)
  {
    SDL_DestroyTexture(texture);
    Textures[id] = NULL;
  }
}

void TextureManager::FreeAll()
{
  while (_NextId > 0) TextureManager::FreeTexture(--_NextId);
}