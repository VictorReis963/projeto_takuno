// leitura.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

char* lerLinhaComPrefixo(FILE *fp, const char *prefixo) {
    char linha[128];
    if (fgets(linha, sizeof(linha), fp)) {
        char *valor = strchr(linha, ':');
        if (valor != NULL) {
            valor += 2; // pular ": "
            valor[strcspn(valor, "\n")] = 0; // remover '\n'
            return strdup(valor);
        }
    }
    return NULL;
}

Personagem lerArquivoEntrada(const char *entrada1) {
    FILE *fp = fopen(entrada1, "r");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    Personagem p;
    p.nome = lerLinhaComPrefixo(fp, "Nome");
    p.descricao = lerLinhaComPrefixo(fp, "Descrição");

    char linha[128];

    fgets(linha, sizeof(linha), fp);
    sscanf(strchr(linha, ':') + 2, "%f", &p.capacidadeMochila);

    fgets(linha, sizeof(linha), fp);
    sscanf(strchr(linha, ':') + 2, "%d", &p.qtdItens);

    p.itens = malloc(p.qtdItens * sizeof(Item));

    for (int i = 0; i < p.qtdItens; i++) {
        fgets(linha, sizeof(linha), fp);
        char nomeItem[64];
        float peso, valor;
        sscanf(linha, "Item: %s %f %f", nomeItem, &peso, &valor);
        p.itens[i].nome = strdup(nomeItem);
        p.itens[i].peso = peso;
        p.itens[i].valor = valor;
    }

    fclose(fp);
    return p;
}
