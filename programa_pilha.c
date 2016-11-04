#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void menu(){
	printf("\n");
	printf("1-inserir topo\n");
	printf("2-remover topo\n");
	printf("3-inverter pilha\n");
	printf("4-tamanho da pilha\n");
	printf("5-verifica se a pilha está vazia\n");
	printf("6-sair\n");
	
}

int main(){
	pilha *p;
	int escolha=0;
	do{
		menu();
		scanf("%d", &escolha);
		if(escolha==1){
				int info=0;
				printf("Digite o valor a ser acrescentado: \n");
				scanf("%d", &info);
				Inserir_topo(&p, info);
		}else if(escolha==2){
				Remover_topo(&p);
		}else if(escolha==5){
			int ver;
			Verifica_vazio(p, &ver);
			if(ver==0){
				printf("Pilha não está vazia!\n");
			}else{
				printf("Pilha está vazia\n");	
			}
		}else if(escolha==4){
			int tamanho = tamanhoPilha(p);
			printf("Tamanho: %d\n", tamanho);
		}else if(escolha==3){
			inverter(&p);
		}
	}while(escolha!=6);
return 0;
}
