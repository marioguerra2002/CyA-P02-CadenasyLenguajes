/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __main_cc__
#define __main_cc__

#include "chain.h"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Uso: " << argv[0] << " <chain>" << std::endl;
    return 1;
  }
  int opcode = std::stoi(argv[3]);
  std::ifstream inputfile(argv[1]);
  std::ofstream outputfile(argv[2]);
  std::string auxiliar;
  std::string input;

  if (inputfile.is_open()) {
    while (std::getline(inputfile, auxiliar)) { // Read line by line
      for (unsigned i = 0; i < auxiliar.size(); ++i) { 
        input += auxiliar[i]; // Introduce the line in the input string
      }
      std::cout << input << std::endl;
      Chain chain(input); // Create a chain object
      std::cout << chain;
      std::cout << "\n";
      switch (opcode)
      {
      case 1:
        outputfile << chain.getAlphabet().printAlphabet().str();
        break;
      case 2:
        outputfile << chain.Size().str();
        break;
      case 3:
        outputfile << chain.Reverse().str();
        break;
      case 4:
        outputfile << chain.Prefixes().str();
        break;
      case 5:
        outputfile << chain.Sufixes().str();
        break;
      default:
        std::cerr << "Por favor, introduzca un valor válido" << std::endl;
        return 1;
      } 
      input.clear(); // Clear the input string
    }
    
  }



  return 0;
  
}

#endif // __main_cc__