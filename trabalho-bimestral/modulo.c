#include "modulo.h"
#include <time.h>

clock_t start_t, end_t, total_t, t;

// >> START BUBBLESORT
void bubbleSort(int *v, int n, long int *c, long int *t, double *tempo) {
    int i, j, aux;
	
    clock_t begin = clock();

	for(i = 0; i < n - 1; i++) {
		for(j = n - 1; j > i; j--) {
			
			(*c)++;
			if(v[j] < v[j-1]){
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				(*t)++;
			}

		}
	}

    clock_t end = clock();

    double elapsedb = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedb;

    printf("\nTempo: %lfs", elapsedb);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));
}
// >> END BUBBLESORT

// >> START COMBSORT
void combSort(int *v, int n, long int *c, long int *t, double *tempo) {

	int step = n;
	int i, j, k, again = 1;

    clock_t begin = clock();

	//Fase 1
	while((step = (step / 1.3 )) > 1) {
		for(j = 0; j < n - step; j++){
			k = j + step;
			(*c)++;

			if(v[j] > v[k]) {
				int aux = v[j];
				v[j] = v[k];
				v[k] = aux; 
				(*t)++;
			}
		}
	}

	//Fase 2
	for(i = 0; i < n - 1 && again == 1; i++){
		again = 0;
		for(j = n - 1; j > i; j--){
			(*c)++;
			if(v[j] < v[j-1]) {
				(*t)++;
				int aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				again = 1;
			}
		}
	}

    clock_t end = clock();

    double elapsedc = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedc;

    printf("\nTempo: %lfs", elapsedc);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));

}
// >> END COMBSORT

// >> START INSERTION SORT
int qtd_compInsertion(int y, int z, long int *c) {
    (*c)++;
    return (y < z);
}

void insertionSort(int *v, int n, long int *c, long int *t, double *tempo) {
    int i, j, key;

    clock_t begin = clock();
    int aux;
	for(int i = 1; i < n; i++) {
		for(int j = i; j > 0 && qtd_compInsertion(v[j], v[j-1], c); j--) {
			aux = v[j];
			v[j] = v[j-1];
			v[j-1] = aux;
			(*t)++;
		}
	}

    clock_t end = clock();
    double elapsedi = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedi;

    printf("\nTempo: %lfs", elapsedi);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));
}
// >> END INSERTION SORT

// >> START SELECTION SORT
int qtd_compSelection(int y, int z, long int *c) {
    (*c)++;
    return (y < z);
}

void selectionSort(int *v, int n, long int *c, long int *t, double *tempo) {

	int min;
    clock_t begin = clock();
	
	for(int i = 0; i < n - 1; i++) {
		min = i;
		for(int j = i + 1; j < n; j++) {
			if(qtd_compSelection(v[j], v[min], c))
				min = j;
		}
		
		int aux = v[i];
		v[i] = v[min];
		v[min] = aux;
		(*t)++;
	}

    clock_t end = clock();
    double elapseds = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapseds;

    printf("\nTempo: %lfs", elapseds);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));
}

// >> END SELECTION SORT

// >> START MERGE SORT
void intercala(int *v, int p, int q, int r, long int *c, long int *t) {
    int i, j, k; // Contadores
    int *vetor_aux; // Vetor Auxiliar

	vetor_aux = (int *) malloc((r - p) * sizeof(int));

    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        (*c)++;

        if (v[i] <= v[j]) {
            (*t)++;
            vetor_aux[k++] = v[i++];
        } else {
            (*t)++;
            vetor_aux[k++] = v[j++];
        }
    }

    while (i < q) {
        (*t)++;
        vetor_aux[k++] = v[i++];
    }

    while (j < r) {
        (*t)++;
        vetor_aux[k++] = v[j++];
    }

    for (i = p; i < r; i++) {
        (*t)++;
        v[i] = vetor_aux[i - p];
    }

    free(vetor_aux);
}

void mergeSort(int *v, int p, int r, long int *c, long int *t, double *tempo) {

	clock_t begin = clock();
	invocaMerge(v, p, r, c, t);
    clock_t end = clock();

    double elapsedm = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedm;

    printf("\nTempo: %lfs", elapsedm);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));
}

void invocaMerge(int *v, int p, int r, long int *c, long int *t) {
    if (p < r - 1) {
        int q = (p + r) / 2;

        invocaMerge(v, p, q, c, t);
        invocaMerge(v, q, r, c, t);
        intercala(v, p, q, r, c, t);
    }
}
// >> END MERGE SORT

// >> START QUICK SORT 
int particionaQuick(int *v, int p, int r, long int *c, long int *t) {
   	int i = p - 1, j = r + 1, piv = v[p];   

	while(1) {
		do {
			(*c)++;
			i++;
		} while(v[i] < piv);

		do {
			(*c)++;
			j--;
		} while(v[j] > piv);

		if(i >= j) {
			break;
		}

		int aux = v[i];
		v[i] = v[j];
		v[j] = aux;
		(*t)++;
	}

	return j;
}

