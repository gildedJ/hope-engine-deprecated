#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3 
{
  float X, Y, Z;
};

Vector3 operator+(Vector3 a, Vector3 b)
{
  Vector3 result = { a.X + b.X, a.Y + b.Y, a.Z + b.Z };
  return result;
}

Vector3 operator*(float c, Vector3 v)
{
  Vector3 result = {c * v.X, c * v.Y, c * v.Z};
  return result;
}

Vector3 operator*(Vector3 v, float c)
{
  return operator*(c,v);
}

Vector3 operator-(Vector3 v)
{
  Vector3 result = {-v.X, -v.Y, -v.Z};
  return result;
}

Vector3 operator-(Vector3 a, Vector3 b)
{
  Vector3 result = {a.X - b.X, a.Y - b.Y, a.Z - b.Z};
  return result;
}

bool operator==(const Vector3 &lhs, const Vector3 &rhs)
{
  return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

#endif