#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"

double media(double *v, int n);
clock_t start_t, end_t, total_t, t;

int main() {

	FILE *f = NULL;
	char *nomeArquivo = "vetor5-caso4.txt";

	f = fopen(nomeArquivo, "r+");
	if (f == NULL) {
		exit(1);
	}

	//Verificar quantidade de elementos no arquivo
	int numeroElementos = 0;
	int tmp; 

	fscanf(f, "%d", &tmp);
	while(!feof(f)) {
	fscanf(f, "%d", &tmp);
	numeroElementos++;
	}
	fclose(f);

	// Criação dos vetores
	int *vetorBubble = NULL;
	int *vetorComb = NULL;
	int *vetorInsertion = NULL;
	int *vetorSelection = NULL;
	int *vetorMerge = NULL;
	int *vetorQuick = NULL;
	int *vetorDualPivot = NULL;
	int *vetorHeap = NULL;

	vetorBubble = (int *) malloc(numeroElementos * sizeof(int));
	vetorComb = (int *) malloc(numeroElementos * sizeof(int));
	vetorInsertion = (int *) malloc(numeroElementos * sizeof(int));
	vetorSelection = (int *) malloc(numeroElementos * sizeof(int));
	vetorMerge = (int *) malloc(numeroElementos * sizeof(int));
	vetorQuick = (int *) malloc((numeroElementos + 100000) * sizeof(int));
	vetorDualPivot = (int *) malloc(numeroElementos * sizeof(int));
	vetorHeap = (int *) malloc(numeroElementos * sizeof(int));
    
	if(vetorBubble == NULL) exit(1);
	if(vetorComb == NULL) exit(1);
	if(vetorInsertion == NULL) exit(1);
	if(vetorSelection == NULL) exit(1);
	if(vetorMerge == NULL) exit(1);
	if(vetorQuick == NULL) exit(1);
	if(vetorDualPivot == NULL) exit(1);
	if(vetorHeap == NULL) exit(1);

	//Salva os elementos do arquivo no primeiro vetor
	f = fopen(nomeArquivo, "r+");

	int elemento;
	int posicaoVetor = 0;
	fscanf(f, " %d", &elemento);
   	while(!feof(f)) {
    	vetorBubble[posicaoVetor] = elemento;
    	posicaoVetor++;
    	fscanf(f, " %d", &elemento);
	}
	fclose(f);


	//Copiamos o conteúdo do arquivo para todos os vetores
	for(int i = 0; i < numeroElementos; i++) {
		vetorComb[i] = vetorBubble[i];
	}

    for(int i = 0; i < numeroElementos; i++) {
		vetorInsertion[i] = vetorBubble[i];
	}
    
	for(int i = 0; i < numeroElementos; i++) {
		vetorSelection[i] = vetorBubble[i];
	}

    for(int i = 0; i < numeroElementos; i++) {
		vetorMerge[i] = vetorBubble[i];
	}

    for(int i = 0; i < numeroElementos; i++) {
		vetorQuick[i] = vetorBubble[i];
	}

	for(int i = 0; i < numeroElementos; i++) {
		vetorDualPivot[i] = vetorBubble[i];
	}

	for(int i = 0; i < numeroElementos; i++) {
		vetorHeap[i] = vetorBubble[i];
	}


	// Inicia cada função de ordenação com seu respectivo vetor
	// e retorna o resultado das comparações
	long int comparacoes = 0;
	long int trocas = 0;

	// Cria um vetor auxiliar para voltar o vetor a sua posição original. Assim, 
	// após a ordenação, é possível refazer o processo para realizar o cálculo de média de tempo
	int *vaux = (int *) malloc(numeroElementos * sizeof(int));
	

	// ==================================================================================
  	// ================================ BUBBLE SORT =====================================
	// Esse vetor guardará o valor original de cada vetor (bubble, sort, etc.)
	// para conseguirmos executar 5 vezes e realizar a média do tempo.
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorBubble[i];
	}

	double mediaTempoBubble[5];
	printf("\n----- BUBBLE SORT -----\n");	
	for(int i = 0; i < 5; i++) {
		
		bubbleSort(vetorBubble, numeroElementos, &comparacoes, &trocas, &mediaTempoBubble[i]);
		
		// Faz a cópia do vetor vaux (original) para o bubble realizar a ordenação novamente
		for(int i = 0; i < numeroElementos; i++) {
			vetorBubble[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo Bubble: %lfs\n", media(mediaTempoBubble, 5));
	//Reseta o valor delas para contar novamente no próximo tipo de ordenação	
	comparacoes = 0;
	trocas = 0;
	printf("\n");


	// ==================================================================================
  	// =================================== COMBSORT =====================================
	double mediaTempoComb[5];
  	printf("\n----- COMB SORT -----\n");
	for(int i = 0; i < 5; i++) {
		
		combSort(vetorComb, numeroElementos, &comparacoes, &trocas, &mediaTempoComb[i]);

		// Faz a cópia do vetor vaux (original) para o bubble realizar a ordenação novamente
		for(int i = 0; i < numeroElementos; i++) {
			vetorComb[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaTempoComb, 5));
	comparacoes = 0;
	trocas = 0;
	printf("\n");


	// ==================================================================================
	// ===================================== INSERTION ==================================
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorInsertion[i];
	}

	double mediaTempoInsertion[5];
	printf("\n----- INSERTION SORT -----\n");
	for(int i = 0; i < 5; i++) {

		insertionSort(vetorInsertion, numeroElementos, &comparacoes, &trocas, &mediaTempoInsertion[i]);

		for(int i = 0; i < numeroElementos; i++) {
			vetorInsertion[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaTempoInsertion, 5));
	comparacoes = 0;
	trocas = 0;
	printf("\n");


	// ==================================================================================
	// ===================================== SELECTION ==================================
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorSelection[i];
	}

	double mediaTempoSelection[5];
	printf("\n----- SELECTION SORT -----\n");
	for(int i = 0; i < 5; i++) {

		selectionSort(vetorSelection, numeroElementos, &comparacoes, &trocas, &mediaTempoSelection[i]);

		for(int i = 0; i < numeroElementos; i++) {
			vetorSelection[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaTempoSelection, 5));
	comparacoes = 0;
	trocas = 0;
	printf("\n");


	// ===================================================================================
	// ===================================== MERGE SORT ==================================
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorMerge[i];
	}

	double mediaTempoMerge[5];
	printf("\n----- Merge SORT -----\n");
	for(int i = 0; i < 5; i++) {
		
		mergeSort(vetorMerge, 0, numeroElementos, &comparacoes, &trocas, &mediaTempoMerge[i]);

		for(int i = 0; i < numeroElementos; i++) {
			vetorMerge[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaTempoMerge, 5));
	comparacoes = 0;
	trocas = 0;
	printf("\n");


	// ==================================================================================
	// ===================================== QUICK SORT ==================================
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorQuick[i];
	}

	double mediaTempoQuick[5];
	printf("\n----- QUICK SORT -----\n");

	for(int i = 0; i < 5; i++) {
		
		quickSort(vetorQuick, 0, numeroElementos - 1, &comparacoes, &trocas, &mediaTempoQuick[i]);

		for(int i = 0; i < numeroElementos; i++) {
			vetorQuick[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaTempoQuick, 5));
	comparacoes = 0;
	trocas = 0;
	printf("\n");


	// ==================================================================================
	// ================================== DUAL PIVOT QUICK ==============================
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorDualPivot[i];
	}

	double mediaDualPivot[5];
	printf("\n----- DUAL-PIVOT QUICK SORT -----\n");
	for(int i = 0; i < 5; i++) {
		
		invocaDualPivot(vetorDualPivot, 0, numeroElementos - 1, &comparacoes, &trocas, &mediaDualPivot[i]);

		for(int i = 0; i < numeroElementos; i++) {
			vetorDualPivot[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaDualPivot, 5));
	comparacoes = 0;
	trocas = 0;
	printf("\n");

	
	// ==================================================================================
	// ===================================== HEAP SORT ==================================
	for(int i = 0; i < numeroElementos; i++) {
		vaux[i] = vetorHeap[i];
	}
	
	double mediaHeapSort[5];
	printf("\n----- HEAP SORT -----\n");
	for(int i = 0; i < 5; i++) {
		
		heapSort(vetorHeap, 0, numeroElementos, &comparacoes, &trocas, &mediaHeapSort[i]);

		for(int i = 0; i < numeroElementos; i++) {
			vetorHeap[i] = vaux[i];
		}

		comparacoes = 0;
		trocas = 0;
	}
	printf("\n> Média tempo: %lfs\n", media(mediaHeapSort, 5));

	printf("\n");
	free(vetorBubble);
	free(vetorComb);
	free(vetorInsertion);
	free(vetorSelection);
	free(vetorMerge);
	free(vetorQuick);
	free(vetorDualPivot);
	free(vetorHeap);

	free(vaux);

   return 0;
}

double media(double *v, int n) {
	double soma = 0;
	
	for(int i = 0; i < n; i++) {
		soma = soma + v[i];
	}

	return soma / n;
}