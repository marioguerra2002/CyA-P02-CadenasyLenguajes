#include "chain.h"
const char kSpace = ' ';
std::stringstream output;
Chain::Chain(const std::string& input) {
  std::string auxiliar; // used to introduce the alphabet
  for (unsigned i{input.size() - 1}; i >= 0; --i) {
    if (input[i] == kSpace) {
      break;
    }
    std::cout << "Simbolo: " << input[i] << std::endl;
    auxiliar += input[i];
  }
  std::cout << auxiliar.size() << std::endl;
  alphabet_ = Alphabet(auxiliar);
  // create the alphabet object with the auxiliar string
  auxiliar.clear();
  for (int i{0}; input[i] != kSpace; ++i) {
    auxiliar += input[i];
  }
  for (unsigned i{0}; i < auxiliar.size(); ++i) {
    std::set<Symbol>::iterator compared = 
    alphabet_.getAlphabet().find(Symbol(auxiliar[i]));
    // iterator to compare the symbol with the alphabet
    if (Symbol(auxiliar[i]) == *compared) { 
    // if the symbol is in the alphabet
      chain_.push_back(Symbol(auxiliar[i]));
    } else {
      std::cerr << "El simbolo " << auxiliar[i] <<
      " no pertenece al alfabeto" << std::endl;
    }
  }
}


std::ostream& operator<< (std::ostream &os, const Chain& chain) {
  for (auto& symbol : chain.chain_) {
    os << symbol.getSymbol();
  }
  os << std::endl;
  return os;
}
std::ostream& operator<<(std::ostream& os, const std::vector<Symbol>& vector) {
  for (auto& symbol : vector) {
    os << symbol.getSymbol();
  }
  os << std::endl;
  return os;
}

// std::istream& operator>>(std::istream& is, Chain& chain) {
//   std::string input;
//   is >> input;
//   chain = Chain(input);
//   return is;
// }

std::stringstream Chain::Size() { 
  std::stringstream output;
  // size of the vect
  output << chain_.size() << std::endl;
  return output;
}

std::stringstream Chain::Reverse() {
  std::stringstream output;
  // go around the chain from back to from
  for (int i = chain_.size() - 1; i >= 0; --i) {
    output << chain_[i].getSymbol() << " ";
  }
  output << std::endl;
  return output;
}

std::stringstream Chain::Prefixes() {
  std::stringstream output;
  output << "{";
  output << "&, ";
  for (int i = 0; i < chain_.size(); ++i) {
    // goes from the first element to the last
    for (int j = 0; j <= i; ++j) {
      // goes from the first element to the i-th element to take the prefix
      // (0, 01, 012, 0123...)
      output << chain_[j].getSymbol();
    }
    if (i != chain_.size() - 1) {
      output << ", ";
    }
  }
  output << "}" << std::endl;
  return output;
}

std::stringstream Chain::Sufixes(){
  std::stringstream output;
  output << "{";
  output << "&, ";
  for (int i = chain_.size() - 1; i >= 0; --i) {
    // same than prefixes but from the last element to the first
    for (int j = i; j < chain_.size(); ++j) {
      // goes from the i-th element to the last element to take the sufix
      // (5, 45, 345, 2345...)
      output << chain_[j].getSymbol();
    }
    if (i != 0) { // if it is not the first element (avoid the comma in last)
      output << ", ";
    }
  }
  output << "}" << std::endl;
  return output;
}

