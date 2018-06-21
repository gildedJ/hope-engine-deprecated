#include "world.h"

#include <memory>

#define WORLD_CHUNK_HASHMAP_SIZE 1024

World::World()
{ 
}

World::~World()
{
}

WorldChunk *World::GetChunk(Vector3 position)
{
  WorldChunk *result = ChunkMap[position];
  if (result == nullptr)
  {
    result = new WorldChunk();
    result->Position = position;
    ChunkMap[position] = result;
  }
  return result;
}