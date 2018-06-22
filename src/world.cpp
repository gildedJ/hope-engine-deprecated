#include "world.h"

void WorldChunk::RemoveEntity(EntityId id)
{
  EntityListIterator it = Entities.find(id);
  if (it != Entities.end())
  {
    Entities.erase(it);
  }
}

void WorldChunk::AddEntity(EntityId id)
{
  Entities.insert(id);
}

void MoveEntity(EntityId id, WorldChunk *from, WorldChunk *to)
{
  from->RemoveEntity(id);
  to->AddEntity(id);
}

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