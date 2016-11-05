#include <stdio.h>
#include <stdlib.h>
#define ERRO 1
#define OK 0

struct t_Pilha;
typedef struct t_Pilha Pilha;

int Inicializar_pilha	 (Pilha **inicio);
int Resetar_pilha		 (Pilha **inicio);

int Push_pilha			 (Pilha **inicio, int info);
int Pop_pilha			 (Pilha **inicio, int *dado);
int IsEmpty_pilha		 (Pilha *inicio, int *resp);

void Inverter_pilha (Pilha **p);
int Tamanho_pilha(Pilha **p);
int Obter_topo(Pilha *inicio, int *dado);

