#include "entity.h"
#include <cassert>

bool Entity::HasComponent(ComponentType type)
{
  return true;
}

Component *Entity::GetComponent(ComponentType type)
{
  assert(this->HasComponent(type));
  return Components[type];
}