#include "textureManager.h"

#include "SDL_image.h"

#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, TextureId> TextureStore;
typedef TextureStore::iterator TextureStoreIterator;

#define MAX_TEXTURES 32

static TextureId _NextId = 0;
static SDL_Texture *Textures[MAX_TEXTURES];
static TextureStore FilenameToId;

const TextureId TextureManager::LoadTexture(const char *filename, SDL_Renderer *renderer)
{
  TextureStoreIterator it = FilenameToId.find(filename);
  if (it == FilenameToId.end() || Textures[it->second] == NULL)
  {
    SDL_Surface *tmpSurface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    Textures[_NextId] = texture;
    FilenameToId[filename] = _NextId;
    return _NextId++;
  }
  else
  {
    return it->second;
  }
}

SDL_Texture *TextureManager::GetTexture(const TextureId id)
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
  while (_NextId > 0)
    TextureManager::FreeTexture(--_NextId);
}