//
//  jogo20perguntas.c
//  Jogo 20 Perguntas
//
//  Created by Patrick Beal.
//  Copyright © 2018 Patrick Beal. All rights reserved.
//

#include <headers.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pArquivo;

    int opcao =0;
    char *numero;
    pArquivo = fopen("perguntas.txt", "r+");

    arvore *raiz = (arvore *) malloc(sizeof(arvore));
    raiz->Sim = NULL;
    raiz->Nao = NULL;
    raiz->indice = 1;
    arvore *salvar = NULL;

    printf(" *** Jogo das 20 Perguntas *** \n");
    printf("1) Iniciar novo jogo\n");
    printf("2) Carregar jogo\n");
    printf("3) Sair\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1: // Novo jogo
            printf("Digite sua pergunta inicial: \n");
            fgets(raiz->pergunta, 50, stdin);
            strtok(raiz->pergunta, "\n");               //Retira o '\n' inserido ao final da string
            fprintf(pArquivo, "%d", raiz->indice);
            fprintf(pArquivo, ")");
            fprintf(pArquivo, "%s", raiz->pergunta);
            printf("\nFim de jogo!\n");
            break;

        case 2: //Carregar Jogo
            numero = malloc(4*(sizeof(char)));
            fscanf(pArquivo, "%4[^)])", numero);
            fscanf(pArquivo, "%50[^\n]\n", raiz->pergunta);
            raiz->Sim = NULL;
            raiz->Nao = NULL;
            raiz->indice = atoi(numero);
            free(numero);
            salvar = carregarArvore(pArquivo, &raiz->Sim, &raiz, 2, 1);
            printf("\nCarregando dados passados......\nFeito!\n");
            printf("\nFim de jogo!\n");
            break;

        case 3:
            break;

        default:
            printf("Opção Inválida!!\n");
            removerNo(raiz);
            removerNo(salvar);
            return 0;
    }

    removerNo(raiz);
    removerNo(salvar);
    fclose(pArquivo);
    printf("Até a próxima!!!\n");
    return 0;

}