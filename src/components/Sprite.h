#ifndef SPRITE_H
#define SPRITE_H

#include "../component.h"
#include "../vector2.h"
#include "../textureManager.h"

struct Sprite : Component 
{
  Sprite() : Component(ComponentType::Sprite) {}
  
  TextureId Texture;
  Vector2 Offset;     // from position
  Vector2 TopLeft;    // position IN Texture
  Vector2 Size;
};

#endif