#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

enum ComponentType {
  Position = 0,
  Velocity,
  Acceleration,
  BoxCollider,
  COMPONENT_COUNT
};

struct Component {
  EntityId EntityId;
  ComponentType Type;
};

#endif