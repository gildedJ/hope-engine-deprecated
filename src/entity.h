#ifndef ENTITY_H
#define ENTITY_H

typedef int EntityId;

#include "component.h"

struct Entity
{
  EntityId Id;
  Component *Components[ComponentType::COMPONENT_COUNT];
  int ComponentOwnership;

  bool HasComponent(ComponentType);
  Component *GetComponent(ComponentType);
  void AddComponent(Component *);
  void RemoveComponent(ComponentType type);
};

#define MAX_ENTITIES 1024

struct EntityManager
{
  int NumEntities;
  Entity Entities[MAX_ENTITIES];

  void AddComponent(EntityId, Component *);
  void RemoveComponent(EntityId, ComponentType);
  Entity *GetEntity(EntityId);
  EntityId CreateEntity();
};

#endif