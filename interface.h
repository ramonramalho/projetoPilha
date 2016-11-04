

//User Interface (impressão e leitura)


double mediaAritmetica(double* dados, int numDados){
	double soma = 0;
	int i=0; for(; i<numDados; i++) soma += dados[i];
	return soma / numDados;
}

double desvioPadrao(double* dados, int numDados){
	//https://pt.wikipedia.org/wiki/Desvio_padrão (Desvio Padrão Amostral)
	if(numDados < 2) return 0;
	double soma, media = mediaAritmetica(dados, numDados);
	int i=0; for(; i<numDados; i++) soma += pow(dados[i] - media, 2);
	return sqrt(soma / (numDados-1));
}


void printMediaEDesvio(ConjAmostras* amostras){
	double desvios1[5], medias1[5], desvios2[5], medias2[5],
		   *buffer1 = (double*) malloc(sizeof(double)*amostras->top),
		   *buffer2 = (double*) malloc(sizeof(double)*amostras->top);
	int i, j;
	
	for(i=0; i<5; i++){
		for(j=0; j<amostras->top; j++){
			buffer1[j] = amostras->amo[j]->med[i]->Atenua;
			buffer2[j] = amostras->amo[j]->med[i]->Veloc;
		}
		
		desvios1[i] = desvioPadrao(buffer1, amostras->top);
		medias1[i] = mediaAritmetica(buffer1, amostras->top);
		
		desvios2[i] = desvioPadrao(buffer2, amostras->top);
		medias2[i] = mediaAritmetica(buffer2, amostras->top);
	}
	
	free(buffer1); free(buffer2);
	
	
	puts("\n\n______________________________________________________________");
	printf("                    Desvio padrao e medias                    |\n");
	printf("==============================================================|\n");
	
	printf("      Atenuacao                                               |\n");
	printf("__________________       3%%      6%%      10%%     15%%     20%%\n");
	
	printf("   Desvios padrao |  ");
	for(i=0; i<5; i++) printf("%8.3lf%s", desvios1[i], i==4?"\n":"");
	printf("           Medias |  ");
	for(i=0; i<5; i++) printf("%8.2lf%s", medias1[i], i==4?"\n":"");
	
	printf("__________________|___________________________________________|\n");
	printf("     Velocidade                                               |\n");
	printf("__________________       3%%      6%%      10%%     15%%     20%%\n");
	
	printf("   Desvios padrao |  ");
	for(i=0; i<5; i++) printf("%8.3lf%s", desvios2[i], i==4?"\n":"");
	printf("           Medias |  ");
	for(i=0; i<5; i++) printf("%8.2lf%s", medias2[i], i==4?"\n":"");
	puts("__________________|___________________________________________|\n");
}



// Funções para imprimir Registros

void printMedida(Medida * medida){
	printf("%7.3f, %-8.3f", medida->Atenua, medida->Veloc);
}

void printAmostr(Amostra* a){
	printf("%s%d  ", a->ID<10?"00" : a->ID<100?"0" : "", a->ID);
	int i=0;
	for(; i<a->top; i++){
		printMedida( a->med[i] );
		if(i != 4) printf("|");
	}
	printf("\n");
}

void printConjAmostras(ConjAmostras* set){
	char *s="             ";
	puts("\n\n______________________________________________________________");
	printf("%s         Exibindo Amostra%s (%d ite%s)\t      |\n",
		s, set->top==1?"":"s", set->top, set->top==1?"m":"ns"
	);
	printf("%s                                                 |\n", s);
	printf("%s       (Recomenda-se maximizar a janela)         |", s);
	printf("\n\n%s 3%% %s 6%% %s 10%% %s 15%% %s 20%%\n", s,s,s,s,s);
	printf(" ID    ");
	int i=0; for(; i<5; i++) printf("Aten     Vel%s", i==4?"\n":"      ");
	for(i=0; i<set->top; i++) printAmostr( set->amo[i] );
	printf("\n");
	
	printf("%s                 %d Amostra%s Exibida%s\t      |\n",
		s, set->top, set->top==1?"":"s", set->top==1?"":"s"
	);
	printf("%s       (Recomenda-se maximizar a janela)         |\n", s);
	puts("______________________________________________________________|\n");
}


void printMenu(){
	char *s = "           ";
	printf("\n%s ________________________________________\n", s);
	printf("%s|                                        |\n", s);
	printf("%s|      Analise de amostras de leite      |\n", s);
	printf("%s|                                        |\n", s);
	printf("%s|  1 - Imprimir Amostras                 |\n", s);
	printf("%s|  2 - Imprimir desvio padrao e medias   |\n", s);
	printf("%s|  3 - Carregar outros arquivos          |\n", s);
	printf("%s|  4 - Salvar graficos para analise      |\n", s);
	printf("%s|  5 - Sair                              |\n", s);
	printf("%s|________________________________________|\n", s);
	printf("%s Escolha uma opcao: ", s);
}

void printCabecalho(){
	printf("\n______________________________________________________________\n");
	printf("                                              |   |   |   |   |\n");
	printf("                        PROJETO SI200A        | 2 | 0 | 1 | 6 |\n");
	printf("______________________________________________|___|___|___|___|\n");
	printf("\n          Algoritmos e Programacao de Computadores II");
	printf("\n______________________________________________________________\n");
	printf("                                                              |\n");
	printf("                 Sergio Ferreira Batista Filho.......187064   |\n");
	printf("                  Rafael Porto Sellis.................45937   |\n");
	printf("______________________________________________________________|\n");
}

void procTrocarArquivos(char* msg, int showNames, char* fileA, char* fileB){
	puts("\n______________________________________________________________");
	puts("                                                              |");
	printf("%s|\n", msg);
	if(showNames) printf("                   (\"%s\" e \"%s\")\n", fileA, fileB);
	printf("\n");
	printf("       Escolha um arquivo contendo dados de ATENUACAO:        |\n");
	printf("   > ");
	fgets(fileA, 200, stdin);
	int i=0; for(; i<200; i++) if(fileA[i] == '\n') fileA[i] = '\0';
	printf("\n       E um arquivo contendo dados das VELOCIDADES:           |\n");
	printf("   > ");
	fgets(fileB, 200, stdin);
	for(i=0; i<200; i++) if(fileB[i] == '\n') fileB[i] = '\0';
	printf("\n______________________________________________________________|\n");
}

void procFalhaCarregarArquivos(char* fileA, char* fileB, ConjAmostras** a){
	do{
		procTrocarArquivos(
			"               Falha ao abrir arquivos de entrada             ", 1,
			fileA, fileB
		);
		cleanupAmostras(*a); //limpar amostras
		*a = newConjAmostras(fileA, fileB);
	}
	while(*a == NULL);
}

void procFalhaSalvarImagem(char* file){
	puts("\n______________________________________________________________");
	printf("                                                              |\n");
	printf("                 Falha ao tentar salvar imagem                |\n");
	printf("                       \"%s\"", file);
	printf("\n");
	printf("       Escolha outro nome para a imagem:                      |\n");
	printf("   > ");
	fgets(file, 200, stdin);
	int i=0; for(; i<200; i++) if(file[i] == '\n') file[i] = '\0';
	printf("\n______________________________________________________________|\n");
}

void printImagensSalvas(char** files){
	puts("\n______________________________________________________________");
	printf("                                                              |\n");
	printf("            Imagens salvas com os seguintes nomes:            |\n");
	printf("                                                              |\n");
	int i=0; for(; i<5; i++) printf("       * \"%s\"\n", files[i]);
	printf("______________________________________________________________|\n");
}







