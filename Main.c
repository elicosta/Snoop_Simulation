#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void view(int i, int n, int cache[], int memoria[], char status[]){
	printf("#############################################\n");
	printf("Cache      Status da cache Memória\n");
	for (i = 0; i < n; ++i){		
		printf("Cache %d: %d ", i, cache[i]);		
		printf("Status %d: %c ", i, status[i]);
		printf("    Memória %d: %d\n", i, memoria[i]);
	}
	printf("#############################################\n");	
}

void read(int i, int a, int n, int endereco, int cache[], int memoria[], char status[]){
	for (i = 0; i < n; ++i){
		if(endereco == (int)&memoria[i]){
			cache[a] = memoria[i];
			
			
			//view(i, n, cache, memoria, status);//Exibe toda atividade após a leitura na memória
			
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
	printf("Memória %d: %d\n", i, &memoria[i]);
	}
}

int main(void)
{
	setlocale(LC_ALL, "Portuguese"); //Uso de caracteres especiais
	int endereco, a;
	int *memoria, *cache;
	int n, i, menu;
	char *status; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inválido
	
	//Quantos cache possuirá o sistema, de acordo com o usuário final 
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	menu = 100;
	
	//Criaçao da Memória, Cache e Status da Cache em vetores de alocação dinâmica
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
		printf("Quais opções você deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDEREÇOS DA CACHE\n4 - LISTAR ENDEREÇOS DA MEMÓRIA\n0 - SAIR\n");
		scanf("%d", &menu);
		//Leitura da memória para a cache que o usuário irá determinar
		if(menu == 1){
			printf("Qual cache será usado pelo endereço de memória?\n");
			for (i = 0; i < n; ++i){
			printf("cache %d\n", i);
			}
			scanf("%d", &a); //Váriavel a terá o número de qual cache escolhida
			printf("Qual endereço de memória será lido?\n");
			for (i = 0; i < n; ++i){
			printf("Memória %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", &endereco);//Variavel endereço terá o número de endereço da memoria escolhida 
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
