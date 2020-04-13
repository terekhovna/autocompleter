#ifndef PROG__WORD_STORAGE_H_
#define PROG__WORD_STORAGE_H_

#include <string>
#include <map>
#include <algorithm>

namespace autocompleter {

class WordStorage {
 public:
  WordStorage() {
    root = new Node(nullptr, '\0');
  }
  void AddWord(const std::string& s) {
    Node* current_node = root;
    for(char c : s) {
      if (current_node->children[c] == nullptr) {
        Node* node = new Node(current_node, c);
        current_node->children[c] = node;
      }
      current_node = current_node->children[c];
    }
    ++current_node->number_of_income;
  }
  std::string GetHint(const std::string &s) {
    Node* node = GetNode(s);
    if(node == nullptr) {
      return "i don't have hint for this string";
    }
    auto hint_result = GetHintNode(node);
    return GetString(hint_result.first);
  }
  ~WordStorage() {
    delete root;
  }
 private:
  struct Node {
    Node(Node* parent, char c) {
      this->parent = parent;
      this->char_to_parent = c;
      this->number_of_income = 0;
    }
    std::map<char, Node*> children;
    Node* parent;
    char char_to_parent;
    size_t number_of_income;
    ~Node() {
      for(auto node : children) {
        delete node.second;
      }
    }
  };
  std::pair<Node*, size_t> GetHintNode(Node* node) {
    if(node == nullptr) {
      return {nullptr, 0};
    }
    size_t income_count = node->number_of_income;
    Node* result_node = node;
    for(auto child : node->children) {
      auto result = GetHintNode(child.second);
      if (result.second > income_count) {
        income_count = result.second;
        result_node = result.first;
      }
    }
    return {result_node, income_count};
  }
  std::string GetString(Node* node) {
    std::string s;
    while(node != root) {
      s.push_back(node->char_to_parent);
      node = node->parent;
    }
    std::reverse(s.begin(), s.end());
    return s;
  }

  Node* GetNode(const std::string& s) {
    Node* current_node = root;
    for(char c : s) {
      if (current_node->children[c] == nullptr) {
        return nullptr;
      }
      current_node = current_node->children[c];
    }
    return current_node;
  }
  Node* root;
};

}

#endif //PROG__WORD_STORAGE_H_
