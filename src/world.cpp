#include "world.h"
#include <memory>

#define WORLD_CHUNK_HASHMAP_SIZE 1024

World::World()
{ 
}

World::~World()
{
}

static int _hash(int x, int y, int z)
{
  return (z << 16) + (y << 8) + x;
}

WorldChunk *World::GetChunk(int x, int y, int z)
{
  int index = _hash(x, y, z);
  WorldChunk *result = ChunkMap[index];
  
}