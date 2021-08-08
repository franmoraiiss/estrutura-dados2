#include<stdio.h>
#include<stdlib.h>

int tamanhoVetor = 0;
int cont = 0;

void print(int *v);
void insere(int valor, int *v);
void remover(int valor, int *v);
int procurar(int valor, int *v);
int hash(int key);

int main() {

	int opcao;
	int valor;

	scanf("%d", &tamanhoVetor);
	int *v = malloc(tamanhoVetor * sizeof(int));

	// Preenche todo vetor com zero
	for (int i = 0; i < tamanhoVetor; i++) {
		v[i] = 0;
	}

	do {
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				scanf(" %d", &valor);
				insere(valor, v);
				break;

			case 2:
				scanf("%d", &valor);
				if(valor){
					int indice;
					indice = procurar(valor, v);
					if(indice != -1) printf("\n%d", indice);
				}
				break;

			case 3:
				scanf("%d", &valor);
				remover(valor, v);
				break;

			case 4:
				printf("\n");
				print(v);
				break;

			case 9:
				break;
		}
	} while (opcao != 9);

  free(v);
	return 0;
}

void print(int *v) {
	for(int i = 0; i < tamanhoVetor; i++) {
    if(v[i] != -2 && v[i] != 0) {
      printf("%d ", v[i]);
    }
	}
}


void insere(int valor, int *v) {
	if (cont == tamanhoVetor) exit(1);

	int pos;
	pos = hash(valor);
	while (v[pos] != 0 && v[pos] != -1) {
		pos = (pos + 1) % tamanhoVetor;
	}
	v[pos] = valor;

	cont++;
}


void remover(int valor, int *v) {
	if (cont == 0) exit(1);

	int indice;
	indice = valor;
	if (indice != -1) {
		v[indice] = -2;
		cont--;
	}
}

int procurar(int valor, int *v) {
	if (cont == 0) exit(1);

	int pos;
	pos = hash(valor);
	while(v[pos] != 0) {
		if(v[pos] == valor) return pos;
		pos = (pos + 1) % tamanhoVetor;
	}

	printf("\n-1");
	return -1;
}

int hash(int key) {
  return (key & 0x7FFFFFFF) % tamanhoVetor;
}
