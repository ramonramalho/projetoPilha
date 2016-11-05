#include <stdio.h>
#include <stdlib.h>
struct t_Pilha;
typedef struct t_Pilha Pilha;

int Inicializar_pilha	 (Pilha **inicio);
int Inicializar2_pilha	 (Pilha **inicio);
int Inserir_topo		 (Pilha **inicio, int info);
int Remover_topo		 (Pilha **inicio);
int Obter_topo			 (Pilha *inicio, int *dado);
int Verifica_vazio		 (Pilha *inicio, int *resp);

