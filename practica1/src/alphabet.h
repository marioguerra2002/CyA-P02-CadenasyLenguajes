#include <set>  // Include vector library
#include <vector>  // Include vector library
#include <iostream>
#include "symbol.h"  // Include symbol header file

class Alphabet {  // Alphabet class
  public:
    Alphabet() {}; // Default constructor
    Alphabet(const std::vector<std::string>&); // Constructor
    // Add symbol to alphabet in
    std::set<Symbol> getAlphabet() const { return alphabet_; }  // Get alphabet
    void print() const {
      for (const auto& symbol : alphabet_) {
        std::cout << symbol.getSymbol() << " ";
      }
    }

  private:
    std::set<Symbol> alphabet_;  // Vector of symbols
  
};