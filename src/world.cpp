#include "world.h"

#include <memory>

#define WORLD_CHUNK_HASHMAP_SIZE 1024

World::World()
{
}

World::~World()
{
}

WorldChunk *World::GetChunk(Vector3<int> position)
{
  WorldChunk *result = nullptr;
  WorldChunkMapIterator it = ChunkMap.find(position);
  if (it != ChunkMap.end())
  {
    result = it->second;
  }
  else
  {
    result = new WorldChunk();
    result->Position = position;
    ChunkMap[position] = result;
  }
  return result;
}