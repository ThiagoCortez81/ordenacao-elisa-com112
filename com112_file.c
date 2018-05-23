/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   com112_file.c
 * Author: demo
 *
 * Created on 7 de Abril de 2018, 13:43
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <zconf.h>
#include "com112_file.h"

void GeraArquivo_N_Numeros(int tam) {
    FILE *f; //Ponteiro para ler o arquivo


    //Abre o arquivo e testa se houve falha, em caso de falha, exibe uma mensagem
    if (!(f = fopen("com112_entrada.txt", "w"))) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Gravando o tamnhado do vetor na primeira linha do arquivo
    fprintf(f, "%d \n", tam);

    // Escrevendo numeros aleatorio no arquivo 
    while (0 < tam) {
        fprintf(f, "%d ", rand() % 10000);
        tam--;
    }

    // fechando o arquiv0
    fclose(f);
}

void GeraArquivo_N_Numeros_Ordenado(int tam) {
    FILE *f; //Ponteiro para ler o arquivo
    int cont = 0;

    //Abre o arquivo e testa se houve falha, em caso de falha, exibe uma mensagem
    if (!(f = fopen("com112_entrada.txt", "w"))) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Gravando o tamnhado do vetor na primeira linha do arquivo
    fprintf(f, "%d \n", tam);

    // Escrevendo numeros aleatorio no arquivo 
    while (cont < tam) {
        fprintf(f, "%d ", cont);
        cont++;
    }

    // fechando o arquiv0
    fclose(f);
}

int MenuRelatorio(int TamArq) {
    int op = 0;
    int *Vet;

    do {
        printf("\n\n\n\t Trabalho prático Algoritmo e Estrutura de dados II");

        printf("\n\n\t Relatorios ! ");
        printf("\n\t Gerar Relatorio Aleatorio e usar -> 1 ");
        printf("\n\t Gerar Relatorio Ordenado e usar  -> 2 ");
        printf("\n\n\t Escolha:   ");
        scanf("%d", &op);

    } while (op != 1 && op != 2);

    switch (op) {
        case 1:


            printf("\n\t Gerar Relatorio Aleatorio  ");
            printf("\n\n\t Digite o tamanho do arquivo:   ");
            scanf("%d", &TamArq);

            // Alocando o vetor dinamicamente
            Vet = (int *) malloc(TamArq * sizeof (int));

            // Funcão gera arquivo
            GeraArquivo_N_Numeros(TamArq);

            printf("\n\t** Relatorio Aleatorio Gerado com Sucesso ** ");
            system("clear");

            return TamArq;
            break;


        case 2:

            printf("\n\t Gerar Relatorio Aleatorio  ");
            printf("\n\n\t Digite o tamanho do arquivo:   ");
            scanf("%d", &TamArq);

            // Alocando o vetor dinamicamente
            Vet = (int *) malloc(TamArq * sizeof (int));

            // Funcão gera arquivo
            GeraArquivo_N_Numeros_Ordenado(TamArq);

            printf("\n\t** Relatorio Aleatorio Gerado com Sucesso ** ");
            system("clear");
            return TamArq;
            break;
    }
    return TamArq;
}

void Preenche_Vetor_Tam_N(int *Vet) {
    FILE *f;
    int tam;
    int num;
    int cont = 0;

    //Abre o arquivo e testa se houve falha, em caso de falha, exibe uma mensagem
    if (!(f = fopen("com112_entrada.txt", "r"))) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Lendo o tamanho do arquivo
    fscanf(f, "%d \n", &tam);

    ////Enquanto não chegar o fim do arquivo, irá ler cada valor e criará um
    while (!feof(f)) {

        fscanf(f, "%d ", &num);
        Vet[cont] = num;
        cont++;
    }

    fclose(f);
}

void Grava_Arquivo_Ordenado(int *Vet, int tam, int n_comp, int n_troca, char *indentificador, double tempo_gasto) {

    FILE *arq1, *arq2, *arq3, *arq4, *arq5;
    
    // Abrindo o arquivo para escrevita e validando
    if (!(arq1 = fopen(indentificador, "w"))) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    
    // Escrevendo no arquivo a compara, troca e tempo gasto
    fprintf(arq1, "%i %i %f \n", n_comp, n_troca, tempo_gasto);

    // Estruduta de repetição por escrever todos numeros do vetor no arquivo
    for (int i = 0; i < tam; i++)
        fprintf(arq1, "%d ", Vet[i]);

    fclose(arq1);
}

