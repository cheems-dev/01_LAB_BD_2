#ifndef TRIE_H
#define TRIE_H

#include <memory>
#include <string>
#include "TrieNodeWithValue.h"

class Trie
{
public:
  Trie();
  bool Insert(const std::string &key, const std::string &value);
  bool GetValue(const std::string &key, std::string &value, bool *success) const;
  void PrintTrie() const;

private:
  std::unique_ptr<TrieNodeWithValue> root_;
};

#endif // TRIE_H
