#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "../component.h"
#include "../vector2.h"

struct BoxCollider : Component 
{
  BoxCollider() : Component(ComponentType::BoxCollider) {}

  Vector2 Position; // relative to entity position
  Vector2 Size;     // width / height
};

#endif