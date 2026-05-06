#include <cmath>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::string> translate(std::vector<std::string> &s) {
  std::vector<std::string> result;
  std::stack<std::string> op_stack;
  std::unordered_map<std::string, int> precedence = {
      {"*", 1}, {"/", 1}, {"+", 0}, {"-", 0}, {"(", -1}};
  for (auto element : s) {
    if (element == "(")
      op_stack.push(element);
    else if (element == ")") {
      while (!op_stack.empty() && op_stack.top() != "(") {
        result.push_back(op_stack.top());
        op_stack.pop();
      }
      op_stack.pop();
    } else if (precedence.find(element) == precedence.end()) {
      result.push_back(element);
    } else {
      if (op_stack.empty())
        op_stack.push(element);
      else if (precedence[element] > precedence[op_stack.top()])
        op_stack.push(element);
      else if (precedence[element] <= precedence[op_stack.top()]) {
        result.push_back(op_stack.top());
        op_stack.pop();
        op_stack.push(element);
      }
    }
  }
  if (!op_stack.empty()) {
    while (op_stack.size()) {
      result.push_back(op_stack.top());
      op_stack.pop();
    }
  }
  return result;
}
int string_to_int(std::string s) {
  if (s[0] != '-') {
    int result = 0;
    int j = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      result += (s[i] - '0') * (std::pow(10, j++));
    }
    return result;
  }
  else {
    int result = 0;
    int j = 0;
    for (int i = s.size() - 1; i >= 1; i--) {
      result += (s[i] - '0') * (std::pow(10, j++));
    }
    return -1 * result;
  }
}
std::vector<std::string> tokenizer(std::string s) {
  std::vector<std::string> tokens;
  std::unordered_set<char> op = {'+', '-', '*', '/', '(', ')'};
  for (int i = 0; i < s.size(); i++) {
    if (op.find(s[i]) != op.end()) {
      tokens.push_back(std::string(1, s[i]));
    } else {
      if (isdigit(s[i])) {
        std::string number = std::string(1, s[i]);
        int j = i + 1;
        while (isdigit(s[j]) && j < s.size()) {
          number += s[j];
          i = j;
          j++;
        }
        tokens.push_back(number);
      } else {
        continue;
      }
    }
  }
  return tokens;
}

int postfix_parser(std::vector<std::string> tokens) {
  std::stack<std::string> my_stack;
  for (auto element : tokens) {
    if (element == "+") {
      int op_1 = string_to_int(my_stack.top());
      my_stack.pop();
      int op_2 = string_to_int(my_stack.top());
      my_stack.pop();
      my_stack.push(std::to_string(op_1 + op_2));
    } else if (element == "*") {
      int op_1 = string_to_int(my_stack.top());
      my_stack.pop();
      int op_2 = string_to_int(my_stack.top());
      my_stack.pop();
      my_stack.push(std::to_string(op_1 * op_2));
    } else if (element == "/") {
      int op_1 = string_to_int(my_stack.top());
      my_stack.pop();
      int op_2 = string_to_int(my_stack.top());
      my_stack.pop();
      my_stack.push(std::to_string(op_2 / op_1));
    } else if (element == "-") {
      int op_1 = string_to_int(my_stack.top());
      my_stack.pop();
      int op_2 = string_to_int(my_stack.top());
      my_stack.pop();
      my_stack.push(std::to_string(op_2 - op_1));
    } else {
      my_stack.push(element);
    }
  }
  return string_to_int(my_stack.top());
}
void output_result(std::vector<std::string> &lst) {
  std::cout << "[";
  for (auto element : lst) {
    std::cout << " " << element;
  }
  std::cout << "]" << std::endl;
}
int main() {
  bool ex = true;
  while (ex) {
    std::string s;
    std::cout << ">> " ;
    std::cin >> s;
    std::vector<std::string> tokens = tokenizer(s);
    // output the tokenizer result ;
    std::cout << "tokenizer = ";
    output_result(tokens);
    std::vector<std::string> postfix_notation = translate(tokens);
    // output the translator result ;
    std::cout << "translator = ";
    output_result(postfix_notation);
    int result = postfix_parser(postfix_notation);
    std::cout << "result = " << result << std::endl;
  }
  return 0;
}
