#ifndef VECTOR3_H
#define VECTOR3_H

template <typename T>
struct Vector3
{
  T X, Y, Z;
};

template <typename T>
Vector3<T> operator+(Vector3<T> a, Vector3<T> b)
{
  Vector3<T> result = {a.X + b.X, a.Y + b.Y, a.Z + b.Z};
  return result;
}

template <typename T>
Vector3<T> operator*(float c, Vector3<T> v)
{
  Vector3<T> result = {c * v.X, c * v.Y, c * v.Z};
  return result;
}

template <typename T>
Vector3<T> operator*(Vector3<T> v, float c)
{
  return operator*(c, v);
}

template <typename T>
Vector3<T> operator-(Vector3<T> v)
{
  Vector3<T> result = {-v.X, -v.Y, -v.Z};
  return result;
}

template <typename T>
Vector3<T> operator-(Vector3<T> a, Vector3<T> b)
{
  Vector3<T> result = {a.X - b.X, a.Y - b.Y, a.Z - b.Z};
  return result;
}

template <typename T>
bool operator==(const Vector3<T> &lhs, const Vector3<T> &rhs)
{
  return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

#endif