#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================
//   STRUCT DA SALA (NÓ DA ÁRVORE)
// ===============================
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// ===============================
//        CRIA UMA NOVA SALA
// ===============================
Sala* criarSala(char nome[]) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ===============================
//     EXPLORAÇÃO DAS SALAS
// ===============================
void explorarSalas(Sala* atual) {
    char opcao;

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (atual->esquerda != NULL)
            printf(" - Digite 'e' para ir à sala da esquerda: %s\n", atual->esquerda->nome);

        if (atual->direita != NULL)
            printf(" - Digite 'd' para ir à sala da direita: %s\n", atual->direita->nome);

        printf(" - Digite 's' para sair\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);

        if (opcao == 's') {
            printf("\nEncerrando exploração...\n");
            break;
        } 
        else if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        }
        else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        }
        else {
            printf("\nCaminho inválido! Tente novamente.\n");
        }

        // Chegou em um nó-folha?
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("\nVocê chegou ao final do caminho na sala: %s\n", atual->nome);
            break;
        }
    }
}

// ===============================
//     MONTAGEM DA MANSÃO
// ===============================
//
//            Hall de Entrada
//              /           \
//        Biblioteca      Cozinha
//        /       \         /     \
//   Escritório  Sala de Música  Despensa   Jardim
//
int main() {
    // Nó raiz
    Sala* hall = criarSala("Hall de Entrada");

    // Nível 1
    hall->esquerda = criarSala("Biblioteca");
    hall->direita = criarSala("Cozinha");

    // Nível 2 esquerda (Biblioteca)
    hall->esquerda->esquerda = criarSala("Escritório");
    hall->esquerda->direita = criarSala("Sala de Música");

    // Nível 2 direita (Cozinha)
    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita = criarSala("Jardim");

    printf("=== DETECTIVE QUEST - NIVEL NOVATO ===\n");
    printf("Explore a mansão tomando decisões!\n");

    explorarSalas(hall);

    return 0;
}
