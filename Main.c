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
	char Status_Cache; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inv�lido
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	cache = malloc (n * sizeof (int));
	memoria = malloc (n * sizeof (int));
	while(menu != 0){
		printf("Quais op��es voc� deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDERE�OS DA CACHE\n4 - LISTAR ENDERE�OS DA MEM�RIA\n0 - SAIR\n");
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
			printf("Mem�ria %d: %d\n", i, &memoria[i]);
			}
		}
	}
	
	free (cache);
    return 0;
}
