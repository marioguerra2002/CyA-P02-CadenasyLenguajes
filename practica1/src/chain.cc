#include "chain.h"
std::stringstream output;
Chain::Chain(const std::string& input) {
  std::string auxiliar;
  std::vector <std::string> vect_auxiliar;
  // char space = {' '};
  for (unsigned i = 0; i < input.size(); ++i) {
    if (input[i] != ' ') {
      auxiliar += input[i];
    }
    else {
      vect_auxiliar.push_back(auxiliar);
      auxiliar.clear();
    }
  }

  vect_auxiliar.push_back(auxiliar); // Add the last word to the vector
  // Now we have a vector with the alphabet and the chain
  auxiliar.clear(); 
  // Create the alphabet with the first n-1 elements of the vector
  alphabet_ = Alphabet(vect_auxiliar);
  // std::cout << "Alphabet: ";
  // alphabet_.print();
  // Now we divide the chain in Symbols depending of the alphabet
  for (int i = 0; i < vect_auxiliar[vect_auxiliar.size() - 1].size(); ++i) {
    auxiliar += vect_auxiliar[vect_auxiliar.size() - 1][i];
    // In vect_auxiliar there is the alphabet and the chain (in last position)
    Symbol auxiliar_symb(auxiliar);
    for (auto symbol_alphabet : alphabet_.getAlphabet()) {
      if (auxiliar_symb == symbol_alphabet.getSymbol()) {
        // If exist a symbol in alphabet
        chain_.push_back(auxiliar_symb);
        auxiliar.clear();
      }
    }
  }

  if (auxiliar != "") {
    // In case de auxiliar isn't empty
    chain_.push_back(Symbol(auxiliar));
    std::cerr << "Error, cadena no valida" << std::endl;
    exit(1);
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
  // Size of the vect
  output << chain_.size() << std::endl;
  return output;
}

std::stringstream Chain::Reverse() {
  std::stringstream output;
  // Go around the chain from back to from
  for (int i = chain_.size(); i >= 0; --i) {
    output << chain_[i].getSymbol() << " ";
  }
  output << std::endl;
  return output;
}

std::stringstream Chain::Prefixes() {
  std::stringstream output;
  output << "&" << "\n";
  std::vector<Symbol> auxiliar_vect;
  for (auto symbol : chain_) {
    auxiliar_vect.push_back(symbol);
    //std::cout << auxiliar_vect;
    output << auxiliar_vect;
  }
  output << "\n";
  return output;
}

std::stringstream Chain::Sufixes(){
  std::stringstream output;
  output << "&" << "\n";
  std::vector<Symbol> auxiliar_vect;
  for (int i = chain_.size() - 1; i >= 0; --i) {
    auxiliar_vect.push_back(chain_[i]);
    for (int j = auxiliar_vect.size() - 1; j >= 0; --j) {
      output << auxiliar_vect[j].getSymbol();
    }
    output << "\n";
  }
  output << "\n";
  return output;
}

std::stringstream Chain::Subchain() {
  std::stringstream output;
  output << "&";
  return output;
}