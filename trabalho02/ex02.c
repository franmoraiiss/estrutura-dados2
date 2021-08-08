#include <stdio.h>
#include <stdlib.h>

int c, t;

void leVetor(int *v, int n) {
   for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
}

void smartBubbleSort(int *v, int n) {
   int aux;

   for(int i = 0; i < n - 1; i++) {

      int trocou = 0;
      for(int j = n - 1; j > i; j--) {
         c++;
         if(v[j] > v[j-1]){
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            t++;

            trocou = 1;
         }
      }

      if(trocou == 0) {
         break;
      }

      trocou = 0;
   }
}

int main() {

   int n;
   scanf("%d", &n);

   int *v;
   v = (int *) malloc(n * sizeof(int));

   leVetor(v, n);
   smartBubbleSort(v, n);

   for(int i = 0; i < n; i++) {
      printf("%d ", v[i]);
   }

   printf("\n%d %d", c, t);
   free(v);
   return 0;
}