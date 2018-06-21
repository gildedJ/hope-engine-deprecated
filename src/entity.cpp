#include "entity.h"
#include <cassert>

Entity::Entity()
    : Id(0), ComponentOwnership(0) {}

Entity::Entity(EntityId id)
    : Id(id), ComponentOwnership(0) {}

bool Entity::HasComponent(ComponentType type)
{
  return (bool)(this->ComponentOwnership && (1 << type));
}

Component *Entity::GetComponent(ComponentType type)
{
  assert(HasComponent(type));
  return Components[type];
}

void Entity::AddComponent(Component *component)
{
  assert(!HasComponent(component->Type));
  ComponentOwnership |= (1 << component->Type);
  Components[component->Type] = component;
}

void Entity::RemoveComponent(ComponentType type)
{
  ComponentOwnership &= ~(1 << type);
}

EntityManager::EntityManager() : NumEntities(0), NextFree(nullptr) {}

void EntityManager::AddComponent(EntityId id, Component *component)
{
  Entities[id].AddComponent(component);
}

void EntityManager::RemoveComponent(EntityId id, ComponentType type)
{
  Entities[id].RemoveComponent(type);
}

Entity *EntityManager::GetEntity(EntityId id)
{
  return &Entities[id];
}

EntityId EntityManager::CreateEntity()
{
  if (NextFree == nullptr)
  {
    EntityId result = ++NumEntities;
    Entities[result].Id = result;
    return result;
  }
  else
  {
    EM_FreeSlot *nextEntity = NextFree;
    NextFree = nextEntity->Next;
    EntityId result = nextEntity->Id;
    delete nextEntity;

    Entities[result].Id = result;
    Entities[result].ComponentOwnership = 0;
    return result;
  }
}

void EntityManager::DestroyEntity(EntityId id)
{
  Entities[id].Id = 0;
  NumEntities--;

  EM_FreeSlot *newFree = new EM_FreeSlot;
  newFree->Id = id;
  newFree->Next = NextFree;
  NextFree = newFree;
}