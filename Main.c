#include <stdio.h>
#include <stdlib.h>

void read(){
}

void write(){
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
			
			printf("Qual endereço de memória será lido?\n");
			for (i = 0; i < n; ++i){
			printf("Memória %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", endereco);
			printf("Qual cache será usado pelo endereço de memória?\n");
			for (i = 0; i < n; ++i){
			scanf("cache%d", i);
			}
			scanf("%d", i);
		}
		
		if(menu == 2){
			for (i = 0; i < n; ++i){
			scanf("%d", cache[i]);
		}
		}
		if(menu == 3){
			for (i = 0; i < n; ++i){
			printf("Cache %d: %d\n", i, &cache[i]);
			}
		}
		if(menu == 4){
			for (i = 0; i < n; ++i){
			printf("Memória %d: %d\n", i, &memoria[i]);
			}
		}
	}

	free (cache);
	free (memoria);
	free (status);
    return 0;
}
