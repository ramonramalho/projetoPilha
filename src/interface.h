

// Interface com o usuário (entrada e saída)


void printMenu(){
	char *s = "           ";
	printf("\n%s ________________________________________\n", s);
	printf("%s|                                        |\n", s);
	printf("%s|            Sistema de pilha            |\n", s);
	printf("%s|                                        |\n", s);
	printf("%s|  1 - Inserir dado na pilha             |\n", s);
	printf("%s|  2 - Remover dado do topo da pilha     |\n", s);
	printf("%s|  3 - Inverter pilha                    |\n", s);
	printf("%s|  4 - Tamanho da pilha                  |\n", s);
	printf("%s|  5 - Verificar se a pilha esta vazia   |\n", s);
	printf("%s|  6 - Inverter string usando pilha      |\n", s);
	printf("%s|  7 - Sair                              |\n", s);
	printf("%s|________________________________________|\n", s);
	printf("%s Escolha uma opcao: ", s);
}

void printCabecalho(){
	printf("\n______________________________________________________________\n");
	printf("                                              |   |   |   |   |\n");
	printf("                        PROJETO PILHA         | 2 | 0 | 1 | 6 |\n");
	printf("______________________________________________|___|___|___|___|\n");
	printf("\n          Algoritmos e Programacao de Computadores II");
	printf("\n______________________________________________________________\n");
	printf("                                                              |\n");
	printf("                 Marcos Ramon Ramalho................183414   |\n");
	printf("                 Sergio Ferreira Batista Filho.......187064   |\n");
	printf("______________________________________________________________|\n");
}


void inverterString(char **string){
	Pilha *p;
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

void processoInverterString(){
	
	char* string = (char*) malloc(sizeof(char) * 300);
	
	puts("\n______________________________________________________________");
	puts("                                                              |");
	printf("       Digite um texto a ser invertido:                       |\n");
	printf("   > ");
	fgets(string, 300, stdin);
	printf("                                                              |\n");
	
	int i=0; for(; i<300; i++) if(string[i]=='\n'){ string[i]='\0'; break; } //tirar \n
	inverterString((char**)&string);
	printf("       Texto invertido:                                       |\n");
	printf("     %s", string);
	printf("\n______________________________________________________________|\n");
	
	free(string);
}


void processoInserirTopo(Pilha *p){
	
	char* string = (char*) malloc(sizeof(char) * 300);
	
	puts("\n______________________________________________________________");
	puts("                                                              |");
	printf("       Digite o valor a ser inserido na pilha                 |\n");
	printf("   > ");
	fgets(string, 300, stdin);
	printf("                                                              |\n");
	
	int info=0;
	sscanf(string, "%d", &info);
	Inserir_topo(&p, info);
	
	printf("       Dado inserido:                                         |\n");
	printf("     %d", info);
	printf("\n______________________________________________________________|\n");
	
	free(string);
}

void processoRemoverTopo(Pilha *p){
	int dado;
	if(Obter_topo(p, &dado) == ERRO){
		printf("\n    | Pilha vazia, remocao impossivel\n");
		return;
	}
	Remover_topo(&p);
	
	printf("\n______________________________________________________________\n");
	printf("                                                              |\n");
	printf("       Dado removido da pilha:                                |\n");
	printf("     %d \n", dado);
	printf("______________________________________________________________|\n");
}






