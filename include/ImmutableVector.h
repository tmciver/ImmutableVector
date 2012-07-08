#pragma once

#include <cstddef>
#include <stdexcept>

template <class T>
class ImmutableVector {
  class IVData;
  IVData *m_data;

 public:
  ImmutableVector(T *a_buf, size_t a_size);
  ImmutableVector(const ImmutableVector<T>& iv);
  ~ImmutableVector();
  size_t size() const;
  const T* data() const;
  const T& operator[](size_t index) const;
};

template<class T>
ImmutableVector<T>::ImmutableVector(T *a_buf, size_t a_size) {
  m_data = new IVData(a_buf, a_size);
}

template<class T>
ImmutableVector<T>::ImmutableVector(const ImmutableVector<T>& iv) {
  m_data = iv.m_data;
  ++m_data->refs;
}

template<class T>
ImmutableVector<T>::~ImmutableVector() {
  if (--m_data->refs == 0) {
    delete m_data;
  }
}

template<class T>
size_t ImmutableVector<T>::size() const {
  return m_data->m_size;
}

template<class T>
const T* ImmutableVector<T>::data() const {
  return m_data->m_data;
}

template<class T>
const T& ImmutableVector<T>::operator[](size_t index) const {
  if (index >= m_data->m_size) {
    throw std::out_of_range("Invalid index.");
  }
  return m_data->m_data[index];
}

// IVData class exists to implement data sharing between copies of ImmutableVectors
template<class T>
class ImmutableVector<T>::IVData {
 public:
  T *m_data;
  size_t m_size;
  size_t refs;      // ref count

 IVData(const T *a_data, size_t a_size) : m_size(a_size), refs(1) {
    m_data = new T[m_size];
    for (int i = 0; i < m_size; ++i) {
      m_data[i] = a_data[i];
    }
  }

  ~IVData() {
    delete[] m_data;
  }
};

