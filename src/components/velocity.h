#ifndef VELOCITY_H
#define VELOCITY_H

#include "../component.h"
#include "../vector2.h"

struct VelocityComponent : Component {
  Vector2 Velocity;
};

#endif