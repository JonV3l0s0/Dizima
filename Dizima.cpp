#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

int main() {
    char escolha, resp;
    bool repetir;
    int parteInteira, periodo, antiPeriodo, periodoOriginal, antiPeriodoOriginal, nAlgarismosPeriodo, nAlgarismosAntiPeriodo, numerador, denominador;

    printf("Gerador de fracao geratriz de dizima periodica\n\n");

    repetir = true;

	do {
        printf("Dentre as opcoes abaixo, escolha qual tipo de dizima voce ira inserir:\n[1] - Simples\n[2] - Composta\n\nDigite a sua escolha\n");
        scanf(" %c", &escolha);
	
		if(escolha == '1') {
			printf(" \nDigite a parte inteira da dizima\n");
			scanf("%i", &parteInteira);
			printf("Digite o periodo da dizima\n");
			scanf("%i", &periodo);
		
			periodoOriginal = periodo;
			nAlgarismosPeriodo = 0;
			denominador = 0;
			
			//Contador de quantidade de algarismos presentes no periodo
			while(periodo > 0) {
				periodo /= 10;
				denominador += 9*pow(10,nAlgarismosPeriodo);
				nAlgarismosPeriodo++;
			}
		
			numerador = ((parteInteira*pow(10, nAlgarismosPeriodo))+periodoOriginal) - parteInteira;
		
			//Codigo para simplificar a fracao
			for(int i = 1; i < denominador; i++){
				if((denominador%i==0)&&(numerador%i==0)){
					denominador /= i;
					numerador /= i;
				}
			}
		
			printf("A fracao da sua dizima periodica simples %i,%i%i%i%i%i...\n",parteInteira,periodoOriginal,periodoOriginal,periodoOriginal,periodoOriginal,periodoOriginal);
			printf("E : %i/%i", numerador,denominador);
		} 
		else if (escolha == '2'){
			printf(" \n");
			printf("Digite a parte inteira da dizima\n");
			scanf("%i", &parteInteira);
			printf("Digite o antiperiodo da dizima\n");
			scanf("%i", &antiPeriodo);
			printf("Digite o periodo da dizima\n");
			scanf("%i", &periodo);
		
			periodoOriginal = periodo;
			antiPeriodoOriginal = antiPeriodo;
			nAlgarismosPeriodo = 0;
			nAlgarismosAntiPeriodo = 0;
			denominador = 0;
			
			//Contador de quantidade de algarismos presentes no antiperiodo	
			while(antiPeriodo > 0) {
				antiPeriodo /= 10;
				nAlgarismosAntiPeriodo++;
			}		
				
			//Contador de quantidade de algarismos presentes no periodo
			while(periodo > 0) {
				periodo /= 10;
				denominador += 9 * pow(10, nAlgarismosPeriodo + nAlgarismosAntiPeriodo);
				nAlgarismosPeriodo++;
			}
		
			numerador = ((parteInteira*pow(10,(nAlgarismosPeriodo+nAlgarismosAntiPeriodo))) + (antiPeriodoOriginal*pow(10,nAlgarismosPeriodo)) + periodoOriginal) - ((parteInteira*pow(10,nAlgarismosAntiPeriodo)) + antiPeriodoOriginal);
		
			//Codigo para simplificar a fracao
			for(int i = 1; i < denominador; i++){
				if((denominador%i==0)&&(numerador%i==0)){
					denominador /= i;
					numerador /= i;
				}
			}
		
			printf("A fracao da sua dizima periodica composta %i,%i%i%i%i%i%i%i...\n",parteInteira,antiPeriodoOriginal,periodoOriginal,periodoOriginal,periodoOriginal,periodoOriginal,periodoOriginal,periodoOriginal);
			printf("E : %i/%i", numerador,denominador);
		
		}
		printf("\nDeseja inserir outra dizima periodica ? [S/N] ");
        scanf(" %c", &resp);
        
        while (getchar() != '\n');
		
		if(resp == 's' || resp == 'S'){
			repetir = true;
			printf("\n");
		} else {
			repetir = false;
		}
	}while(repetir);

	return 0;
}
