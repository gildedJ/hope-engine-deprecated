#ifndef VECTOR2_H
#define VECTOR2_H

template <typename T>
struct Vector2
{
  T X, Y;
};

template <typename T>
Vector2<T> operator+(Vector2<T> a, Vector2<T> b)
{
  Vector2 result = {a.X + b.X, a.Y + b.Y};
  return result;
}

template <typename T>
Vector2<T> operator*(float c, Vector2<T> v)
{
  Vector2 result = {c * v.X, c * v.Y};
  return result;
}

template <typename T>
Vector2<T> operator*(Vector2<T> v, float c)
{
  return operator*(c, v);
}

template <typename T>
Vector2<T> operator-(Vector2<T> v)
{
  Vector2 result = {-v.X, -v.Y};
  return result;
}

template <typename T>
Vector2<T> operator-(Vector2<T> a, Vector2<T> b)
{
  Vector2 result = {a.X - b.X, a.Y - b.Y};
  return result;
}

template <typename T>
bool operator==(const Vector2<T> &lhs, const Vector2<T> &rhs)
{
  return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

#endif