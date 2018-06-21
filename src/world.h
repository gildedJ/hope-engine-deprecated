#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include "vector3.h"

#include <unordered_map>
#include <unordered_set>

namespace std
{
template <typename T>
struct hash<Vector3<T>>
{
  size_t operator()(const Vector3<T> &key) const
  {
    return (key.X * 37) + (key.Y * 41) + (key.Z * 43);
  }
};
} // namespace std

typedef std::unordered_set<EntityId> EntityList;
typedef EntityList::iterator EntityListIterator;

struct WorldChunk
{
  Vector3<int> Position;
  EntityList Entities;

  void RemoveEntity(EntityId);
  void AddEntity(EntityId);
};

typedef std::unordered_map<Vector3<int>, WorldChunk *> WorldChunkMap;
typedef WorldChunkMap::iterator WorldChunkMapIterator;

struct World
{
  World();
  ~World();

  WorldChunkMap ChunkMap;

  WorldChunk *GetChunk(Vector3<int>);
};

void MoveEntity(EntityId id, WorldChunk *from, WorldChunk *to);

#endif