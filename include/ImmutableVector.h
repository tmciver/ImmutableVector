#include <cstddef>

template <class T>
class ImmutableVector {
 public:
  ImmutableVector(T *a_buf, size_t a_size);
  ~ImmutableVector();
  size_t size() const;
  T& operator[](size_t index) const;
 private:
  T *m_data;
  size_t m_size;
};
