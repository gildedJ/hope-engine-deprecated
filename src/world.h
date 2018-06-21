#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include "vector3.h"

#include <unordered_map>

namespace std {
  template<> struct hash<Vector3>
  {
    size_t operator()(const Vector3& key) const
    {
      return (key.X * 37) + (key.Y * 41) + (key.Z * 43);
    }
  };
}

#define CHUNK_ENTITY_PAGE_SIZE 32

struct EntityPage
{
  int Count;
  EntityId Entities[CHUNK_ENTITY_PAGE_SIZE];
  EntityPage *NextPage;
};

struct WorldChunk
{
  Vector3 Position;
  EntityPage FirstPage;
};

struct World
{
  World();
  ~World();

  std::unordered_map<Vector3, WorldChunk*> ChunkMap;

  WorldChunk *GetChunk(Vector3);
};




#endif