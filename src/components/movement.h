#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../component.h"
#include "../vector2.h"

struct Movement : Component
{
  Movement() : Component(ComponentType::Movement) {}

  Vector2<float> Velocity;
  Vector2<float> Acceleration;
};

#endif