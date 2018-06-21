#ifndef ENTITY_H
#define ENTITY_H

typedef int EntityId;

#include "component.h"

struct Entity
{
  Entity();
  Entity(EntityId);

  EntityId Id;
  Component *Components[ComponentType::COMPONENT_COUNT];
  int ComponentOwnership;

  bool HasComponent(ComponentType);
  Component *GetComponent(ComponentType);
  void AddComponent(Component *);
  void RemoveComponent(ComponentType type);
};

#define MAX_ENTITIES 2048

struct EM_FreeSlot
{
  EntityId Id;
  EM_FreeSlot *Next;
};

struct EntityManager
{
  EntityManager();

  int NumEntities;
  EM_FreeSlot *NextFree;
  Entity Entities[MAX_ENTITIES];

  void AddComponent(EntityId, Component *);
  void RemoveComponent(EntityId, ComponentType);
  Entity *GetEntity(EntityId);
  EntityId CreateEntity();
  void DestroyEntity(EntityId);
};

#endif