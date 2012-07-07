#pragma once

#include <cstddef>
#include <stdexcept>

template <class T>
class ImmutableVector {
  T *m_data;
  size_t m_size;

 public:
  ImmutableVector(T *a_buf, size_t a_size);
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
