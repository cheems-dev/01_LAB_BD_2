#ifndef TRIENODEWITHVALUE_H
#define TRIENODEWITHVALUE_H

#include "TrieNode.h"

class TrieNodeWithValue : public TrieNode
{
public:
  TrieNodeWithValue(char key_char);
  void SetValue(const string &value);
  string GetValue() const;

private:
  string value_;
};

#endif // TRIENODEWITHVALUE_H
