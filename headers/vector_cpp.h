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
  Vector(Vector &);
  ~Vector();

  size_type size() const;
  size_type capacity() const;
  reference at(size_type i);
  Vector &operator=(Vector &);
  iterator begin();
  iterator end();
  void push_back(value_type);
  void reserve(size_type);
  iterator insert(iterator, value_type);
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

template <typename T> inline Vector<T>::Vector(Vector &other) {
  size_vector = other.size_vector;
  capacity_vector = other.capacity_vector;
  vector = new value_type[size_vector];
  for (size_type i = 0; i < size_vector; i++) {
    vector[i] = other.vector[i];
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

template <typename T> inline Vector<T> &Vector<T>::operator=(Vector &other) {
  if (this != &other) {
    delete[] vector;

    size_vector = other.size_vector;
    capacity_vector = other.capacity_vector;
    vector = new value_type[size_vector];
    for (size_type i = 0; i < size_vector; i++) {
      vector[i] = other.vector[i];
    }
  }
  return *this;
}

template <typename T> typename Vector<T>::iterator Vector<T>::begin() {
  return vector;
}

template <typename T> typename Vector<T>::iterator Vector<T>::end() {
  return vector + (size_vector - 1);
}

template <typename T> void Vector<T>::push_back(value_type value) {
  if (size_vector == capacity_vector) {
    size_type new_capacity = (size_vector == 0) ? 1 : (capacity_vector * 2);
    reserve(new_capacity);
  }
  vector[size_vector++] = value;
}

template <typename T> void Vector<T>::reserve(size_type new_capacity) {
  iterator new_vector = new value_type[new_capacity];
  for (size_type i = 0; i < size_vector; i++) {
    new_vector[i] = vector[i];
  }
  delete[] vector;
  vector = new_vector;
  capacity_vector = new_capacity;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos, value_type value) {
  if (size_vector == capacity_vector) {
    size_type new_capacity = (size_vector == 0) ? 1 : (capacity_vector * 2);
    reserve(new_capacity);
  }
  for (iterator it = this->end(); it != pos; it--) {
    *(it + 1) = *it;
  }
  *pos = value;
  return pos;
}

#endif
