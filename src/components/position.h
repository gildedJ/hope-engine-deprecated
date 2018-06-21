#ifndef POSITION_H
#define POSITION_H

#include "../component.h"
#include "../vector2.h"
#include "../vector3.h"

struct Position : Component
{
  Position() : Component(ComponentType::Position) {}

  Vector2<float> ChunkPosition;
  Vector3<int> WorldPosition;
};

#endif