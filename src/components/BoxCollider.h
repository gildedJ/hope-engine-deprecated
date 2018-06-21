#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "../component.h"
#include "../vector2.h"

struct BoxCollider : Component
{
  BoxCollider() : Component(ComponentType::BoxCollider) {}

  Vector2<float> Position; // relative to entity position
  Vector2<float> Size;     // width / height
};

#endif