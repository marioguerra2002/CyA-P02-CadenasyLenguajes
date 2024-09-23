// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo symbol.h: contiene la declaración de la clase Symbol.
#ifndef __symbol_h__  // If not defined symbol_h
#define __symbol_h__  // Define symbol_h
/**
 * @brief Clase que representa un símbolo.
 */
class Symbol {  // Symbol class
public:
    Symbol(char);
    Symbol() {};
    char getSymbol(void) const;  // getter de la clase
    // void setSymbol(const std::string&);
    const bool operator!=(const Symbol&) const;
    const bool operator==(const Symbol&) const;
    const bool operator<(const Symbol) const;
    // comparing operator for setter
private:
    char symbol_;  // Name of the symbol
};

#endif  // End of symbol_h
