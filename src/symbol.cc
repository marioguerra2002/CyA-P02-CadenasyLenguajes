// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo symbol.cc: contiene la implementación de la clase Symbol.
#include "symbol.h"

/**
 * @brief Constructor de la clase Symbol.
 * 
 * @param recieved Carácter recibido que se asignará al atributo symbol_.
 */
Symbol::Symbol(char recieved) {
  symbol_ = recieved;
}

/**
 * @brief Obtiene el símbolo almacenado en el objeto.
 * 
 * @return char El símbolo almacenado.
 */
char Symbol::getSymbol() const {
  return symbol_;
}

/**
 * @brief Sobrecarga del operador de igualdad (==) para comparar dos objetos 
 * Symbol.
 * 
 * @param symbol2 Referencia constante al objeto Symbol a comparar.
 * @return true Si los dos objetos Symbol contienen el mismo carácter.
 * @return false Si los dos objetos Symbol contienen caracteres diferentes.
 */
const bool Symbol::operator==(const Symbol& symbol2) const {
  return symbol_ == symbol2.symbol_;
}

/**
 * @brief Sobrecarga del operador de desigualdad (!=) para comparar dos objetos 
 * Symbol.
 * 
 * @param symbol2 Referencia constante al objeto Symbol a comparar.
 * @return true Si los dos objetos Symbol contienen caracteres diferentes.
 * @return false Si los dos objetos Symbol contienen el mismo carácter.
 */
const bool Symbol::operator!=(const Symbol& symbol2) const {
  return symbol_ != symbol2.symbol_;
}

/**
 * @brief Sobrecarga del operador menor que (<) para comparar dos objetos 
 * Symbol.
 * 
 * @param symbol_2 Referencia constante al objeto Symbol a comparar.
 * @return true Si el símbolo del objeto actual es menor que el símbolo de 
 * symbol_2.
 * @return false Si el símbolo del objeto actual no es menor que el símbolo de 
 * symbol_2.
 */
const bool Symbol::operator<(const Symbol symbol_2) const {
  return symbol_ < symbol_2.symbol_;
}
