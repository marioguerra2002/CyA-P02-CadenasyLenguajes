#include "alphabet.h"  // Include alphabet header file
#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>

class Chain {
  public:
    Chain() {};  // Default constructor
    Chain(const std::string&);  // Constructor
    Chain getChain();
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
    friend std::ostream& operator<<(std::istream& os, const std::vector<Symbol>& vector);
    //friend std::istream& operator>>(std::istream& is, Chain& chain);
    std::stringstream Size();
    std::stringstream Reverse();
    std::stringstream Prefixes();
    std::stringstream Sufixes();
    std::stringstream Subchain();

  private:
    std::vector<Symbol> chain_;  // Vector of strings
    Alphabet alphabet_;  // Alphabet object used to create the chain
    
};

