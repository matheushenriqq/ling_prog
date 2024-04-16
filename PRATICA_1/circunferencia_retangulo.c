/*

* Program: [Circunferencia e Retangulo]

* Author: [Matheus H Alves Medeiros]

* Date: [05/03/2024]

* Description: [Este progama realiza calculos reelacionados a circunferencia e retangulo a partir de dados atribuidos pelo usuário]

* License: [CC BY]

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const float pi = 3.14;

typedef struct {
	
	float raio;
	float circunf;
	float area;
} circle;

int main (){
	
	int opcao;
	
	printf ("Digite 1 para calculos relacionados a circunferencia ou 2 para relacionados a retangulo\n");
	scanf ("%d", &opcao);
	
	if (opcao == 1){
		
		circle circulo1;
		
		printf ("Digite o valor do raio\n");
		scanf ("%f", &circulo1.raio);
		getchar ();
		
		circulo1.circunf = 2 * pi * circulo1.raio;
		circulo1.area = pi * (pow(circulo1.raio,2));
		
		printf ("O comprimento da circunferenica e: %.2f\n", circulo1.circunf);
		printf ("A medida da area e: %.2f\n", circulo1.area);
	}
	
	else if (opcao == 2) {
		
		float *base, *altura;
		float area, perimetro;
		
		base = (float*)malloc(sizeof(float));
		altura = (float*)malloc(sizeof(float));
		
		printf ("Digite o valor da base\n");
		scanf ("%f", &*base);
		getchar();
		
		printf ("Digite o valor da altura\n");
		scanf ("%f", &*altura);
		getchar();
		
		perimetro = (2* *base) + (2 * *altura);
		area = *base * *altura;
		
		printf ("O perimetro e: %.2f\n", perimetro);
		printf ("A area e: %.2f\n", area);
		
		return 0;
			
	}

}
