#include "symbol.h"

Symbol::Symbol(char recieved) {
  symbol_ = recieved;
}
char Symbol::getSymbol() const {
  return symbol_;
}
// void setSymbol(const std::string& new_symbol) {
//   this* = new_symbol;
// }
const bool Symbol::operator==(const Symbol& symbol2) const {
  return symbol_ == symbol2.symbol_;
}
const bool Symbol::operator!=(const Symbol& symbol2) const {
  return symbol_ != symbol2.symbol_;
}
const bool Symbol::operator<(const Symbol symbol_2) const
{ return symbol_ < symbol_2.symbol_; }