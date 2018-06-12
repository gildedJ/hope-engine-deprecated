#ifndef HEALTH_H
#define HEALTH_H

#include "../component.h"

struct Health : Component 
{
  Health() : Component(ComponentType::Health) {}
  
  int Current;
  int Max;
  int Temp;
};

#endif