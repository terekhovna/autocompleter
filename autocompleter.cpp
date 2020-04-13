//
// Created by yaz-r on 13.04.2020.
//

#include "autocompleter.h"
#include "stdexcept"

autocompleter::Autocompleter::Autocompleter()
    : have_word_{ false },
      current_record_{word_storage_.GetRecord("")} {
}

void autocompleter::Autocompleter::Start() {
  while (true) {
    UserConsole::Request request = std::move(user_console_.GetRequest());
    switch (request.GetType()) {
      case UserConsole::Request::RequestType::AddText:
        AddText(std::move(request.GetString()));
        break;
      case UserConsole::Request::RequestType::AddLetters:
        AddLetters(std::move(request.GetString()));
        break;
      case UserConsole::Request::RequestType::Request:
        ProcessWord(std::move(request.GetString()));
        break;
    }
  }
}

bool IsLetter(char symbol) {
  return (symbol >= 'a' && symbol <= 'z')
    || (symbol >= 'A' && symbol <= 'Z');
}

char ToLower(char symbol) {
  if ('A' <= symbol && symbol <= 'Z') {
    return symbol - 'A' + 'a';
  }
  else {
    return symbol;
  }
}

void autocompleter::Autocompleter::AddText(const std::string &text) {
  std::string current_word;
  for(auto c : text) {
    if (IsLetter(c)) {
      current_word.push_back(ToLower(c));
    }
    else {
      word_storage_.AddWord(current_word);
      current_word.clear();
    }
  }
}

void autocompleter::Autocompleter::AddLetters(const std::string &letters) {
  if (!have_word_) {
    throw std::logic_error("you doesn't write word");
  }
  current_record_.AddLetters(letters);
  user_console_.WriteHint(current_record_.GetHint());
}

void autocompleter::Autocompleter::ProcessWord(const std::string &word) {
  current_record_ = word_storage_.GetRecord(word);
  have_word_ = true;
  user_console_.WriteHint(current_record_.GetHint());
}