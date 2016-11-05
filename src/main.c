#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "interface.h"

void inverterString(char **string){
	pilha *p;
	Inicializar_pilha(&p);
	int i=0, j=0;
	while( (*string)[i] != '\0'){
		Inserir_topo(&p, (int)(*string)[i]);
		i++;
	}
	for(; j<i; j++){
		int n;
		Obter_topo(p, &n);
		Remover_topo(&p);
		(*string)[j] = (char) n;
	}
	(*string)[j] = '\0';
}

int main(){
	printCabecalho();
	pilha *p;
	char escolha[100];
	do{
		printMenu();
		fgets(escolha, 100, stdin);
		switch(escolha[0]){
			case '1':
				{
					int info=0;
					printf("Digite o valor a ser acrescentado: \n");
					scanf("%d", &info);
					Inserir_topo(&p, info);
				}
				break;
			case '2':
				Remover_topo(&p);
				break;
			case '3':
				inverter(&p);
				break;
			case '4':
				{
					int tamanho = tamanhoPilha(p);
					printf("Tamanho: %d\n", tamanho);
				}
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
				{
					char* string = (char*) malloc(sizeof(char) * 300);
					fgets(string, 300, stdin);
					
					int i=0; for(; i<300; i++) if(string[i]=='\n'){ string[i]='\0'; break; } //tirar \n
					inverterString((char**)&string);
					printf("%s\n", string);
					free(string);
				} 
				break;
		}
	} while(escolha[0] != '7');
	
	Inicializar2_pilha(&p);
	return 0;
}
