#include <stdio.h>
#include <stdlib.h>
struct no_pilha;
typedef struct no_pilha pilha;

int Inicializar_pilha	  (pilha **inicio);
int Inicializar2_pilha	 (pilha **inicio);
int Inserir_topo		   (pilha **inicio, int info);
int Remover_topo		   (pilha **inicio);
int Obter_topo			 (pilha *inicio, int *dado);
int Verifica_vazio		 (pilha *inicio, int *resp);

