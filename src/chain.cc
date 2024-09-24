// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo chain.cc: contiene la implementación de la clase Chain.
#include "chain.h"
const char kSpace = ' ';
const char kVoid_chain = '&';
const std::string kVoid_chain_string{"&"};
std::stringstream output;

/**
 * @brief Constructor de la clase Chain. Crea una cadena a partir de una 
 * cadena de entrada, construyendo también un alfabeto a partir de los 
 * símbolos de la cadena.
 * 
 * @param input Cadena de entrada que contiene tanto la cadena como el alfabeto.
 */
Chain::Chain(const std::string& input) {
  std::string auxiliar; // usado para construir el alfabeto
  std::vector<std::string> input_divided;
  for (ulong i{0}; i < input.size() - 1; ++i) {
    if (input[i] != kSpace) {
      auxiliar.push_back(input[i]);
    } else {
      input_divided.push_back(auxiliar);
      auxiliar.clear();
    }
  }
  input_divided.push_back(auxiliar);
  auxiliar.clear();
  if (input_divided.size() == 1) { // solo está el alfabeto
    void_chain_ = true;
  }
  if (void_chain_ == true) {
    if (input[0] == kVoid_chain) {
      std::cerr << "El alfabeto no puede ser vacío" << std::endl;
      exit(EXIT_FAILURE);
    }
    alphabet_ = Alphabet(input);
    chain_.push_back(Symbol(kVoid_chain));
  } else {
    for (ulong i{input.size() - 1}; i >= 0; --i) {
      if (input[i] == kSpace) {
        break;
      }
      auxiliar += input[i];
    }
    alphabet_ = Alphabet(auxiliar);
    // crea el objeto alfabeto con la cadena auxiliar
    auxiliar.clear();
    
    // Separa la cadena del alfabeto en la entrada
    for (int i{0}; input[i] != kSpace; ++i) {
    auxiliar += input[i];
    }
    // Compara cada símbolo con el alfabeto y lo inserta en la cadena
    for (unsigned i{0}; i < auxiliar.size(); ++i) {
      std::set<Symbol>::iterator compared = 
        alphabet_.getAlphabet().find(Symbol(auxiliar[i]));
      
      if (Symbol(auxiliar[i]) == *compared || Symbol(auxiliar[i]) == Symbol(kVoid_chain)) {
        chain_.push_back(Symbol(auxiliar[i]));
        if (Symbol(auxiliar[i]) == Symbol(kVoid_chain)) {void_chain_ = true;}
      } else {
        std::cerr << "El simbolo " << auxiliar[i] <<
        " no pertenece al alfabeto" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
  }
}
  
/**
 * @brief Sobrecarga del operador de inserción para imprimir la cadena.
 * 
 * @param os Flujo de salida (ostream).
 * @param chain Objeto Chain que se imprimirá.
 * @return std::ostream& El flujo de salida modificado.
 */
std::ostream& operator<< (std::ostream &os, const Chain& chain) {
  for (auto& symbol : chain.chain_) {
    os << symbol.getSymbol();
  }
  os << std::endl;
  return os;
}
/**
 * @brief Sobrecarga del operador de inserción para imprimir un vector de 
 * símbolos.
 * 
 * @param os Flujo de salida (ostream).
 * @param vector Vector de símbolos a imprimir.
 * @return std::ostream& El flujo de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const std::vector<Symbol>& vector) {
  for (auto& symbol : vector) {
    os << symbol.getSymbol();
  }
  os << std::endl;
  return os;
}
/**
 * @brief Devuelve el tamaño de la cadena como un flujo de salida (stringstream).
 * 
 * @return std::stringstream Tamaño de la cadena.
 */
std::stringstream Chain::Size() { 
  std::stringstream output;
  output << chain_.size() << std::endl;
  return output;
}
/**
 * @brief Devuelve la cadena invertida como un flujo de salida (stringstream).
 * 
 * @return std::stringstream La cadena en orden inverso.
 */
std::stringstream Chain::Reverse() {
  std::stringstream output;
  // Recorre la cadena desde el final hasta el principio
  for (ulong i = chain_.size() - 1; i >= 0; --i) {
    output << chain_[i].getSymbol() << " ";
  }
  output << std::endl;
  return output;
}
/**
 * @brief Devuelve los prefijos de la cadena como un flujo de salida 
 * (stringstream).
 * 
 * @return std::stringstream Prefijos de la cadena.
 */
std::stringstream Chain::Prefixes() {
  std::stringstream output;
  output << "{";
  if (void_chain_ == false) {
    output << "&, ";  // El primer prefijo es el vacío
    for (ulong i = 0; i < chain_.size(); ++i) {
      // Recorre desde el primer elemento hasta el i-ésimo elemento
      for (ulong j = 0; j <= i; ++j) {
        output << chain_[j].getSymbol();
      }
      if (i != chain_.size() - 1) {
        output << ", ";
      }
    }
  } else {
    output << "&";
  }
  output << "}" << std::endl;
  return output;
}

/**
 * @brief Devuelve los sufijos de la cadena como un flujo de salida 
 * (stringstream).
 * 
 * @return std::stringstream Sufijos de la cadena.
 */
std::stringstream Chain::Sufixes() {
  std::stringstream output;
  output << "{";
  if (void_chain_ == false) {
    output << "&, ";  // El primer sufijo es el vacío
    for (int i = chain_.size() - 1; i >= 0; --i) {
      // Recorre desde el último elemento hasta el i-ésimo
      for (int j = i; j < chain_.size(); ++j) {
        output << chain_[j].getSymbol();
      }
      if (i != 0) {  // Evita la coma en el último elemento
        output << ", ";
      }
    }
  } else {
    output << "&";
  }
  output << "}" << std::endl;
  return output;
}
