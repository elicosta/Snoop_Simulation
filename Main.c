#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int *cache, *memoria; 
	int n, i;
	char M, E, S, I; // M - Modificado, E - Exclusivo, S - Compartilahdo, I - Inválido
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	cache = malloc (n * sizeof (int));
	memoria = malloc (n * sizeof (int));
	for (i = 0; i < n; ++i){
		scanf("%d", &cache[i]);
	}
	for (i = 0; i < n; ++i){
		printf("%d ", &cache[i]);
	}
	
	free (v);
    return 0;
}
