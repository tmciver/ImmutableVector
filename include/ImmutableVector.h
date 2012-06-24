#include <cstddef>

template <class T>
class ImmutableVector {
  T *m_data;
  size_t m_size;

 public:
  ImmutableVector(T *a_buf, size_t a_size);
  ~ImmutableVector();
  size_t size() const;
  const T& operator[](size_t index) const;
};
