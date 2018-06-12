#ifndef POSITION_H
#define POSITION_H

#include "../component.h"
#include "../vector2.h"

struct PositionComponent : Component {
  Vector2 Position;
};

#endif