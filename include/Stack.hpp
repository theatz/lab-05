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
  Stack():_head(nullptr){};
  explicit Stack(const Stack& stack) = delete;
  Stack(Stack&& stack) = default;
  Stack& operator=(Stack&& stack) = default;

  ~Stack()
  {
    while (_head)
    {
      Node<T> *head = _head->prev;
      delete _head;
      _head = head;
    }
  };

  void push(T&& value)
  {
    _head = new Node<T> {value, _head};
  };

  void push(const T& value)
  {
    _head = new Node<T> {std::move(value), _head};
  };

  void pop()
  {
    if (_head)
    {
      Node<T> *tmp = _head->prev;
      delete _head;
      _head = tmp;
    } else
    {
      throw std::runtime_error("Empty stack");
    }
  }

  const T& head() const
  {
    if(!_head) throw std::runtime_error("Empty stack");
    return _head->data;
  };

 private:
  Node<T> *_head;
};

#endif  // TEMPLATE_STACK_HPP
