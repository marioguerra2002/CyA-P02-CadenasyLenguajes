#ifndef __symbol_h__  // If not defined symbol_h
#define __symbol_h__  // Define symbol_h

#include <string>  // Include string library
//#include <iostream>  // Include iostream library
/**
 * @brief 
 * 
 */
class Symbol {  // Symbol class
public:
    Symbol(std::string);
    Symbol() {}; 
    std::string getSymbol(void) const;  // getter de la clase
    // void setSymbol(const std::string&);
    const bool operator!=(const Symbol&) const;
    const bool operator==(const Symbol&) const;
    const bool operator<(const Symbol) const;  // operador de compación para setter
private:
    std::string symbol_;  // Name of the symbol
};

#endif  // End of symbol_h