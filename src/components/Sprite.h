#ifndef SPRITE_H
#define SPRITE_H

#include "../component.h"
#include "../vector2.h"
#include "../textureManager.h"

struct Sprite : Component
{
  Sprite() : Component(ComponentType::Sprite) {}

  TextureId Texture;
  Vector2<float> Offset;  // from position
  Vector2<float> TopLeft; // position IN Texture
  Vector2<float> Size;
};

#endif