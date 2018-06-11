#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

typedef uint32_t TextureId;

namespace TextureManager {
  const TextureId LoadTexture(const char *filename, SDL_Renderer *renderer);
  SDL_Texture *GetTexture(const TextureId id);
  void FreeTexture(const TextureId id);
  void FreeAll();
}

#endif