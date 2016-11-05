#include "pilha.h"

typedef struct t_Pilha {
	int dado;
	struct t_Pilha *prox;
} Pilha;


//inicializa
int Inicializar_pilha (Pilha **inicio)
{
	*inicio= NULL;
	return OK; /* sem erro */
}

// inicializa apagando tudo da pilha
int Inicializar2_pilha(Pilha **inicio){
	Pilha *percorre, *aux;
	
	if(*inicio != NULL){
		percorre = *inicio;
		while (percorre != NULL){
			 aux = percorre;
			 percorre = percorre -> prox;
			 free(aux);
		}
		*inicio = NULL;
	}
	
	return OK;
}


//tamanho pilha
int tamanhoPilha(Pilha * p){
	Pilha * s = p;
	if(s == NULL ) return 0;
	
	int tamanho=1;
	while(s->prox != NULL){
		s = s->prox;
		tamanho++;
	}
	
	return tamanho;
}

//inverter pilha
void inverter (Pilha **p)
{
	Pilha * p1 = *p;
	Pilha * p2;
	Pilha * aux = *p;
	Inicializar_pilha(&p2);
	while(aux != NULL){
		int d;
		Obter_topo(aux, &d);
		Inserir_topo(&p2, d);
		aux = aux->prox;
	}
	*p = p2;
	Inicializar2_pilha(&p1);
}

//inserir
int Inserir_topo (Pilha **inicio, int info)
{
	Pilha *no_novo = (Pilha *) malloc(sizeof(Pilha));
	no_novo -> dado = info;
	no_novo -> prox = *inicio;
	*inicio = no_novo;
	
	return 0;
}	


//remover
int Remover_topo (Pilha **inicio)
{
	Pilha *aux;
	if (*inicio == NULL){
		return ERRO;  /* pilha vazia, impossivel remover topo */
	}
	else {
		aux = *inicio; 
		*inicio = (*inicio)->prox;
		free(aux);
		return OK;
	}
}


//obter o topo
int Obter_topo(Pilha *inicio, int *dado)
{
	if(inicio == NULL) return ERRO; // Pilha Vazia
	
	*dado = inicio -> dado;
	return OK;
}


//verifica vazio
int Verifica_vazio (Pilha *inicio, int *resp)
{
	if (inicio != NULL)
	   *resp = 0; // Pilha nao Vazia
	else
	   *resp = 1; // Pilha Vazia
	return OK; 
}

