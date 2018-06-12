#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"

typedef int EntityId;

struct Entity 
{
  EntityId Id;
  Component *Components[ComponentType::COMPONENT_COUNT];
};

#define MAX_ENTITIES 1024

struct EntityManager
{
  int NumEntities;
  Entity Entities[MAX_ENTITIES];
};


#endif