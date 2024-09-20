#include "alphabet.h"

Alphabet::Alphabet(const std::string& input) {
  for (unsigned i{0}; i < input.size(); ++i) {
    alphabet_.insert(Symbol(input[i]));
  }
  for (auto symbol_alphabet : alphabet_) {
    std::cout << symbol_alphabet.getSymbol() << " ";
  }
  std::cout << "\n";
}

std::stringstream Alphabet::printAlphabet() const {
  std::stringstream output;
  // cogemos el primer elemento del alfabeto
  output << "{";
  for (auto i = alphabet_.begin(); i != alphabet_.end(); ++i) {
    output << i->getSymbol();
    if (std::next(i) != alphabet_.end()) {
      // Check if it is not the last element to don't print the comma
      output << ", ";
    }
  }
  output << "}" << "\n";
  output << std::endl;
  return output;
}