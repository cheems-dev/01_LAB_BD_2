#include <iostream>
#include "Trie.h"

int main()
{
  Trie trie;

  trie.Insert("hello", "world");
  trie.Insert("hi", "there");
  trie.Insert("teabag", "tea");
  trie.Insert("teacan", "can");

  std::string value;
  bool success;

  // Buscar en el trie y usar el puntero success
  trie.GetValue("tea", value, &success);
  std::cout << "Searching for 'tea': " << (success ? "Found! Value: " + value : "Not Found") << std::endl;

  trie.GetValue("teabag", value, &success);
  std::cout << "Searching for 'teabag': " << (success ? "Found! Value: " + value : "Not Found") << std::endl;

  trie.GetValue("teacan", value, &success);
  std::cout << "Searching for 'teacan': " << (success ? "Found! Value: " + value : "Not Found") << std::endl;

  trie.GetValue("hi", value, &success);
  std::cout << "Searching for 'hi': " << (success ? "Found! Value: " + value : "Not Found") << std::endl;

  trie.GetValue("hey", value, &success);
  std::cout << "Searching for 'hey': " << (success ? "Found! Value: " + value : "Not Found") << std::endl;

  trie.GetValue("hello", value, &success);
  std::cout << "Searching for 'hello': " << (success ? "Found! Value: " + value : "Not Found") << std::endl;

  std::cout << "Trie Structure:" << std::endl;
  trie.PrintTrie();

  return 0;
}
