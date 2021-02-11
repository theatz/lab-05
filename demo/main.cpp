//
// Created by mrbgn on 2/11/21.
//

#include <Stack.hpp>
#include <NoCopyStack.hpp>
template <typename T>
struct Struct
{
  Struct(T d1, T d2, T d3) : data1(d1), data2(d2), data3(d3){};
  explicit Struct(const Struct& stack) = delete;
  Struct(Struct&& stack) noexcept = default;
  auto operator=(Struct&& stack) noexcept -> Struct& = default;
  T data1;
  T data2;
  T data3;
};

int main() {
//  NoCopyableStack<Struct<int>> a;
//  Struct<int> test_struct (1, 2, 3);
//
//  a.push(std::move(test_struct));
//  a.push_emplace(4, 5, 6);
//  const Struct<int>& test_struct2 = a.head();
//
//  std::cout << test_struct2.data2<<std::endl;
  return 0;

}