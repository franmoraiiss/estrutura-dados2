#include <stdio.h>

long int c, t;

void leVetor(int *v, int n) {
   for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
}

void bubbleSort(int *v, int n) {
   int i, j, aux;

   for(i = 0; i < n - 1; i++) {
      for(j = n - 1; j > i; j--) {
         c++;
         if(v[j] < v[j-1]){
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            t++;
         }
      }
   }
}

int main() {

   int n;
   scanf("%d", &n);

   int v[n];

   leVetor(v, n);
   bubbleSort(v, n);

   printf("%ld %ld", c, t);

   return 0;
}