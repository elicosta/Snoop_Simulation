#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdint.h>
#include <time.h>

void view(int i, int n, int cache[], int memoria[], char status[]){
	system("cls");
	printf("#############################################\n");
	for(i = 0; i < 10; ++i){		
		printf("Mem�ria %d: %d ", i, memoria[i]);
		if(i == 4){
				printf("\n");	
			}
	}
	printf("\n#############################################\n");
	printf("Cache      Status da cache\n");
	for (i = 0; i < n; ++i){		
		printf("Cache %d: %d ", i, cache[i]);		
		printf("Status %d: %c\n", i, status[i]);
	}
	printf("#############################################\n");	
}

void verify(int i, int a, int b, int n, int endereco[], int cache[], int memoria[], char status[]){
	for (i = 0; i < n; ++i){
		if(a != i){
			if(endereco[i] == endereco[a] && cache[a] == memoria[b]){
				status[a] = 'S';
				status[i] = 'S';
			}
			if(endereco[i] == endereco[a] && cache[a] != memoria[b]){
				status[a] = 'M';
			}
			//if(endereco[i] != endereco[a] && cache[a] != memoria[b] ){
			//	status[a] = 'E';
			//	status[i] = 'E';
			//}
			//else{
			//	status[a] = 'I';	
			//}
		}
	}
}

void read(int i, int a, int b, int n, int endereco[], int cache[], int memoria[], char status[]){
	for (i = 0; i < n; ++i){		
		if(endereco[a] == (uintptr_t)&memoria[i]){
			cache[a] = memoria[i];
		}		
	}
	verify(i, a, b, n, endereco, cache, memoria, status);
	view(i, n, cache, memoria, status);	
}
	

void write(int i, int a, int n, int endereco[], int cache[], int memoria[], char status[]){
		
}

int main(void)
{
	setlocale(LC_ALL, "Portuguese"); //Uso de caracteres especiais
	int a, b, n, i, menu, memoria[10];
	int *cache, *endereco;
	char *status; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inv�lido
	
	//Quantos cache possuir� o sistema, de acordo com o usu�rio final 
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	menu = 100;
	
	//Cria�ao da Mem�ria, Cache e Status da Cache em vetores de aloca��o din�mica
	for (i = 0; i < 10; ++i){
		memoria[i] = rand() % 100;
	}
	cache = malloc (n * sizeof (int));
	endereco = malloc (n * sizeof (int));
	status =  malloc (n * sizeof (int));
	srand(time(NULL));
	for (i = 0; i < n; ++i){
		status[i] = 'E';
		cache[i] = 0;
		endereco[i] = 0;
	}
	
	//menu principal do sistema
	while(menu != 0){
		printf("Quais op��es voc� deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDERE�OS DA CACHE\n4 - LISTAR ENDERE�OS DA MEM�RIA\n0 - SAIR\n");
		scanf("%d", &menu);
		//Leitura da mem�ria para a cache que o usu�rio ir� determinar
		if(menu == 1){
			system("cls");
			printf("Qual cache ser� usado pelo endere�o de mem�ria?\n");
			for (i = 0; i < n; ++i){
			printf("cache %d\n", i);
			}
			scanf("%d", &a); //V�riavel a ter� o n�mero de qual cache escolhida
			printf("Qual mem�ria ser� lida?\n");
			for (i = 0; i < 10; ++i){
			printf("Mem�ria %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", &b); //Variavel endere�o ter� o n�mero de mem�ria escolhida
			endereco[a] = (uintptr_t)&memoria[b]; // endereco da mem�ria ficar� em um vetor endere�os para ser realizado a verifica��o de status
			read(i, a, b, n, endereco, cache, memoria, status);	
		}
		
		if(menu == 2){
			system("cls");
		}
		if(menu == 3){
			system("cls");
			//verify(i, a, b, n, endereco, cache, memoria, status);
			//view(i, n, cache, memoria, status);	
		}
		if(menu == 4){
			system("cls");
		}
	}

	free (cache);
	free (endereco);
	free (status);
    return 0;
}
