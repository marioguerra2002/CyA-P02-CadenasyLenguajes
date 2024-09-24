// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo alphabet.cc: contiene la implementación de la clase Alphabet.
#include "alphabet.h"
/**
 * @brief Constructor de la clase Alphabet.
 * 
 * Crea un alfabeto a partir de una cadena de caracteres, insertando cada
 * carácter en un conjunto de símbolos.
 * 
 * @param input Cadena de caracteres de la cual se creará el alfabeto.
 */
Alphabet::Alphabet(const std::string& input) {
  for (unsigned i{0}; i < input.size(); ++i) {
    alphabet_.insert(Symbol(input[i]));
  }

  // // Imprime el alfabeto generado
  // for (auto symbol_alphabet : alphabet_) {
  //   std::cout << symbol_alphabet.getSymbol() << " ";
  // }
  // std::cout << "\n";
}
/**
 * @brief Imprime el alfabeto en un formato de conjunto, separando los 
 * símbolos con comas.
 * 
 * @return std::stringstream Flujo de salida que contiene el alfabeto formateado
 * como un conjunto.
 */
std::stringstream Alphabet::printAlphabet() const {
  std::stringstream output;
  // Imprimimos el primer elemento del alfabeto
  output << "{";
  for (auto i = alphabet_.begin(); i != alphabet_.end(); ++i) {
    output << i->getSymbol();

    // Verifica si no es el último elemento para no imprimir la coma
    if (std::next(i) != alphabet_.end()) {
      output << ", ";
    }
  }
  output << "}" << "\n";
  output << std::endl;
  return output;
}
