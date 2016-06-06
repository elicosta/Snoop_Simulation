#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdint.h>
#include <time.h>

void view(int i, int n, int cache[], int memoria[], char status[]){
	system("cls");
	printf("#############################################\n");
	for(i = 0; i < 10; ++i){		
		printf("Memória %d: %d ", i, memoria[i]);
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
			if(endereco[i] == endereco[a] && cache[a] != memoria[b] && status[a] == 'S'){
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
	char *status; // M - Modificado, E - Exclusivo, S - Compartilhado, I - Inválido
	
	//Quantos cache possuirá o sistema, de acordo com o usuário final 
	printf("#############################################\n");
	printf("#           Cache Memory Snooping           #\n");
	printf("#############################################\n");
	printf("Quantas cache?\n");
	scanf ("%d", &n);
	menu = 100;
	
	//Criaçao da Memória, Cache e Status da Cache em vetores de alocação dinâmica
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
		printf("Quais opções você deseja?\n");
		printf("1 - LEITURA\n2 - ESCRITA\n3 - LISTAR ENDEREÇOS DA CACHE\n4 - LISTAR ENDEREÇOS DA MEMÓRIA\n0 - SAIR\n");
		scanf("%d", &menu);
		//Leitura da memória para a cache que o usuário irá determinar
		if(menu == 1){
			system("cls");
			printf("Qual cache será usado pelo endereço de memória?\n");
			for (i = 0; i < n; ++i){
			printf("cache %d\n", i);
			}
			scanf("%d", &a); //Váriavel a terá o número de qual cache escolhida
			printf("Qual memória será lida?\n");
			for (i = 0; i < 10; ++i){
			printf("Memória %d: %d\n", i, &memoria[i]);
			}
			scanf("%d", &b); //Variavel endereço terá o número de memória escolhida
			endereco[a] = (uintptr_t)&memoria[b]; // endereco da memória ficará em um vetor endereços para ser realizado a verificação de status
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
