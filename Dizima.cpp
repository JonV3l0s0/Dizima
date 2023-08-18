#include<stdio.h>
#include<conio.h>
#include<math.h>

main(){
	
	char escolha;
	int parteInteira, periodo, periodoOriginal, nAlgarismosPeriodo, numerador, denominador;

	
	printf("Gerador de fracao geratriz de dizima periodica\n\n");
	
	printf("Dentre as opcoes abaixo, escolha qual tipo de dizima voce ira inserir:\n");
	printf("[1] - Simples\n");
	printf("[2] - Composta\n\n");
	
	printf("Digite a sua escolha\n");
	scanf("%c", &escolha);
	
	if(escolha == '1') {
		printf("Simples\n");
		printf("Digite a parte inteira da dizima\n");
		scanf("%i", &parteInteira);
		printf("Digite o periodo da dizima\n");
		scanf("%i", &periodo);
		
		periodoOriginal = periodo;
		nAlgarismosPeriodo = 0;
		denominador = 0;
		
		while(periodo > 0) {
			periodo /= 10;
denominador = denominador + (9*pow(10,nAlgarismosPeriodo));
			nAlgarismosPeriodo++;
			
			
			

		}
		numerador = ((parteInteira*pow(10, nAlgarismosPeriodo))+periodoOriginal) - parteInteira;
		
		printf("A fracao da sua dizima periodica simples %i,%i%i%i...\n",parteInteira,periodoOriginal,periodoOriginal,periodoOriginal);
		printf("E : %i/%i", numerador,denominador);


		
	} else if (escolha == '2'){
		printf("Composta");
	}
	getch();
}
