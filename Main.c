#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int *v, *mem; 
	int n, i;
	char M, E, S, I; // M - Modificado, E - Exclusivo, S - Compartilahdo, I - Inválido
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	v = malloc (n * sizeof (int));
	mem = malloc (n * sizeof (int));
	for (i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	for (i = 0; i < n; ++i){
		printf("%d ", &v[i]);
	}
	
	free (v);
    return 0;
}
