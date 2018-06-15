#ifndef ENTITY_H
#define ENTITY_H

typedef int EntityId;

#include "component.h"

struct Entity
{
  EntityId Id;
  Component *Components[ComponentType::COMPONENT_COUNT];

  bool HasComponent(ComponentType);
  Component *GetComponent(ComponentType);
};

#define MAX_ENTITIES 1024

struct EntityManager
{
  int NumEntities;
  Entity Entities[MAX_ENTITIES];
};

#endif