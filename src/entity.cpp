#include "entity.h"
#include <cassert>

bool Entity::HasComponent(ComponentType type)
{
  return (bool)(this->ComponentOwnership && (1 << type));
}

Component *Entity::GetComponent(ComponentType type)
{
  assert(this->HasComponent(type));
  return Components[type];
}

void Entity::AddComponent(Component *component)
{
  assert(!this->HasComponent(component->Type));
  this->ComponentOwnership |= (1 << component->Type);
  this->Components[component->Type] = component;
}

void Entity::RemoveComponent(ComponentType type)
{
  this->ComponentOwnership &= ~(1 << type);
}