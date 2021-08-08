#include <stdio.h>

int particiona(int *v, int p, int r) {
   int i = p, j = r + 1, piv = v[p];

   while(1) {
      
      while(v[++i] < piv) {
         if(i == r) {
            break;
         }
      }

      while(piv < v[--j]) {
         if(j == p) {
            break;
         }
      }

      if(i >= j) {
         break;
      }

      int aux;
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;

   }

   int aux;
   aux = v[p];
   v[p] = v[j];
   v[j] = aux;

   return j;
}

void quicksort(int *v, int p, int r) {
   int q;

   if(p < r) {
      q = particiona(v, p, r);
      quicksort(v, p, q - 1);
      quicksort(v, q + 1, r);
   }
}

int main() {
   int n = 9;
   int v[9] = {-3, 1, -80, 5, 4, 9, 0, 3, 4};

   quicksort(v, 0, n - 1);

   for(int i = 0; i < n; i++) {
      printf("%d ", v[i]);
   }

   return 0;
}
