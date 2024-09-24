// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia // Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.edu.es
// Fecha: 24/09/2024
// Archivo main.cc: programa cliente.
// Contiene la funcióon main del proyecto.
#ifndef __main_cc__
#define __main_cc__

#include "chain.h"
/**
 * @brief Función principal que procesa una cadena y realiza operaciones 
 * según el código de operación proporcionado en los argumentos.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Argumentos pasados al programa.
 *             - argv[1]: Archivo de entrada con la cadena y el alfabeto.
 *             - argv[2]: Archivo de salida para escribir los resultados.
 *             - argv[3]: Código de operación:
 *                        - 1: Imprimir el alfabeto.
 *                        - 2: Imprimir el tamaño de la cadena.
 *                        - 3: Imprimir la cadena en orden inverso.
 *                        - 4: Imprimir los prefijos de la cadena.
 *                        - 5: Imprimir los sufijos de la cadena.
 * 
 * @return int Código de estado del programa (0 si todo fue correcto, 1 si hubo
 * errores).
 */
int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::string help{argv[1]};
    if (help == "--help") {
      std::cerr << "Uso: ./p01_chain inputfile outputfile opcode\n";
      std::cerr << "Opcode: " << std::endl;
      std::cerr << "- 1: Imprimir el alfabeto." << std::endl;
      std::cerr << "- 2: Imprimir el tamaño de la cadena." << std::endl;
      std::cerr << "- 3: Imprimir la cadena en orden inverso." << std::endl;
      std::cerr << "- 4: Imprimir los prefijos de la cadena." << std::endl;
      std::cerr << "- 5: Imprimir los sufijos de la cadena." << std::endl;                    
      return 1;
    }
    std::cerr << "Uso incorrecto. Para mostrar uso introduzca --help" << std::endl;
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
      // std::cout << input << std::endl;
      Chain chain(input); // Create a chain object
      // std::cout << chain;
      // std::cout << "\n";
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