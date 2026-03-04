#include <iostream>
#include <stdexcept>
template<class T>
T* merge2(const T* a, size_t sa, const T* b, size_t sb, T* c)
{
  if ((!a && sa != 0) || (!b && sb != 0) || (!c && (sa+sb)!=0))
    throw std::invalid_argument("Null pointer");

  size_t i = 0, j = 0, k = 0;

  while (i < sa && j < sb)
  {
    if (a[i] <= b[j])
      c[k++] = a[i++];
    else
      c[k++] = b[j++];
  }

  while (i < sa)
    c[k++] = a[i++];

  while (j < sb)
    c[k++] = b[j++];

  return c;
}

int main()
{
  size_t sa = 3, sb = 3;
  
  int* a = new int[sa]{1, 3, 5};
  int* b = new int[sb]{2, 4, 6};
  int* c = new int[sa + sb];

  merge2(a, sa, b, sb, c);

  std::cout << "Merged array: ";
  for (size_t i = 0; i < sa + sb; ++i)
    std::cout << c[i] << " ";
  std::cout << std::endl;

  delete[] a;
  delete[] b;
  delete[] c;

  return 0;
}