/*

* Program: [Circunferencia e Retangulo]

* Author: [Matheus H Alves Medeiros]

* Date: [05/03/2024]

* Description: [Este progama realiza calculos reelacionados a circunferencia e retangulo a partir de dados atribuidos pelo usu?rio]

* License: [CC BY]

*/

#include <iostream>

using namespace std;

int main() {
    char opcao;
    cout << "Digite 'c' para calcular circulo ou 'r' para calcular retangulo: \n";
    cin >> opcao;

    if (opcao == 'c') {
    	
        float raio, circunf, area;
        const float pi = 3.14;
        cout << "Digite o raio do circulo: \n";
        cin >> raio;
        circunf = 2 * pi * raio;
        area = pi * raio * raio;
        cout << "O comprimento da circunferencia e: \n" << circunf << endl;
        cout << "A area do circulo e: \n" << area << endl;
    } 
    
    else if (opcao == 'r') {
    	
        float base, altura, perimetro, area;
        cout << "Digite o valor da base: \n";
        cin >> base;
        cout << "Digite o valor da altura: \n";
        cin >> altura;
        perimetro = (base * 2) + (altura * 2);
        area = base * altura;
        cout << "O perimetro do retangulo e: " << perimetro << endl;
        cout << "A area do retangulo e: " << area << endl;
    } 

    
    return 0;
}
