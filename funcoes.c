
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>  
#include <stdbool.h>
#include <math.h>

// funcao que inverte os elementos de um array
void inverter_array(int vetor[], int tamanho) {
    int valor_temporario;
    for(int i = 0; i < tamanho/2; i++) {
        valor_temporario = vetor[i];
        vetor[i] = vetor[tamanho-1-i];
        vetor[tamanho-1-i] = valor_temporario;
    }
}

// funcao que troca valores entre duas variaveis usando ponteiros
void trocar_valores(int* primeiro_valor, int* segundo_valor) {
    int valor_temporario = *primeiro_valor;
    *primeiro_valor = *segundo_valor;
    *segundo_valor = valor_temporario;
}

// funcao que soma duas matrizes e armazena o resultado em uma terceira
void somar_matrizes(int matriz1[][3], int matriz2[][3], int matriz_resultado[][3], int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            matriz_resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// funcao recursiva que calcula o n-esimo termo da sequencia fibonacci
int fibonacci(int numero) {
    if(numero <= 1) return numero;
    return fibonacci(numero-1) + fibonacci(numero-2);
}

// funcao que remove espacos de uma string
void remover_espacos(char* texto) {
    int contador = 0;
    for(int i = 0; texto[i]; i++) {
        if(texto[i] != ' ') {
            texto[contador++] = texto[i];
        }
    }
    texto[contador] = '\0';
}

// estrutura para representar um ponto no plano cartesiano
typedef struct {
    int x;
    int y;
} Ponto;

// calcula a distancia euclidiana entre dois pontos
float calcular_distancia(Ponto ponto1, Ponto ponto2) {
    return sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2));
}

// busca um elemento em um array e retorna sua posicao (ou -1 se nao encontrar)
int buscar_elemento(int vetor[], int tamanho, int elemento_buscado) {
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] == elemento_buscado) return i;
    }
    return -1;
}

// implementacao do algoritmo bubble sort para ordenacao
void ordenar_bubble(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho-1; i++) {
        for(int j = 0; j < tamanho-i-1; j++) {
            if(vetor[j] > vetor[j+1]) {
                int valor_temporario = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = valor_temporario;
            }
        }
    }
}

// conta quantos bits 1 existem na representacao binaria de um numero
int contar_bits_1(unsigned int numero) {
    int contador = 0;
    while(numero) {
        contador += numero & 1;
        numero >>= 1;
    }
    return contador;
}

// salva os elementos de um array em um arquivo
void salvar_array_arquivo(int vetor[], int tamanho, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if(arquivo == NULL) return;
    
    for(int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", vetor[i]);
    }
    fclose(arquivo);
}

// aloca dinamicamente uma matriz bidimensional
int** criar_matriz(int numero_linhas, int numero_colunas) {
    int** matriz = (int**)malloc(numero_linhas * sizeof(int*));
    for(int i = 0; i < numero_linhas; i++) {
        matriz[i] = (int*)malloc(numero_colunas * sizeof(int));
    }
    return matriz;
}

// verifica se uma string e um palindromo
bool eh_palindromo(const char* texto) {
    int tamanho = strlen(texto);
    for(int i = 0; i < tamanho/2; i++) {
        if(texto[i] != texto[tamanho-1-i]) return false;
    }
    return true;
}

// calcula o fatorial de um numero usando recursao
unsigned long long calcular_fatorial(int numero) {
    if(numero <= 1) return 1;
    return numero * calcular_fatorial(numero-1);
}

// preenche um cubo (matriz 3d) com um valor especifico
void preencher_cubo(int cubo[][4][4], int dimensao, int valor_preenchimento) {
    for(int i = 0; i < dimensao; i++) {
        for(int j = 0; j < dimensao; j++) {
            for(int k = 0; k < dimensao; k++) {
                cubo[i][j][k] = valor_preenchimento;
            }
        }
    }
}

// estrutura para implementacao de lista encadeada
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// cria um novo no para a lista encadeada
No* criar_no(int valor_inicial) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor_inicial;
    novo_no->proximo = NULL;
    return novo_no;
}

int main() {
    // exemplo de uso das funcoes
    printf("=== demonstracao das funcoes ===\n\n");
    
    // teste 1: array
    int vetor_teste[] = {1, 2, 3, 4, 5};
    printf("array original: ");
    for(int i = 0; i < 5; i++) printf("%d ", vetor_teste[i]);
    inverter_array(vetor_teste, 5);
    printf("\narray invertido: ");
    for(int i = 0; i < 5; i++) printf("%d ", vetor_teste[i]);
    printf("\n\n");
    
    // teste 2: ponteiros
    int primeiro_numero = 5, segundo_numero = 10;
    printf("antes da troca: primeiro = %d, segundo = %d\n", primeiro_numero, segundo_numero);
    trocar_valores(&primeiro_numero, &segundo_numero);
    printf("depois da troca: primeiro = %d, segundo = %d\n\n", primeiro_numero, segundo_numero);
    
    // teste 3: palindromo
    const char* texto_teste = "arara";
    printf("'%s' eh palindromo? %s\n", texto_teste, eh_palindromo(texto_teste) ? "sim" : "nao");
    
    return 0;
}
