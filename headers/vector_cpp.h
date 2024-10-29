#ifndef VECTOR_CPP_H
#define VECTOR_CPP_H

#include <gtest/gtest.h>
#include <initializer_list>
#include <iostream>

template <typename T> class Vector {
private:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  iterator vector;
  size_type size_vector;
  size_type capacity_vector;

public:
  Vector();
  Vector(std::initializer_list<value_type> list);
  Vector(size_type n);
  Vector(size_type n, value_type value);
  ~Vector();

  size_type size() const;
  size_type capacity() const;
  reference at(size_type i);
};

template <typename T>
Vector<T>::Vector() : vector(nullptr), size_vector(0), capacity_vector(0) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> list) {
  size_vector = list.size();
  capacity_vector = list.size();
  vector = new value_type[size_vector];
  size_type i = 0;
  for (auto &elem : list) {
    vector[i++] = elem;
  }
}

template <typename T> Vector<T>::Vector(size_type n) {
  size_vector = n;
  capacity_vector = n;
  vector = new value_type[size_vector];
}

template <typename T> Vector<T>::Vector(size_type n, value_type value) {
  size_vector = n;
  capacity_vector = n;
  vector = new value_type[size_vector];
  for (size_type i = 0; i < size_vector; i++) {
    vector[i] = value;
  }
}

template <typename T> Vector<T>::~Vector() { delete[] vector; }

template <typename T> typename Vector<T>::size_type Vector<T>::size() const {
  return size_vector;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::capacity() const {
  return capacity_vector;
}

template <typename T> typename Vector<T>::reference Vector<T>::at(size_type i) {
  return vector[i];
}

#endif
