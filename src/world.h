#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include <unordered_map>

#define CHUNK_ENTITY_PAGE_SIZE 32

struct EntityPage
{
  int Count;
  EntityId Entities[CHUNK_ENTITY_PAGE_SIZE];
  EntityPage *NextPage;
};

struct WorldChunk
{
  int X, Y, Z;
  EntityPage FirstPage;
};

struct World
{
  World();
  ~World();

  std::unordered_map<int, WorldChunk*> ChunkMap;

  WorldChunk *GetChunk(int, int, int);
};



#endif