#include "ImmutableVector.h"

#include <cstddef>

template<class T>
ImmutableVector<T>::ImmutableVector(T *a_buf, size_t a_size) {
  m_data = new T[a_size];
  m_size = a_size;
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
const T& ImmutableVector<T>::operator[](size_t index) const {
  return m_data[index];
}
