#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int *v, *mem; 
	int n, i;
	char Status_Cache, EXIT; // M - Modificado, E - Exclusivo, S - Compartilahdo, I - Inválido, EXIT - SAIR
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	v = malloc (n * sizeof (int));
	mem = malloc (n * sizeof (int));
	while(EXIT == 0){	
		for (i = 0; i < n; ++i){
			scanf("%d", &v[i]);
		}
		for (i = 0; i < n; ++i){
			printf("%d ", v[i]);
		}
		printf("\nDeseja realizar mais um comando?\n 0 - SIM                   1 - NÃO\n");
		scanf("%d", &EXIT);
	}
	free (v);
    return 0;
}
