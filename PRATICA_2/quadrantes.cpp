/*

* Program: [Quadrantes]

* Author: [Matheus H Medeiros]

* Date: [12/03/2024]

* Description: [Divide a tela em quato quadrantes e imprime em qual desses quadrantes está o cursor]

* License: [CC BY]

*/

#include <iostream>
#include <Windows.h>

int main() {
    POINT cursorPos;
    
    // Definições das variáveis da tela, de resolução 1920x1080p
    int quadrante_altura = 540, quadrante_comprimento = 960;
    bool quit = false;

    while (!quit) {
        GetCursorPos(&cursorPos);
		
		
        if (cursorPos.x < quadrante_comprimento) {
            if (cursorPos.y < quadrante_altura) {
                std::cout << "Quadrante A\n";
            } else {
                std::cout << "Quadrante C\n";
            }
        } else {
            if (cursorPos.y < quadrante_altura) {
                std::cout << "Quadrante B\n";
            } else {
                std::cout << "Quadrante D\n";
            }
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Verifica se a tecla ESC está pressionada
            quit = true;

        Sleep(200);
        system("cls");
    }

    return 0;
}

