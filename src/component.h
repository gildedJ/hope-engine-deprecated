#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

enum ComponentType 
{
  Position = 0,
  Movement,
  BoxCollider,
  Sprite,
  SpriteAnimation,
  Health,
  COMPONENT_COUNT
};

struct Component 
{
  Component(ComponentType type) : Type(type), EntityId(0) {}

  EntityId EntityId;
  ComponentType Type;
};


#endif