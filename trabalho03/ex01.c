#include <stdio.h>
#include <stdlib.h>

int c = 0, t = 0;

void leVetor(int *vetor, int n);
void mergeSort(int *vetor, int start, int end);
void intercala(int *vetor, int start, int q, int end);

int main() {

   int n;
   scanf("%d", &n);

   int *vetor;
   vetor = (int*) malloc(n * sizeof(int));

   leVetor(vetor, n);
   mergeSort(vetor, 0, n);

   printf("%d %d", c, t);

   free(vetor);
}

void leVetor(int *vetor, int n) {
   for(int i = 0; i < n; i++) {
      scanf("%d", &vetor[i]);
   }
}

void mergeSort(int *vetor, int start, int end) {
   if(start < end - 1) {
      int q = (start + end) / 2;

      mergeSort(vetor, start, q);
      mergeSort(vetor, q, end);
      intercala(vetor, start, q, end);
   }
}

void intercala(int *vetor, int start, int q, int end) {
   int i, j, k;
   int *vetor_aux;

   vetor_aux = (int*) malloc((end - start) * sizeof(int));
   i = start;
   j = q;
   k = 0;

   while(i < q && j < end) {
      c++;
      if(vetor[i] <= vetor[j]) {
         t++;
         vetor_aux[k++] = vetor[i++];
      } else {
         t++;
         vetor_aux[k++] = vetor[j++];
      }
   }

   while(i < q) {
      t++;
      vetor_aux[k++] = vetor[i++];
   }

   while(j < end) {
      t++;
      vetor_aux[k++] = vetor[j++];
   }

   for(i = start; i < end; i++) {
      t++;
      vetor[i] = vetor_aux[i - start];
   }

    free(vetor_aux);
}