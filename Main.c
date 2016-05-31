#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void view(int i, int n, int cache[], int memoria[], char status[]){
	printf("#############################################\n");
	printf("Cache      Status da cache Mem�ria\n");
	for (i = 0; i < n; ++i){		
		printf("Cache %d: %d ", i, cache[i]);		
		printf("Status %d: %c ", i, status[i]);
		printf("    Mem�ria %d: %d\n", i, memoria[i]);
	}
	printf("#############################################\n");	
}

void read(int i, int a, int n, int endereco, int cache[], int memoria[], char status[]){
	for (i = 0; i < n; ++i){
		if(endereco == (int)&memoria[i]){
			cache[a] = memoria[i];
			
			
			//view(i, n, cache, memoria, status);//Exibe toda atividade ap�s a leitura na mem�ria
			
			//system("cls");
			printf("endereco: %d\n", endereco);
			printf("cache: %d\n", a);
			printf("enderecomemory: %d\n", &memoria[i]);
			printf("enderecache: %d\n", &cache[i]);
			printf("cache: %d\n", cache[i]);
			printf("memory: %d\n", memoria[i]);
		}
		if(cache[i] == cache[a] && a != i){
			status[a] = 'S';
			status[i]= 'S';			 
		}
		if(cache[i] != cache[a] && a!= i){
			status[a] = 'E';
			status[i]= 'E';	
		}
		//else{
		//printf("invalido");}
		
	}
	view(i, n, cache, memoria, status);	
}
	

void write(){
}

void listingCache(int i, int n, int cache[]){
	for (i = 0; i < n; ++i){
		printf("Cache %d: %d\n", i, &cache[i]);
	}
}

void listingMemory(int i, int n, int memoria[]){
	for (i = 0; i < n; ++i){
	printf("Mem�ria %d: %d\n", i, &memoria[i]);
	}
}

int main(void)
{
	setlocale(LC_ALL, "Portuguese"); //Uso de caracteres especiais
	int endereco, a;
	int *memoria, *cache;
	int n, i, menu;
	char *status; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inv�lido
	
	//Quantos cache possuir� o sistema, de acordo com o usu�rio final 
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	menu = 100;
	
	//Cria�ao da Mem�ria, Cache e Status da Cache em vetores de aloca��o din�mica
	cache = malloc (n * sizeof (int));
	memoria = malloc (n * sizeof (int));
	status =  malloc (n * sizeof (int));
	srand(time(NULL));
	for (i = 0; i < n; ++i){
		status[i] = 'E';
		cache[i] = 0;
		memoria[i] = rand() % 100;
	}
	
	//menu principal do sistema
	while(menu != 0){
		printf("Quais op��es voc� deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDERE�OS DA CACHE\n4 - LISTAR ENDERE�OS DA MEM�RIA\n0 - SAIR\n");
		scanf("%d", &menu);
		//Leitura da mem�ria para a cache que o usu�rio ir� determinar
		if(menu == 1){
			printf("Qual cache ser� usado pelo endere�o de mem�ria?\n");
			for (i = 0; i < n; ++i){
			printf("cache %d\n", i);
			}
			scanf("%d", &a); //V�riavel a ter� o n�mero de qual cache escolhida
			printf("Qual endere�o de mem�ria ser� lido?\n");
			for (i = 0; i < n; ++i){
			printf("Mem�ria %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", &endereco);//Variavel endere�o ter� o n�mero de endere�o da memoria escolhida 
			read(i, a, n, endereco, cache, memoria, status);	
		}
		
		if(menu == 2){
			for (i = 0; i < n; ++i){
			scanf("%d", cache[i]);
		}
		}
		if(menu == 3){
			listingCache(i,n, cache);
		}
		if(menu == 4){
			listingMemory(i, n, memoria);
		}
	}

	free (cache);
	free (memoria);
	free (status);
    return 0;
}