void quickSort(int *v, int p, int r, long int *c, long int *t, double *tempo) {
   	
	clock_t begin = clock();
	invocaQuick(v, p, r, c, t);
    clock_t end = clock();
	
    double elapsedm = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedm;

    printf("\nTempo: %lfs", elapsedm);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));
}

void invocaQuick(int *v, int p, int r, long int *c, long int *t) {
	int q;

	if(p < r) {
		q = particionaQuick(v, p, r, c, t);
		invocaQuick(v, p, q, c, t);
		invocaQuick(v, q + 1, r, c, t);
	}
}
// >> END QUICK SORT 


// >> START DUAL PIVOT QUICK SORT
void dualPivotQuick(int *v, int p, int r, long int *c, long int *t) {

	if(p < r){
        int pivoEsquerdo, pivoDireito;

        pivoDireito = particionaDualPivot(v, p, r, &pivoEsquerdo, c, t);
        dualPivotQuick(v, p, pivoEsquerdo - 1, c, t);
        dualPivotQuick(v, pivoEsquerdo + 1, pivoDireito - 1, c, t);
        dualPivotQuick(v, pivoDireito + 1, r, c, t);
    }
}

int comparaDualPivot(int v, int p, long int *c) {
	(*c)++;
	return v >= p;
}

int particionaDualPivot(int *vetor, int menor, int maior, int *pivoEsquerdo, long int *c, long int *t){
    
	(*c)++;
	if(vetor[menor] > vetor[maior]){
		
		(*t)++;
		int aux = vetor[menor];
		vetor[menor] = vetor[maior];
		vetor[maior] = aux;
    }

    int j = menor + 1;
    int g = maior - 1;
    int k = menor + 1;
    int p = vetor[menor];
    int q = vetor[maior];

    while(k <= g){

		(*c)++;
        if(vetor[k] < p){
			(*t)++;
			int aux = vetor[k];
			vetor[k] = vetor[j];
			vetor[j] = aux;

            j++;
        } else if(comparaDualPivot(vetor[k], q, c)){
            while(vetor[g] > q && k < g){
                g--;
            }

			(*t)++;
			int aux = vetor[k];
			vetor[k] = vetor[g];
			vetor[g] = aux;
            
            g--;
			
			(*c)++;
            if(vetor[k] < p){

				(*t)++;
				int aux = vetor[k];
				vetor[k] = vetor[j];
				vetor[k] = aux;

                j++;
            }
        }
        k++;
    }
    j--;
    g++;

	(*t)++;
	int aux = vetor[menor];
	vetor[menor] = vetor[j];
	vetor[j] = aux;

	(*t)++;
	aux = vetor[maior];
	vetor[maior] = vetor[g];
	vetor[g] = aux;

    *pivoEsquerdo = j;

    return g;
}

void invocaDualPivot(int *v, int p, int r, long int *c, long int *t, double *tempo) {

	clock_t begin = clock();
	dualPivotQuick(v, p, r, c, t);
    clock_t end = clock();
	
    double elapsedm = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedm;
    printf("\nTempo: %lfs", elapsedm);
    printf("\nC -> %ld / T -> %ld", (*c), (*t));

}
// >> END DUAL PIVOT QUICK SORT

//START HEAP SORT
void heapSort(int *vetor, int p, int n, long int *comp, long int *troca, double *tempo) {	
	
	clock_t begin = clock();

	int i, j, c, raiz, aux;
    for (i = 1; i < n; i++){
        c = i;
        do {
            raiz = (c - 1) / 2;             
            if (vetor[raiz] < vetor[c]) 
            {
                aux = vetor[raiz];
                vetor[raiz] = vetor[c];
                vetor[c] = aux;
            }
            c = raiz;
        } while (c != 0);
    }

    for (j = n - 1; j >= 0; j--){

        aux = vetor[0];
        vetor[0] = vetor[j];    
        vetor[j] = aux;
        (*troca)++;
        raiz = 0;

        do{
            c = 2 * raiz + 1;   
            (*comp)++;
            if ((vetor[c] < vetor[c + 1]) && c < j-1){
                c++;
            }

            (*comp)++;
            if (vetor[raiz]<vetor[c] && c<j){
                aux = vetor[raiz];
                vetor[raiz] = vetor[c];
                vetor[c] = aux;

                (*troca)++;
            }
            raiz = c;
        } while (c < j);
    } 	
    
    clock_t end = clock();
    double elapsedm = (double)(end - begin) / CLOCKS_PER_SEC;
    *tempo = elapsedm;

	printf("\nTempo: %lfs", elapsedm);
    printf("\nC -> %ld / T -> %ld", (*comp), (*troca));
}