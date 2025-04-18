#include <iostream>

// Part 2: Implementing Move Semantics
class Buffer
{
private:
  int *data;
  size_t size;

public:
  Buffer(size_t s) : size(s), data(new int[s])
  {
    std::cout << "Constructor called\n";
  }

  ~Buffer()
  {
    delete[] data;
    std::cout << "Destructor called\n";
  }

  // other.data = | 0x0000 | 0x0004 | 0x0008 | 0x000C | 0x0010 | 0x0011 |
  // int = 4 bytes
  // other.size = 5 * 4 int = 20 bytes
  // 0 1 2 3 4 5 6 7 8 9  A  B  C  D  E  F
  // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

  Buffer(const Buffer &other) : size(other.size), data(new int[other.size])
  {
    std::copy(other.data, other.data + other.size, data);
    std::cout << "Copy constructor called\n";
  }

  Buffer &operator=(const Buffer &other)
  {
    if (this != &other)
    {
      delete[] data;
      size = other.size;
      data = new int[size];
      std::copy(other.data, other.data + size, data);
      std::cout << "Copy assignment called\n";
    }
    return *this;
  }

  Buffer(Buffer &&other) noexcept : data(other.data), size(other.size)
  {
    other.data = nullptr;
    other.size = 0;
    std::cout << "Move constructor called\n";
  }

  Buffer &operator=(Buffer &&other) noexcept
  {
    if (this != &other)
    {
      delete[] data;
      data = other.data;
      size = other.size;

      other.data = nullptr;
      other.size = 0;
      std::cout << "Move assignment called\n";
    }
    return *this;
  }
};