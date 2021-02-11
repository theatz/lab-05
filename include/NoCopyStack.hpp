//
// Created by mrbgn on 2/11/21.
//

#include "Stack.hpp"
#include <cstdlib>
#include <iostream>
#include <type_traits>

#ifndef TEMPLATE_NOCOPYSTACK_HPP
#define TEMPLATE_NOCOPYSTACK_HPP

template <typename T>
class NoCopyStack {
 public:
  NoCopyStack() : _head(nullptr)
  {
    if (std::is_copy_constructible<T>::value ||
        std::is_copy_assignable<T>::value)
      throw std::runtime_error("Error stack");
  }

  explicit NoCopyStack(const NoCopyStack& stack) = delete;
  NoCopyStack& operator=(const NoCopyStack& stack) = delete;
  NoCopyStack(NoCopyStack&& stack) = default;

  template <typename ... Args>
  void push_emplace(Args&&... value)
  {
    _head = new Node<T>{{std::forward<Args>(value)...}, _head};
  }

  void push(T&& value)
  {
    _head = new Node<T>{std::move(value), _head};
  }
  const T& head() const
  {
    if (_head) return _head -> data;
    else throw std::runtime_error("Empty stack");
  }
  T pop()
  {
    if (_head)
    {
      Node<T> *buf = _head -> prev;
      T data = std::move(_head -> data);
      delete _head;
      _head = buf;
      return data;
    } else throw std::runtime_error("Empty stack");
  }
  ~NoCopyStack()
  {
    while (_head)
    {
      Node<T> *buf = _head -> prev;
      delete _head;
      _head = buf;
    }
  }
 private:
  Node<T> *_head;
};
#endif  // TEMPLATE_NOCOPYSTACK_HPP
