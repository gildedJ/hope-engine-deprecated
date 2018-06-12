#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2 
{
  float X, Y;
};

Vector2 operator+(Vector2 a, Vector2 b)
{
  Vector2 result = { a.X + b.X, a.Y + b.Y };
  return result;
}

Vector2 operator*(float c, Vector2 v)
{
  Vector2 result = {c * v.X, c * v.Y};
  return result;
}

Vector2 operator*(Vector2 v, float c)
{
  return operator*(c,v);
}

Vector2 operator-(Vector2 v)
{
  Vector2 result = {-v.X, -v.Y};
  return result;
}

Vector2 operator-(Vector2 a, Vector2 b)
{
  Vector2 result = {a.X - b.X, a.Y - b.Y};
  return result;
}

#endif