#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class TrieNode
{
public:
  TrieNode(char key_char);

  bool HasChild(char key_char) const;
  TrieNode *GetChildNode(char key_char);
  void InsertChildNode(char key_char, unique_ptr<TrieNode> child);
  void SetEndNode(bool is_end);
  bool IsEndNode() const;
  char GetKeyChar() const;
  void PrintTrie(const string &prefix = "") const;

private:
  char key_char_;
  bool is_end_;
  vector<unique_ptr<TrieNode>> children_{26};
};

#endif // TRIENODE_H
