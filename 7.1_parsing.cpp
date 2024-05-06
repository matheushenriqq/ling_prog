#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream arquivo("arquivo.txt");
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            // Realize o parsing da linha conforme necessário
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    return 0;
}
