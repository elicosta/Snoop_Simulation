#include <stdio.h>
#include <stdlib.h>

void read(){
}

void write(){
}

int main(void)
{	
	/**struct Cache{
		char status;
		int *cache;
	} **/
	
	int *memoria, *cache; 
	int n, i, menu;
	char Status_Cache; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inválido
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	cache = malloc (n * sizeof (int));
	memoria = malloc (n * sizeof (int));
	while(menu != 0){
		printf("Quais opções você deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDEREÇOS DA CACHE\n4 - LISTAR ENDEREÇOS DA MEMÓRIA\n0 - SAIR\n");
		scanf("%d", &menu);
		if(menu == 1){
			for (i = 0; i < n; ++i){
			printf("%d\n", cache[i]);
		}
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
    return 0;
}
