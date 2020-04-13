#ifndef PROG__AUTOCOMPLETER_H_
#define PROG__AUTOCOMPLETER_H_

#include <string>
#include "word_storage.h"
#include "user_console.h"

namespace autocompleter {

class Autocompleter {
 public:
  Autocompleter();
  void Start();
 private:
  void AddText(const std::string &text);
  void ProcessWord(const std::string &word);
  void AddLetters(const std::string &letters);
  bool have_word_;
  WordStorage word_storage_;
  std::string current_request_;
  UserConsole user_console_;
};

}

#endif //PROG__AUTOCOMPLETER_H_
