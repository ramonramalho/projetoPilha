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
				processoInserirTopo(p);
				break;
			case '2':
				if(Remover_topo(&p) == ERRO){
					printf("\n       | Pilha vazia, remocao impossivel\n");
				}
				break;
			case '3':
				inverter(&p);
				break;
			case '4':
				printf("Tamanho: %d\n", tamanhoPilha(p));
				break;
			case '5':
				{
					int ver;
					Verifica_vazio(p, &ver);
					if(ver==0){
						printf("Pilha não está vazia!\n");
					}else{
						printf("Pilha está vazia\n");
					}
				}
				break;
			case '6':
				processoInverterString();
				break;
		}
	} while(escolha[0] != '7');
	
	Inicializar2_pilha(&p); //limpar pilha da memoria
	return 0;
}
