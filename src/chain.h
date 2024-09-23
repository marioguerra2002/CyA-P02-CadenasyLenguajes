// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo chain.h: contiene la declaración de la clase Chain.
#ifndef CHAIN_H
#define CHAIN_H

#include "alphabet.h"
#include <fstream>
/**
 * @brief Clase que representa una cadena de símbolos pertenecientes a un 
 * alfabeto.
 */
class Chain {
  public:
    Chain() {};  // Default constructor
    Chain(const std::string&);  // Constructor
    Chain getChain();
    Alphabet getAlphabet() const { return alphabet_; }  // Get alphabet
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
    friend std::ostream& operator<<(std::istream& os,
    const std::vector<Symbol>& vector);
    //friend std::istream& operator>>(std::istream& is, Chain& chain);
    std::stringstream Size();
    std::stringstream Reverse();
    std::stringstream Prefixes();
    std::stringstream Sufixes();

  private:
    std::vector<Symbol> chain_;  // Vector of strings
    Alphabet alphabet_;  // Alphabet object used to create the chain  
};
#endif  // End of chain_h