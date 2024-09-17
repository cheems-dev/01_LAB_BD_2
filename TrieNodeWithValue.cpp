#include "TrieNodeWithValue.h"

TrieNodeWithValue::TrieNodeWithValue(char key_char) : TrieNode(key_char) {}

void TrieNodeWithValue::SetValue(const string &value)
{
  value_ = value;
}

string TrieNodeWithValue::GetValue() const
{
  return value_;
}
