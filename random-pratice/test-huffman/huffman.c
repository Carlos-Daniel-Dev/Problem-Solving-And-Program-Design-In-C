#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

struct No* buscar(struct No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    printf("%d ", raiz->valor); // Mostra o valor atual enquanto percorre a árvore

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

int main() {
    struct No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    int elemento = 40;
    printf("Caminho para encontrar %d: ", elemento);
    struct No* resultado = buscar(raiz, elemento);
    if (resultado != NULL) {
        printf("\n");
        printf("%d encontrado!\n", resultado->valor);
    } else {
        printf("\n");
        printf("%d não encontrado!\n", elemento);
    }

    return 0;
}
