#include "Trie.h"

Trie::Trie() : root_(make_unique<TrieNodeWithValue>('\0')) {}

bool Trie::Insert(const string &key, const string &value)
{
  TrieNodeWithValue *current = static_cast<TrieNodeWithValue *>(root_.get());
  for (char ch : key)
  {
    if (!current->HasChild(ch))
    {
      current->InsertChildNode(ch, make_unique<TrieNodeWithValue>(ch));
    }
    current = static_cast<TrieNodeWithValue *>(current->GetChildNode(ch));
  }
  if (current->IsEndNode())
  {
    return false;
  }
  current->SetEndNode(true);
  current->SetValue(value);
  return true;
}

bool Trie::GetValue(const std::string &key, std::string &value, bool *success) const
{
  TrieNodeWithValue *current = static_cast<TrieNodeWithValue *>(root_.get());
  for (char ch : key)
  {
    if (!current->HasChild(ch))
    {
      if (success)
        *success = false;
      return false;
    }
    current = static_cast<TrieNodeWithValue *>(current->GetChildNode(ch));
  }
  if (current->IsEndNode())
  {
    value = current->GetValue();
    if (success)
      *success = true;
    return true;
  }
  if (success)
    *success = false;
  return false;
}

void Trie::PrintTrie() const
{
  root_->PrintTrie();
  cout << endl;
}
