// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <iostream>

template<typename T, int kSize>
class TStack {
 private:
  T arr[kSize];
  int top;
 public:
  TStack(): top(-1) {}
  int getSize() const { return top + 1; }
  void push(T x) {
    if (top + 1 >= kSize) std::cout << "Out of size" << std::endl;
    else arr[++top] = x;
  }
  T pop() {
    if (top != -1) return arr[top--];
    else return T();
  }
  T getValue() const {
    if (top != -1) return arr[top];
    else return T();
  }
};
#endif //INCLUDE_TSTACK_H_
