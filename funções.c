#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

int comparar(const void *a, const void *b) {
    Item *i1 = (Item*)a;
    Item *i2 = (Item*)b;
    float vp1 = i1->valor / i1->peso;
    float vp2 = i2->valor / i2->peso;
    return (vp2 > vp1) - (vp2 < vp1);
}

float mochilaFracionaria(Personagem p) {
    qsort(p.itens, p.qtdItens, sizeof(Item), comparar);

    float capacidade = p.capacidadeMochila;
    float valorTotal = 0;

    printf("Itens selecionados:\n");

    for (int i = 0; i < p.qtdItens && capacidade > 0; i++) {
        if (p.itens[i].peso <= capacidade) {
            printf("- %s (100%%)\n", p.itens[i].nome);
            capacidade -= p.itens[i].peso;
            valorTotal += p.itens[i].valor;
        } else {
            float fracao = capacidade / p.itens[i].peso;
            printf("- %s (%.1f%%)\n", p.itens[i].nome, fracao * 100);
            valorTotal += p.itens[i].valor * fracao;
            capacidade = 0;
        }
    }

    return valorTotal;
}

void salvarResultado(const char *saida, Personagem p, float valorTotal) {
    FILE *fp = fopen(saida, "w");
    if (!fp) {
        perror("Erro ao salvar arquivo");
        return;
    }

    fprintf(fp, "Personagem: %s\n", p.nome);
    fprintf(fp, "Descrição: %s\n", p.descricao);
    fprintf(fp, "Valor total na mochila: %.2f\n", valorTotal);
    fclose(fp);
}
