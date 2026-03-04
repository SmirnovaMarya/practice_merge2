#include <iostream>
#include <stdexcept>

template<class T>
T* merge2(const T* a, size_t sa, const T* b, size_t sb, T* c) // T: должен иметь конструктор по умолчанию
{
  if ((!a && sa != 0) || (!b && sb != 0) || (!c && (sa+sb)!=0)) // T: должен поддерживать оператор сравнения <=
    throw std::invalid_argument("Null pointer");

  size_t i = 0, j = 0, k = 0;

  while (i < sa && j < sb)
  {
    if (a[i] <= b[j]) // T: нужен оператор <=
      c[k++] = a[i++]; // T: должен поддерживать присваивание и копирование
    else
      c[k++] = b[j++]; // T: должен поддерживать присваивание и копирование
  }

  while (i < sa)
    c[k++] = a[i++]; // T: должен поддерживать присваивание и копирование

  while (j < sb)
    c[k++] = b[j++]; // T: должен поддерживать присваивание и копирование

  return c;
}

int main()
{
  size_t sa = 3, sb = 3;

  int* a = new int[sa]{1, 3, 5};
  int* b = new int[sb]{2, 4, 6};
  int* c = new int[sa + sb]; // T: нужен конструктор по умолчанию

  std::cout << "1 массив: ";
  for (size_t i = 0; i < sa; ++i)
    std::cout << a[i] << " ";
  std::cout << std::endl;

  std::cout << "2 массив: ";
  for (size_t i = 0; i < sb; ++i)
    std::cout << b[i] << " ";
  std::cout << std::endl << std::endl;

  merge2(a, sa, b, sb, c);
  std::cout << "Отсортированный массив: ";
  for (size_t i = 0; i < sa + sb; ++i)
    std::cout << c[i] << " ";
  std::cout << std::endl;

  delete[] a; // T: должен иметь деструктор
  delete[] b; // T: должен иметь деструктор
  delete[] c; // T: должен иметь деструктор
  std::cout << std::endl;

  return 0;
}
/* Требования к неявному интерфейсу шаблона:
  1)Нулевая длина массива допустима, но если передать nullptr с ненулевой длиной будет выброс исключения
  2)При неотсортированных входных массиваз функция всё равно сработает, но результат не будет отсортированным
  3)Функция не создаёт новый массив сама — массив c должен быть уже выделен */