void Relatorio_Final(int Tam) {

    int n_comp;
    int n_mov;
    int flag = 0;
    float n_temp;

    FILE *f; //Ponteiro para ler o arquivo

    FILE *arq1, *arq2, *arq3, *arq4, *arq5;

    //Abre o arquivo e testa se houve falha, em caso de falha, exibe uma mensagem
    if (!(f = fopen("com112_relatorio.txt", "w"))) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(f, "Numeros de elementos ordenados: %d \n\n", Tam);

    if ((arq1 = fopen("1-Bubble_Sort.txt", "r"))) {
        fscanf(arq1, "%d %d %f", &n_comp, &n_mov, &n_temp);
        flag = 1;
        fprintf(f, "\n Método Bubble Sort \n\t"
                   " Tempo de execução: %0.2f \n\t"
                   " Número de comparações: %d \n\t"
                   " Número de movimentações: %d \n", n_temp, n_comp, n_mov);
    }

    if (flag)
        fclose(arq1);

    flag = 0;

    if ((arq2 = fopen("2-Insertion_Sort.txt", "r"))) {
        fscanf(arq2, "%d %d %f", &n_comp, &n_mov, &n_temp);
        flag = 1;
        fprintf(f, "\n Método Insertion Sort \n\t "
                   "Tempo de execução: %0.2f \n\t"
                   " Número de comparações: %d \n\t"
                   " Número de movimentações: %d \n", n_temp, n_comp, n_mov);
    }

    if (flag)
        fclose(arq2);

    flag = 0;

    if ((arq3 = fopen("3-Selection_Sort.txt", "r"))) {
        fscanf(arq3, "%d %d %f", &n_comp, &n_mov, &n_temp);
        flag = 1;
        fprintf(f, "\n Método Selection Sort \n\t"
                   " Tempo de execução: %0.2f \n\t"
                   " Número de comparações: %d \n\t"
                   " Número de movimentações: %d \n", n_temp, n_comp, n_mov);
    }

    if (flag)
        fclose(arq3);

    flag = 0;

    if ((arq4 = fopen("4-Merge_Sort.txt", "r"))) {
        fscanf(arq4, "%d %d %f", &n_comp, &n_mov, &n_temp);
        flag = 1;
        fprintf(f, "\n Método Merge Sort \n\t"
                   " Tempo de execução: %0.2f \n\t"
                   " Número de comparações: %d \n\t"
                   " Número de movimentações: %d \n", n_temp, n_comp, n_mov);
    }

    if (flag)
        fclose(arq4);

    flag = 0;

    if ((arq5 = fopen("5-Quick_Sort.txt", "r"))) {
        fscanf(arq5, "%d %d %f", &n_comp, &n_mov, &n_temp);
        flag = 1;
        fprintf(f, "\n Método Quick Sort \n\t"
                   " Tempo de execução: %0.2f \n\t"
                   " Número de comparações: %d \n\t"
                   " Número de movimentações: %d \n", n_temp, n_comp, n_mov);
    }

    if (flag)
        fclose(arq5);


    fclose(f);

    printf("\n\tRelatorio Final Gerado com Sucesso !");

}

void LimpaArquivos() {
    int flag = 0;
    FILE *f; //Ponteiro para ler o arquivo

    FILE *arq1, *arq2, *arq3, *arq4, *arq5;

    if ((arq1 = fopen("1-Bubble_Sort.txt", "r"))) {
        unlink("1-Bubble_Sort.txt");
    }

    if (flag)
        fclose(arq1);

    flag = 0;

    if ((arq2 = fopen("2-Insertion_Sort.txt", "r"))) {
        unlink("2-Insertion_Sort.txt");
    }

    if (flag)
        fclose(arq2);

    flag = 0;

    if ((arq3 = fopen("3-Selection_Sort.txt", "r"))) {
        unlink("3-Selection_Sort.txt");
    }

    if (flag)
        fclose(arq3);

    flag = 0;

    if ((arq4 = fopen("4-Merge_Sort.txt", "r"))) {
        unlink("4-Merge_Sort.txt");
    }

    if (flag)
        fclose(arq4);

    flag = 0;

    if ((arq5 = fopen("5-Quick_Sort.txt", "r"))) {
        unlink("5-Quick_Sort.txt");
    }

    if (flag)
        fclose(arq5);

}

void Gerar_Saida(int *Vet, int tam) {
    FILE *Relatorio_Saida;
    int num;
    
    int a;
    int b;
    float c;
    
    // Abrindo arquivo para escrever Relatorio de saida
    if (!(Relatorio_Saida = fopen("com112_saida.txt", "w"))) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 0; i < tam; i++) {
        fprintf(Relatorio_Saida, "%d ", Vet[i]);
    }

    fclose(Relatorio_Saida);

    printf("\n\tRelatorio de Saida Gerado com Sucesso !");

    return;
}
