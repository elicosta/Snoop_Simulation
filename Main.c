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

void verify(int i, int a, int n, int cache[], int memoria[], char status[]){
	for (i = 0; i < n; ++i){
		if(cache[i] != cache[a] && a!= i){
			status[a] = 'E';
			status[i]= 'E';	
		}
		if(cache[i] == cache[a] && a != i && a != 0){
			status[a] = 'S';
			status[i]= 'S';			 
		}
		//else{
		//	status[a] = 'I';
		//}
	}
}

void read(int i, int a, int n, int endereco, int cache[], int memoria[], char status[]){
	for (i = 0; i < n; ++i){		
		if(endereco == (int)&memoria[i]){
			cache[a] = memoria[i];
		}		
	}
	verify(i, a, n, cache, memoria, status);
	view(i, n, cache, memoria, status);	
}
	

void write(int i, int a, int n, int endereco, int cache[], int memoria[], char status[]){
	printf("qual valor deseja armazenar na cache %d", a);
	scanf("%d", cache[a]);
	status[a] = 'M';
	printf("Deseja armazenar linha da cache na mem�ria selecionada?");
	printf("0 - SIM        1  - N�O");
	scanf("%d", &i);
	if(i == 0){
		for (i = 0; i < n; ++i){
			if(endereco == (int)&memoria[i]){
				memoria[i] = cache[a];				
			}
			if(cache[i] == cache[a] && a != i){
			status[a] = 'S';
			status[i]= 'S';			 
			}
			if(cache[i] != cache[a] && a!= i){
				status[a] = 'E';
				status[i]= 'E';	
			}
		}
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
			printf("Qual cache ser� usada para escrita?\n");
			for (i = 0; i < n; ++i){
			printf("cache %d\n", i);
			}
			scanf("%d", &a); //V�riavel a ter� o n�mero de qual cache escolhida
			printf("Qual endere�o de mem�ria ser� armazenizado a linha de cache?\n");
			for (i = 0; i < n; ++i){
			printf("Mem�ria %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", &endereco);
		}
		if(menu == 3){
		}
		if(menu == 4){
		}
	}

	free (cache);
	free (memoria);
	free (status);
    return 0;
}
