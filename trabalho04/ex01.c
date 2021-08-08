#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
   char nome[100];
   char curso[4];
   int matricula;
} aluno;

int quantidade_alunos = 0;

void leVetor(aluno *v, char *nomeArquivo) {

   FILE *f;
   f = fopen(nomeArquivo, "r");

   if(f == NULL){
      exit(1);
   }

   int i = 0;
   fscanf(f, " %[^\t] %s %d", v[i].nome, v[i].curso, &v[i].matricula);

   while(!feof(f)){
      i++;

      fscanf(f, " %[^\t] %s %d", v[i].nome, v[i].curso, &v[i].matricula);
      quantidade_alunos++;
   }

   fclose(f);
}

void imprimeVetor(aluno *v, int n) {
   for(int i = 0; i < n; i++) {
      printf("%s %s %d\n", v[i].nome, v[i].curso, v[i].matricula);
   }
}

int particao(aluno *v, int p, int r) {
   int i = (p - 1), j = p, tmp = 0;
   int tamanho_nome = strlen(v[r].nome);
   int *piv = (int*) malloc(tamanho_nome * sizeof(int));

   for(int i = 0; i < tamanho_nome; i++) {
      piv[i] = (int)v[r].nome[i];
   }

   while(j <= r - 1){
      if((int)v[j].nome[tmp] == piv[tmp]){
         tmp++;
         continue;
      }

      if((int)v[j].nome[tmp] < piv[tmp]){
         i++;

         aluno aux;
         aux = v[i];
         v[i] = v[j];
         v[j] = aux;
      }

      tmp = 0;
      j++;
   }

   free(piv);

   aluno aux;
   aux = v[i+1];
   v[i+1] = v[r];
   v[r] = aux;

   return (i + 1);
}

void quickSort(aluno *v, int p, int r) {
   int q;

   if(p < r) {
      q = particao(v, p, r);
      quickSort(v, p, q - 1);
      quickSort(v, q + 1, r);
   }
}

int main() {

   char nomeArquivo[100];
   scanf("%s", nomeArquivo);   

   aluno v[1000];

   leVetor(v, nomeArquivo);
   quickSort(v, 0, quantidade_alunos);
   imprimeVetor(v, quantidade_alunos);

   return 0;
}