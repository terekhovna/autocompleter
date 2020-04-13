#ifndef PROG__WORD_STORAGE_H_
#define PROG__WORD_STORAGE_H_

#include <string>
#include <map>
#include <algorithm>

namespace autocompleter {

class WordStorage {
 public:
  WordStorage();

  void AddWord(const std::string& word);

  std::string GetHint(const std::string &word);

  ~WordStorage();

 private:
  struct Node {
    Node(Node* parent, char c);

    std::map<char, Node*> children;
    Node* parent;
    char char_to_parent;
    size_t number_of_income;

    ~Node();
  };

  std::pair<Node*, size_t> GetHintNode(Node* node);
  std::string GetString(Node* node);

  Node* GetNode(const std::string& s);
  Node* root;
};

}

#endif //PROG__WORD_STORAGE_H_
