#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n, long int *c, long int *t, double *tempo);
void combSort(int *v, int n, long int *c, long int *t, double *tempo);
void insertionSort(int *v, int n, long int *c, long int *t, double *tempo);
void selectionSort(int *v, int n, long int *c, long int *t, double *tempo);

void invocaMerge(int *v, int p, int r, long int *c, long int *t);
void mergeSort(int *v, int p, int r, long int *c, long int *t, double *tempo);
void intercala(int *v, int p, int q, int r, long int *c, long int *t);

void invocaQuick(int *v, int p, int r, long int *c, long int *t);
void quickSort(int *v, int p, int r, long int *c, long int *t, double *tempo);
int particionaQuick(int *v, int p, int r, long int *c, long int *t);

void invocaDualPivot(int *v, int p, int r, long int *c, long int *t, double *tempo);
void dualPivotQuick(int *v, int p, int r, long int *c, long int *t);
int particionaDualPivot(int *vetor, int menor, int maior, int *pivoEsquerdo, long int *c, long int *t);
int comparaDualPivot(int v, int p, long int *c);

void heapSort(int *vetor, int p, int n, long int *comp, long int *troca, double *tempo);