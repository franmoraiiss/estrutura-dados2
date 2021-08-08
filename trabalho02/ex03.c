#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c, t;

void combSort(int *v, int n);

int main() {
   
   char arquivo[50];
   scanf("%s", arquivo);

   int n = 0; //quantidade de caracter no arquivo
   int *v = NULL; //vetor
   FILE *f; //vetor do arquivo
   
   int i = 0, elem;

   f = fopen(arquivo, "r+");
   if(arquivo == NULL)
      exit(1);

   fscanf(f, "%d", &i);
   while(!feof(f)) {
      fscanf(f, "%d", &i);
      n++;
   }
   fclose(f);

   v = (int *) malloc(n * sizeof(int));
   if(v == NULL)
      exit(1);

   f = fopen(arquivo, "r+");

   i = 0;
   fscanf(f, "%d", &elem);
   while(!feof(f)) {
      v[i] = elem;
      i++;
      fscanf(f, "%d", &elem);
   }
   fclose(f);

   combSort(v, n);
   printf("%d %d\n", c, t);

   free(v);

   return 0;
}

void combSort(int *v, int n) {
   int step = n;
   int i, j, k, again = 1;

   while((step = (step / 1.3 )) > 1) {
      for(j = 0; j < n - step; j++){
         k = j + step;
         c++;
         if(v[j] > v[k]) {
            printf("%d %d\n", j, k);
            int aux = v[j];
            v[j] = v[k];
            v[k] = aux; 
            t++;
         }
      }
   }

   for(i = 0; i < n - 1 && again == 1; i++){
      again = 0;
      for(j = n - 1; j > i; j--){
         c++;
         if(v[j] < v[j-1]) {
            printf("%d %d\n", j-1, j);
            t++;
            int aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            again = 1;
         }
      }
   }

}