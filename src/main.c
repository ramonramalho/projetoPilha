#include <stdio.h>
#include <stdlib.h>
#define ERRO 1
#define OK 0
#include "pilha.h"
#include "interface.h"



int main(){
	printCabecalho();
	Pilha *p;
	Inicializar_pilha(&p);
	char escolha[100];
	do{
		printMenu();
		fgets(escolha, 100, stdin);
		switch(escolha[0]){
			case '1':
				processoInserirTopo(&p);
				break;
			case '2':
				processoRemoverTopo(&p);
				break;
			case '3':
				Inverter_pilha(&p);
				printf("\n    | Pilha invertida\n");
				break;
			case '4':
				printf("\n    | Tamanho: %d\n", Tamanho_pilha(&p));
				break;
			case '5':
				{
					int ver;
					IsEmpty_pilha(p, &ver);
					if(ver==0){
						printf("\n    | A pilha não esta vazia\n");
					}else{
						printf("\n    | A pilha esta vazia\n");
					}
				}
				break;
			case '6':
				processoImprimirPilha(&p);
				break;
			case '7':
				processoInverterString();
				break;
		}
	} while(escolha[0] != '8');
	
	Resetar_pilha(&p); //limpar pilha da memoria
	printf("\n");
	return 0;
}


