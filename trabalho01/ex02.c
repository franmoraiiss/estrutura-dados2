#include <stdio.h>

void leVetor(int *v, int n);
void selectionSort(int *v, int n);

int menor(int a, int b);
void swap(int *v, int i, int j);

int t = 0, c = 0;

int main() {

   int n;
   scanf("%d", &n);

   int v[n];
   leVetor(v, n);

   selectionSort(v, n);
   printf("%d %d", c, t);

   return 0;
}

void selectionSort(int *v, int n) {
   int min;
   
   for(int i = 0; i < n - 1; i++) {
      min = i;
      for(int j = i + 1; j < n; j++) {
         if(menor(v[j], v[min]))
            min = j;
      }
      
      swap(v, i, min);
   }
}

void leVetor(int *v, int n) {
   for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
}

void swap(int *v, int i, int j) {
   int aux;

   aux = v[i];
   v[i] = v[j];
   v[j] = aux;

   t++;
}

int menor(int a, int b) {
   c++;
   return (a < b);
}