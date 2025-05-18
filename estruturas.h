#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    char *nome;
    float peso;
    float valor;
} Item;

typedef struct {
    char *nome;
    char *descricao;
    int qtdItens;
    float capacidadeMochila;
    Item *itens;
} Personagem;

float mochilaFracionaria(Personagem p);
void salvarResultado(const char *saida, Personagem p, float valorTotal);

#endif
