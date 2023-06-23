#include <functional>
#include <iostream>
#include <unordered_map>

#include "checknumber.hpp"

int main()
{
  InputIllegalEvent input_illegal;
  InputNumberEvent input_number;
  InputExpEvent input_exp;
  InputPointEvent input_point;
  InputSignEvent input_sign;
  InputSpaceEvent input_space;

  while (1) {
    std::string input;

    std::cout << "Please enter a string: q= quit, r=reset or input a number"
              << std::endl;
    std::getline(std::cin, input);

    std::cout << "You entered: " << input << std::endl;

    if (input == "q") {
      break;
    }
    if (input == "r") {
      CheckNumber::reset();
      continue;
    }

    CheckNumber::start();

    for (const auto &c : input) {
      std::cout << "item " << c << std::endl;
      if (c >= '0' && c <= '9') {
        CheckNumber::dispatch(input_number);
      }
      else if (c == 'e' || c == 'E') {
        CheckNumber::dispatch(input_exp);
      }
      else if (c == '+' || c == '-') {
        CheckNumber::dispatch(input_sign);
      }
      else if (c == ' ') {
        CheckNumber::dispatch(input_space);
      }
      else if (c == '.') {
        CheckNumber::dispatch(input_point);
      }
      else {
        CheckNumber::dispatch(input_illegal);
        std::cout << "input illegal break" << std::endl;
      }
      // auto event = input_point;
      CheckNumber::current_state_ptr->get_state();
    }
    if (CheckNumber::current_state_ptr->get_state() == "STATE_ILLEGAL") {
      std::cout << "total number illegal found" << std::endl;
    }
  }
  return 1;
}
