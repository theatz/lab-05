//
// Created by mrbgn on 2/11/21.
//

#include "Stack.hpp"
#include <iostream>
#include <type_traits>

#ifndef TEMPLATE_NOCOPYSTACK_HPP
#define TEMPLATE_NOCOPYSTACK_HPP

template <typename T>
class NoCopyStack {
 public:
  NoCopyStack() : _head(nullptr)
  {
    if (!(std::is_move_constructible<T>::value ||
        std::is_move_assignable<T>::value))
      throw std::runtime_error("Error stack");
  }

  explicit NoCopyStack(const NoCopyStack& stack) = delete;
  NoCopyStack& operator=(const NoCopyStack& stack) = delete;
  NoCopyStack& operator=(const NoCopyStack&& stack) noexcept
  {
    if (_head) _head = new Node<T>{std::move(stack), std::move(_head)};
    else _head = new Node<T>{std::move(stack), nullptr};

  }
  NoCopyStack(NoCopyStack&& stack) = default;

  void push_emplace()
  {
    return;
  }

  template <typename Arg, typename... Args>
  void push_emplace(Arg&& value,Args&&... values);

  void push(T&& value)
  {
    _head = new Node<T>{std::move(value), std::move(_head)};
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

template <typename T>
template <typename Arg, typename... Args>
void NoCopyStack<T>::push_emplace(Arg&& value,Args&&... values)
{
  push(std::move(value));
  push_emplace(std::forward<Args>(values)...);
  //if (values...) push_emplace(std::forward<Args>(values)...);
    //_head = new Node<T>{{std::forward<Args>(value)...}, _head};

}
#endif  // TEMPLATE_NOCOPYSTACK_HPP
