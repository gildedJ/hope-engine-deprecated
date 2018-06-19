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
  Player,  // Tag
  Enemy,   // Tag
  Neutral, // Tag
  LocalControlled,
  RemoteControlled,
  AIControlled,
  COMPONENT_COUNT
};

struct Component 
{
  Component(ComponentType type) : Type(type), Id(0) {}

  EntityId Id;
  ComponentType Type;
};


#endif