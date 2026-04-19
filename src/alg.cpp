// Copyright 2025 NNTU-CS
#include "alg.h"
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
  std::string temp;
  int size = inf.length();
  TStack<char, 100> stack1;
  for (int i = 0; i < size; i++) {
    if (inf[i] >= '0' && inf[i] <= '9') {
      if (temp.length() > 0) temp += ' ';
      temp += inf[i];
    } else if (inf[i] == ')') {
      while (stack1.getSize() != 0 && stack1.getValue() != '(') {
        if (temp.length() > 0) temp += ' ';
        temp += stack1.pop();
      }
      if (stack1.getSize() != 0) {
        stack1.pop();
      }
    } else if (inf[i] == '(') {
      stack1.push(inf[i]);
    } else {
      int priority_n;
      switch (inf[i]) {
        case '*':
        case '/': priority_n = 3; break;
        case '+':
        case '-': priority_n = 2; break;
        default: priority_n = -1; break;
      }
      while (stack1.getSize() != 0 && stack1.getValue() != '(') {
        int priority_p;
        switch (stack1.getValue()) {
          case '*':
          case '/': priority_p = 3; break;
          case '+':
          case '-': priority_p = 2; break;
          default: priority_p = -1; break;
        }
        if (priority_n <= priority_p) {
          if (temp.length() > 0) temp += ' ';
          temp += stack1.pop();
        } else {
          break;
        }
      }
      stack1.push(inf[i]);
    }
  }
  while (stack1.getSize() != 0) {
    char op = stack1.pop();
    if (op != '(') {
      if (temp.length() > 0) temp += ' ';
      temp += op;
    }
  }
  return temp;
}

int eval(const std::string& pref) {
  TStack<int, 100> stack2;
  int i = 0;
  while (i < pref.length()) {
    if (pref[i] >= '0' && pref[i] <= '9') {
      int num = 0;
      while (i < pref.length() && pref[i] >= '0' && pref[i] <= '9') {
        num = num * 10 + (pref[i] - '0');
        i++;
      }
      stack2.push(num);
    }
    if (pref[i] == '+' || pref[i] == '-' || pref[i] == '*' || pref[i] == '/') {
      int b = stack2.pop(), a = stack2.pop();
      int result;
      switch (pref[i]) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
      }
      stack2.push(result);
    }
    i++;
  }
  return stack2.pop();
}
