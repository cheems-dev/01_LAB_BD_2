#include "TrieNode.h"

TrieNode::TrieNode(char key_char) : key_char_(key_char), is_end_(false) {}

bool TrieNode::HasChild(char key_char) const
{
  int index = key_char - 'a';
  return index >= 0 && index < children_.size() && children_[index] != nullptr;
}

TrieNode *TrieNode::GetChildNode(char key_char)
{
  int index = key_char - 'a';
  return (index >= 0 && index < children_.size()) ? children_[index].get() : nullptr;
}

void TrieNode::InsertChildNode(char key_char, unique_ptr<TrieNode> child)
{
  int index = key_char - 'a';
  if (index >= 0 && index < children_.size())
  {
    children_[index] = move(child);
  }
}

void TrieNode::SetEndNode(bool is_end)
{
  is_end_ = is_end;
}

bool TrieNode::IsEndNode() const
{
  return is_end_;
}

char TrieNode::GetKeyChar() const
{
  return key_char_;
}

void TrieNode::PrintTrie(const string &prefix) const
{
  if (is_end_)
  {
    cout << prefix << " -> ";
  }

  for (const auto &child : children_)
  {
    if (child)
    {
      child->PrintTrie(prefix + child->GetKeyChar());
    }
  }
}
