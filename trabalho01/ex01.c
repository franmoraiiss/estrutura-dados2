#include <stdio.h>

int t = 0, c = 0;

int menor(int a, int b) {
   c++;
   return (a < b);
}

void leVetor(int *v, int n) {
   for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
}

void insertionSort(int *v, int n) {
   int aux;
   for(int i = 1; i < n; i++) {
      for(int j = i; j > 0 && menor(v[j], v[j-1]); j--) {
         aux = v[j];
         v[j] = v[j-1];
         v[j-1] = aux;
         t++;
      }
   }
}

int main() {

   int n;
   scanf("%d", &n);

   int v[n];
   leVetor(v, n);

   insertionSort(v, n);
   printf("%d %d", c, t);

   return 0;
}