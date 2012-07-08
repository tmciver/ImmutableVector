#pragma once

#include <cstddef>
#include <stdexcept>

#include <iostream>

template <class T>
class ImmutableVector {
  T *m_data;
  size_t m_size;

 public:
  ImmutableVector(T *a_buf, size_t a_size);
  ImmutableVector(const ImmutableVector<T>& iv);
  ~ImmutableVector();
  size_t size() const;
  const T* data() const;
  const T& operator[](size_t index) const;
};

template<class T>
ImmutableVector<T>::ImmutableVector(T *a_buf, size_t a_size) : m_size(a_size) {
  m_data = new T[a_size];
  for (int i = 0; i < a_size; ++i) {
    m_data[i] = a_buf[i];
  }
}

template<class T>
ImmutableVector<T>::ImmutableVector(const ImmutableVector<T>& iv) {
  //std::cout << "In copy constructor." << std::endl;
  m_size = iv.m_size;
  m_data = new T[m_size];
  for (int i = 0; i < m_size; ++i) {
    m_data[i] = iv.m_data[i];
  }
}

template<class T>
ImmutableVector<T>::~ImmutableVector() {
  delete [] m_data;
}

template<class T>
size_t ImmutableVector<T>::size() const {
  return m_size;
}

template<class T>
const T* ImmutableVector<T>::data() const {
  return m_data;
}

template<class T>
const T& ImmutableVector<T>::operator[](size_t index) const {
  if (index >= m_size) {
    throw std::out_of_range("Invalid index.");
  }
  return m_data[index];
}
