#include <stdio.h>
#include <stdlib.h>

int c = 0, t = 0;

void leVetor(int *v, int n) {
   for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
   }
}

void intercala(int *v, int p, int q, int r) {
    int i, j, k;
    int *w;

    w = (int*)malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r) {
    	c++;
        if(v[i] <= v[j]) {
        	t++;
            w[k++] = v[i++];
        }
        else {
        	t++;
        	w[k++] = v[j++];
        }
    }

    while(i < q) {
    	t++;
        w[k++] = v[i++];
    }

    while(j < r) {
    	t++;
        w[k++] = v[j++];
    }

    for(i = p; i < r; i++) {
    	t++;
        v[i] = w[i - p];
    }

    free(w);
}

void mergeSort(int *v, int p, int r) {
    if(p < r - 1) {
        int q = (p + r) / 2;

        mergeSort(v, p, q);
        mergeSort(v, q, r);
        intercala(v, p, q, r);
    }
}


int main() {

   int n;
   scanf("%d", &n);

   int *v;
   v = (int*) malloc(n * sizeof(int));

   leVetor(v, n);
   mergeSort(v, 0, n);

   printf("%d %d", c, t);

   free(v);
}

