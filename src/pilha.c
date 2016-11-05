#include "pilha.h"

typedef struct t_Pilha {
	int dado;
	struct t_Pilha *prox;
} Pilha;


//inicializa
int Inicializar_pilha (Pilha **inicio){
	*inicio= NULL;
	return OK;
}

// inicializa apagando tudo da pilha
int Resetar_pilha(Pilha **inicio){
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

//inserir
int Push_pilha(Pilha **inicio, int info){
	Pilha *no_novo = (Pilha *) malloc(sizeof(Pilha));
	no_novo -> dado = info;
	no_novo -> prox = *inicio;
	*inicio = no_novo;
	
	return OK;
}	

//remover e devolver dado
int Pop_pilha(Pilha **inicio, int *dado){
	Pilha *aux;
	if (*inicio == NULL){
		return ERRO;  /* pilha vazia, impossivel remover topo */
	}
	else {
		aux = *inicio; 
		*inicio = (*inicio)->prox;
		*dado = aux->dado;
		free(aux);
		return OK;
	}
}

//verifica vazio
int IsEmpty_pilha(Pilha *inicio, int *resp){
	if (inicio != NULL)
	   *resp = 0; // Pilha nao Vazia
	else
	   *resp = 1; // Pilha Vazia
	return OK;
}


void Inverter_pilha(Pilha **p){
	Pilha *p2;
	int dado;
	Inicializar_pilha(&p2);
	
	while(Pop_pilha(p, &dado) != ERRO){
		Push_pilha(&p2, dado);
	}
	*p = p2;
}

int Tamanho_pilha(Pilha **p){
	if(p == NULL ) return 0;
	Pilha *p2;
	Inicializar_pilha(&p2);
	
	int tamanho=1, dado;
	while(Pop_pilha(p, &dado) != ERRO){
		Push_pilha(&p2, dado);
		tamanho++;
	}
	Inverter_pilha(&p2);
	*p = p2;
	return tamanho;
}

//obter o topo (apenas ler)
int Obter_topo(Pilha *inicio, int *dado){
	if(inicio == NULL) return ERRO; // Pilha Vazia
	
	*dado = inicio -> dado;
	return OK;
}



