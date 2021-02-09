//
// Created by mrbgn on 2/4/21.
//


#include <cstdlib>
#include <iostream>
#include <type_traits>
#ifndef TEMPLATE_STACK_HPP
#define TEMPLATE_STACK_HPP

template <typename T>
struct Node
{
  T data;
  Node *prev;
};

template <typename T>
class Stack
{
 public:
  Stack()
  {

  }
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;

 private:
  Node<T> *_head;
};


#endif  // TEMPLATE_STACK_HPP
