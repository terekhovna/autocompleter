#ifndef PROG__WORD_STORAGE_H_
#define PROG__WORD_STORAGE_H_

#include <string>
#include <map>

namespace autocompleter {

class WordStorage {
 public:
  struct Node {
    std::map<char, Node*> children;
    Node* parent;
    char char_to_parent;
    size_t number_of_income;
    Node* most_frequent;
    std::string GetString();
  };
  class Record {
   public:
    std::string GetHint() {
      if (!remain_part_.empty()) {
        return "doesn't have hint";
      }
      else {
        return node_.most_frequent->GetString();
      }
    }
    void AddLetters(const std::string &s) {
      if (!remain_part_.empty()) {

      }
    }
    Record();
   private:
    std::string remain_part_;
    WordStorage::Node node_;
  };

  void AddWord(const std::string& s) {

  }
  Record GetRecord(const std::string &s);

  };
 private:
  Node* node;
};

}

#endif //PROG__WORD_STORAGE_H_
