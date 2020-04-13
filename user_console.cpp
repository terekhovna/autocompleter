#include "user_console.h"
#include <iostream>

autocompleter::UserConsole::UserConsole() {
}

autocompleter::UserConsole::Request::Request(autocompleter::UserConsole::Request::RequestType request_type,
                                             std::string request_string)
    : type_{request_type}, string_{std::move(request_string)}
{
}

autocompleter::UserConsole::Request::RequestType
autocompleter::UserConsole::Request::GetType() const {
  return type_;
}

std::string& autocompleter::UserConsole::Request::GetString() {
  return string_;
}

autocompleter::UserConsole::Request
autocompleter::UserConsole::GetRequest() {
  std::cout << "write request(word - write word, "
      << "text - write text, letters - add letters)" << std::endl;
  autocompleter::UserConsole::Request::RequestType request_type;

  bool have_right_input = false;
  while(!have_right_input) {
    std::string s;
    std::cin >> s;
    if (s == "word") {
      request_type = autocompleter::UserConsole::Request::RequestType::Request;
      std::cout << "write word" << std::endl;
      have_right_input = true;
    }
    else if(s == "letters") {
      request_type = autocompleter::UserConsole::Request::RequestType::AddLetters;
      std::cout << "write letters" << std::endl;
      have_right_input = true;
    }
    else if(s == "text") {
      request_type = autocompleter::UserConsole::Request::RequestType::AddText;
      std::cout << "write text(only one line)" << std::endl;
      have_right_input = true;
    }
    else {
      std::cout << "please repeat" << std::endl;
    }
  }
  std::string request_string;
  if (request_type != autocompleter::UserConsole::Request::RequestType::AddText) {
    std::cin >> request_string;
  }
  else {
    while (request_string.empty()) {
      std::getline(std::cin, request_string);
    }
  }
  return std::move(Request(request_type, request_string));
}

void autocompleter::UserConsole::WriteHint(const std::string &s) {
  std::cout << "Your Hint: " << s << std::endl;
}