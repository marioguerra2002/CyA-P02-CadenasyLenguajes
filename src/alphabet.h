// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo alphabet.h: contiene la declaración de la clase Alphabet.
#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "symbol.h"  // Include symbol header file
/**
 * @brief Clase que representa un alfabeto compuesto por símbolos.
 */
class Alphabet {  // Alphabet class
  public:
    Alphabet() {}; // Default constructor
    Alphabet(const std::string& ); // Constructor
    // Add symbol to alphabet in
    std::set<Symbol> getAlphabet() const { return alphabet_; }
    // Get alphabet
    void print() const {
      for (const auto& symbol : alphabet_) {
        std::cout << symbol.getSymbol() << " ";
      }
    }
    std::stringstream printAlphabet() const;
  private:
    std::set<Symbol> alphabet_;  // Vector of symbols
};
#endif // End of alphabet_h