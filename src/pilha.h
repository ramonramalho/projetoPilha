
typedef struct no_pilha {
	int dado;
	struct no_pilha *prox;
}pilha;

int Inicializar_pilha	  (pilha **inicio);
int Inicializar2_pilha	 (pilha **inicio);
int Inserir_topo		   (pilha **inicio, int info);
int Remover_topo		   (pilha **inicio);
int Obter_topo			 (pilha *inicio, int *dado);
int Verifica_vazio		 (pilha *inicio, int *resp);

//inicializa
int Inicializar_pilha (pilha **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
}

int Inicializar2_pilha(pilha **inicio)
{
	pilha *percorre, *aux;
	if(*inicio != NULL)
	{
	   percorre = *inicio;
	   while (percorre != NULL)
	   {
			 aux = percorre;
			 percorre = percorre -> prox;
			 free(aux);
	   }
	   *inicio = NULL;
	   return 1; // inicializa apagando tudo da pilha
	}
}


//tamanho pilha
int tamanhoPilha(pilha * p){
	pilha * s = p;
	if(s == NULL ){
		return 0;
	}
	int tamanho=1;
	while(s->prox != NULL){
		s = s->prox;
		tamanho++;
	}
	
	return tamanho;
}

//inverter pilha
void inverter (pilha **p)
{
	pilha * p1 = *p;
	pilha * p2;
	pilha * aux = *p;
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
int Inserir_topo (pilha **inicio, int info)
{
	pilha *no_novo;

	/* Criacao do novo no - Alocação de memoria */
	no_novo = (pilha *) malloc(sizeof(pilha));
	no_novo -> dado = info;

	if (*inicio==NULL)
	{	// insercao em pilha vazia
		no_novo -> prox = NULL;
		*inicio = no_novo;
	}
	else { // insercao em pilha nao vazia
		 no_novo -> prox = *inicio;
		*inicio = no_novo;
	}
	return 0;
}	


//remover
int Remover_topo (pilha **inicio)
{
	pilha *aux;
	if (*inicio == NULL)
	{
		 printf("\nPilha VAZIA ! \nRemocao Impossivel\n");
		return 1;  /* pilha vazia, impossivel remover topo */
	}
	else {
		aux = *inicio; 
		*inicio = (*inicio)->prox;
		free(aux);
		return 0;
	}
}


//obter o topo
int Obter_topo(pilha *inicio, int *dado)
{
	if (inicio != NULL)
	{
	   *dado = inicio -> dado;
	   return 0;
	}
	else
	   return 1; // Pilha Vazia
}


//verifica vazio
int Verifica_vazio (pilha *inicio, int *resp)
{
	if (inicio != NULL)
	   *resp = 0; // Pilha nao Vazia
	else
	   *resp = 1; // Pilha Vazia
	return 0; 
}

