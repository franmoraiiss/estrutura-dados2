#include <stdio.h>
#include <stdlib.h>

int comparaHoare;
int trocaHoare;

int comparaLomuto;
int trocaLomuto;

int comparaSedgewick;
int trocaSedgewick;

void leVetor(int *v, int n) { 
   for(int i = 0; i < n; i++){
      scanf("%d", &v[i]);
   }
}

// HOARE
int particaoHoare(int *v, int p, int r) {
   int i = p - 1;
   int j = r + 1;
   int piv = v[p];

   while(1) {
      do {
         comparaHoare += 1;
         i++;
      } while (v[i] < piv);

      do {
         comparaHoare += 1;
         j--;
      } while (v[j] > piv);

      if (i >= j) {
         return j;
      }

      int aux;
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;

      trocaHoare += 1;
   }
}

void quickSortHoare(int *v, int p, int r){
   int q;
   if(p < r){
      q = particaoHoare(v, p, r);
      quickSortHoare(v, p, q);
      quickSortHoare(v, q + 1, r);
   }
}

// LOMUTO
int particaoLomuto(int *v, int p, int r) {
   int i = p - 1;
   int j;
   int piv = v[r];

   for(j = p; j <= r - 1; j++){
      comparaLomuto += 1;
      if(v[j] <= piv) {
         i++;

         int aux = v[j];
         v[j] = v[i];
         v[i] = aux;

         trocaLomuto += 1;
      }
   }

   int aux = v[i+1];
   v[i+1] = v[r];
   v[r] = aux;
   trocaLomuto++;

   return i+1;
}

void quickSortLomuto(int *v, int p, int r) {
   int q;
   if(p < r) {
      q = particaoLomuto(v, p, r);
      quickSortLomuto(v, p, q-1);
      quickSortLomuto(v, q + 1, r);
   }
}

// SEDGEWICK
int comparacaoSedgewick(int a, int b) {
   comparaSedgewick += 1;

   if(a < b) {
      return 1;
   } else {
      return 0;
   }
}

int particaoSedgewick(int *v, int p, int r) {
   int i = p;
   int j = r + 1;
   int piv = v[p];

   while(1){
      
      while(comparacaoSedgewick(v[++i], piv)) {
         if(i == r) {
            break;
         }
      }
      
      while(comparacaoSedgewick(piv, v[--j])) {
         if(j == p) {
            break;
         }
      }      

      if(i >= j){
         break;
      }

      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      trocaSedgewick += 1;
   }

   int aux = v[p];
   v[p] = v[j];
   v[j] = aux;

   trocaSedgewick += 1;
   return j;
}

void quickSortSedgewick(int *v, int p, int r) {
   int q;
   if(p < r) {
      q = particaoSedgewick(v, p, r);
      quickSortSedgewick(v, p, q-1);
      quickSortSedgewick(v, q + 1, r);
   }
}

int main() {

   int *v, *x;

   int n;
   scanf("%d", &n);
   v = (int*) malloc(n * sizeof(int));
   x = (int*) malloc(n * sizeof(int));
   leVetor(v, n);

   for(int i = 0; i < n; i++){
      x[i] = v[i];
   }
   quickSortHoare(v, 0, n-1);

   for(int i = 0; i < n; i++) {
      v[i] = x[i];
   }
   quickSortLomuto(v, 0, n-1);

   for(int i = 0; i < n; i++) {
      v[i] = x[i];
   }
   quickSortSedgewick(v, 0, n-1);

   printf("%d %d\n", comparaHoare, trocaHoare);
   printf("%d %d\n", comparaLomuto, trocaLomuto);
   printf("%d %d", comparaSedgewick, trocaSedgewick);

   free(v);
   free(x);
   return 0;
}