#include <stdio.h>
#include <stdlib.h>

#include <string.h>

struct StructAluno {
    char nome[30];    
    int binario;
};

typedef struct StructAluno Aluno;

int tamanho_tabela;

int string(char *nome);
int gerar_hash(int chave);
int tabela(Aluno *hash);
int remover_aluno(Aluno *hash);
int buscar_aluno(char *nome_arquivo, Aluno *hash);
int imprime_tabela(char *nome_arquivo, Aluno *hash);
int inserir_aluno(char *nome_arquivo, Aluno *hash, int *posicao);

int main() {

    char nome_arquivo[50];
    int posicao;
    
    scanf("%d", &tamanho_tabela);    
    scanf("%s", nome_arquivo);

    Aluno *hash;
    hash = (Aluno*) calloc(tamanho_tabela, sizeof(Aluno));
    tabela(hash);
	
	posicao = 0;

	int escolha;
    scanf("%d", &escolha);

	while(escolha) {  		
	    scanf("%d", &escolha);

        switch(escolha) {
			case 1: {
				inserir_aluno(nome_arquivo, hash, &posicao);
				break;
			}

			case 2: {
				buscar_aluno(nome_arquivo, hash);
				break;
			}

			case 3: {
				remover_aluno(hash);
				break;
			}

			case 4: {
				imprime_tabela(nome_arquivo, hash);
				break;
			}

			case 9: {
				free(hash);
				return 0;
			}

			default: {
				printf("Opção inválida\n");
			}
        }
    } 

	free(hash);
    return 0;
}

int string(char *nome) {
    int chave = 0;

    int i = 0;
    do {
        chave = 31 * chave + nome[i];
        
		i++;
    } while (nome[i] != '\0');

    return chave;
}

int gerar_hash(int chave) {
	int codigo = (chave & 0x7FFFFFFF) % tamanho_tabela;
    return codigo;
}

int tabela(Aluno *hash) {
    for(int i = 0; i < tamanho_tabela; i++) {
        hash[i].binario = -1;
	}

	return 0;	
}

int buscar_aluno(char *nome_arquivo, Aluno *hash) {

    char nome[30];
	char sigla[4];
	int matricula;

    int contador = 0;

    scanf("%*c");
    scanf("%[^\n]", nome);

    FILE *f;
    int pos = gerar_hash(string(nome));
    for(int i = pos; i < tamanho_tabela && contador < tamanho_tabela; i++) {

        if(strcmp(hash[i].nome, nome) == 0) {

            f = fopen(nome_arquivo, "rb");

            fseek(f, (38 * hash[i].binario), SEEK_SET);
            fread(nome, sizeof(char), 30, f);
            fread(sigla, sizeof(char), 4, f);
            fread(&matricula, sizeof(int), 1, f);

            printf("%d %s %s\n", matricula, nome, sigla);

            fclose(f);
            break;

        } else if(hash[i].binario == -1) {	
            printf("x\n");

            break;

        } else if(i == (tamanho_tabela - 1)) {
            i = -1;
		}

        contador += 1;
    }

    if(contador == tamanho_tabela) {
        printf("x\n");
    }

	return 0;
}

int inserir_aluno(char *nome_arquivo, Aluno *hash, int *posicao) {

    char nome[30];
	char sigla[4];
    int matricula;    

	int contador = 0;

    scanf(" %[^\n]", nome);
    scanf("%s", sigla);
    scanf("%d", &matricula);

    FILE *f;

    int pos = gerar_hash(string(nome));
    for(int i = pos; i < tamanho_tabela && contador < tamanho_tabela; i++) {

        if(hash[i].binario == -1) {

            strcpy(hash[i].nome, nome);
            hash[i].binario = *posicao;
            
			f = fopen(nome_arquivo, "ab");

            fwrite(nome, sizeof(char), 30, f);
            fwrite(sigla, sizeof(char), 4, f);
            fwrite(&matricula, sizeof(int), 1, f);

            *posicao += 1;

            fclose(f);
            break;

        } else if(strcmp(hash[i].nome, "removido") == 0) {

            strcpy(hash[i].nome, nome);

            f = fopen(nome_arquivo, "rb+");
            fseek(f, (38 * hash[i].binario), SEEK_SET);

            fwrite(nome, sizeof(char), 30, f);
            fwrite(sigla, sizeof(char), 4, f);
            fwrite(&matricula, sizeof(int), 1, f);

            fclose(f);
            break;

        } else if(i == tamanho_tabela - 1) {
            i = -1;
		}
		
        contador += 1;
    }

	return 0;
}

int remover_aluno(Aluno *hash) {

    char nome[30];	

    scanf("%*c");
    scanf("%[^\n]", nome);

    int posicao = gerar_hash(string(nome));
    int contador = 0;

    while(contador < tamanho_tabela && hash[posicao].binario != -1) {

        if(strcmp(hash[posicao].nome, nome) == 0) {            
            strcpy(hash[posicao].nome, "removido");

            break;
        } else if(posicao == (tamanho_tabela - 1)) {
            posicao = -1;
        } else {
            posicao = gerar_hash(posicao + 1);
		}

        contador += 1;
    }

	return 0;
}

int imprime_tabela(char *nome_arquivo, Aluno *hash) {

	char nome[30];
	char sigla[4];
    int matricula;

    FILE *f;    

    for(int i = 0; i < tamanho_tabela; i++) {
        if(hash[i].binario == -1) {
            printf("[%d]: vazio\n", i);
        } else if(strcmp(hash[i].nome, "removido") == 0) {
            printf("[%d]: removido\n", i);
        } else {
            f = fopen(nome_arquivo, "rb");

            fseek(f, (38 * hash[i].binario), SEEK_SET);

            fread(nome, sizeof(char), 30, f);
            fread(sigla, sizeof(char), 4, f);
            fread(&matricula, sizeof(int), 1, f);

            printf("[%d]: %d %s %s %d\n", i, matricula, nome, sigla, hash[i].binario);

			fclose(f);
        }
    }  

	return 0;  
}
