#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    // Arquivo a ser lido
    std::string filename = "test_file.txt";
    std::string line;

    // Abrir o arquivo para leitura
    file.open(filename);
    
    // Verificar se o arquivo foi aberto com sucesso
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1; // Encerrar o programa com um código de erro
    }

    // Ler cada linha do arquivo e exibi-la na tela
    while (std::getline(file, line)) {
        // \n é incluído para mostrar quantas informações são obtidas a cada vez
        std::cout << line << std::endl;
    }

    // Fechar o arquivo
    file.close();

    return 0; // Retornar 0 indicando a terminação bem-sucedida do programa
}

