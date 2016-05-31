#include <stdio.h>
#include <stdlib.h>

void read(int a, int n, int endereco, int cache[], int memoria[]){
	int i;
	for (i = 0; i < n; ++i){
		if(endereco == &memoria[i]){
			cache[a] = memoria[i];
			system("cls");
			printf("endereco: %d\n", endereco);
			printf("cache: %d\n", a);
			printf("enderecomemory: %d\n", &memoria[i]);
			printf("enderecache: %d\n", &cache[i]);
			}
		//else{
		//	printf("invalido");}	
	}
		
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
	int endereco, a;
	int *memoria, *cache;
	int n, i, menu;
	char *status; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inválido
	
	
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	menu = 100;
	
	
	cache = malloc (n * sizeof (int));
	memoria = malloc (n * sizeof (int));
	status =  malloc (n * sizeof (int));
	srand(time(NULL));
	for (i = 0; i < n; ++i){
		status[i] = 'E';
		cache[i] = 0;
		memoria[i] = rand() % 100;
	}
	
	
	while(menu != 0){
		printf("Quais opções você deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDEREÇOS DA CACHE\n4 - LISTAR ENDEREÇOS DA MEMÓRIA\n0 - SAIR\n");
		scanf("%d", &menu);
		if(menu == 1){
			printf("Qual cache será usado pelo endereço de memória?\n");
			for (i = 0; i < n; ++i){
			printf("cache %d\n", i);
			}
			scanf("%d", &a);
			printf("Qual endereço de memória será lido?\n");
			for (i = 0; i < n; ++i){
			printf("Memória %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", &endereco);
			read(a, n, endereco, cache, memoria);	
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
