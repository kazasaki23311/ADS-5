#include <iostream>

template<typename T, int lenOfArr>
class TStack {
 private:
  T arr[lenOfArr];
  int top;
 public:
  TStack(): top(-1) {}
  int getSize() const { return top + 1; }
  void push(T x) {
    if (top + 1 >= lenOfArr) std::cout << "Out of size" << std::endl;
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
