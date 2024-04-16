/*

* Program: [Quadrantes]

* Author: [Matheus H Medeiros]

* Date: [12/03/2024]

* Description: [Divide a tela em quato quadrantes e impime em qual desses quadrantes está o cursor]

* License: [CC BY]

*/

#include <stdio.h>
#include <windows.h>

int main() {
    POINT cursorPos;
    
    // Definições das variáveis da tela, de resolução 1920x1080p
    int altura_tela = 1080, comprimento_tela = 1920, quadrante_altura = 540, quadrante_comprimento = 960;
    int quit = 0;

    while (!quit) {
        GetCursorPos(&cursorPos);
		
		// Calculo que retorna 1,2,3 ou 0 para o switch case
        switch (cursorPos.x < quadrante_comprimento ? (cursorPos.y < quadrante_altura ? 0 : 2) : (cursorPos.y < quadrante_altura ? 1 : 3)) {
            case 0:
                printf("Quadrante A\n");
                break;
            case 1:
                printf("Quadrante B\n");
                break;
            case 2:
                printf("Quadrante C\n");
                break;
            case 3:
                printf("Quadrante D\n");
                break;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Verifica se a tecla ESC está pressionada
            quit = 1;

        Sleep(200);
        system("cls");
    }

    return 0;
}

