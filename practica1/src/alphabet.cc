
#include "alphabet.h"

Alphabet::Alphabet(const std::vector<std::string>& input) {
  if (input.size() == 1) {alphabet_.insert(Symbol(input[0]));}
  // If there is just 1 thing, it's the alphabet
  else {
    for (unsigned i = 0; i < input.size() - 1; ++i) {
      alphabet_.insert(Symbol(input[i]));
    }
  }
  std::cout << "Alphabet: ";
  for (auto symbol_alphabet : alphabet_) {
    std::cout << symbol_alphabet.getSymbol() << " ";
  }
  std::cout << "\n";
}

