#include "word_storage.h"


autocompleter::WordStorage::WordStorage() {
  root = new Node(nullptr, '\0');
}

void autocompleter::WordStorage::AddWord(const std::string &word) {
  Node* current_node = root;
  for(char c : word) {
    if (current_node->children[c] == nullptr) {
      Node* node = new Node(current_node, c);
      current_node->children[c] = node;
    }
    current_node = current_node->children[c];
  }
  ++current_node->number_of_income;
}

std::string autocompleter::WordStorage::GetHint(const std::string &word) {
  Node* node = GetNode(word);
  if(node == nullptr) {
    return "i don't have hint for this string";
  }
  auto hint_result = GetHintNode(node);
  return GetString(hint_result.first);
}

autocompleter::WordStorage::~WordStorage() {
  delete root;
}

autocompleter::WordStorage::Node::Node(autocompleter::WordStorage::Node *parent, char c) {
  this->parent = parent;
  this->char_to_parent = c;
  this->number_of_income = 0;
}

autocompleter::WordStorage::Node::~Node() {
  for(auto node : children) {
    delete node.second;
  }
}

std::pair<autocompleter::WordStorage::Node*, size_t>
    autocompleter::WordStorage::GetHintNode(Node* node)
{
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

std::string autocompleter::WordStorage::GetString(autocompleter::WordStorage::Node *node) {
  std::string s;
  while(node != root) {
    s.push_back(node->char_to_parent);
    node = node->parent;
  }
  std::reverse(s.begin(), s.end());
  return s;
}

autocompleter::WordStorage::Node* autocompleter::WordStorage::GetNode(const std::string &s) {
  Node* current_node = root;
  for(char c : s) {
    if (current_node->children[c] == nullptr) {
      return nullptr;
    }
    current_node = current_node->children[c];
  }
  return current_node;
}