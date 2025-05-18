#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

int main() {
    Personagem p;
    p.nome = "Aventureiro";
    p.descricao = "Explorador das ruínas antigas";
    p.capacidadeMochila = 15.0;
    p.qtdItens = 4;

    p.itens = malloc(p.qtdItens * sizeof(Item));

    p.itens[0] = (Item){"Poção", 2.0, 30.0};
    p.itens[1] = (Item){"Espada", 5.0, 70.0};
    p.itens[2] = (Item){"Mapa", 1.0, 20.0};
    p.itens[3] = (Item){"Joia", 10.0, 100.0};

    float valorTotal = mochilaFracionaria(p);
    printf("Valor total acumulado: %.2f\n", valorTotal);

    salvarResultado("saida.txt", p, valorTotal);

    free(p.itens);
    return 0;
}
