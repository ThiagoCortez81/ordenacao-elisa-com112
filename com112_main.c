/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: demo
 *
 * Created on 29 de Março de 2018, 21:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

int main() {
    LimpaArquivos(); //Remove todos os arquivos de ordenação gerados por outra instância previamente abertas do programa

    int TamArq=MenuRelatorio(TamArq);// Menu de Relatorio retorna o tamanho do arquivo;
    int n_comp = 0;
    int n_troca = 0;
    int *Vet;
    int sair = 1;
    int i;
    char indentificador[20];
    clock_t t0, tf;
    double tempo_gasto;
    int op;
    
    do {
        n_comp = 0;
        n_troca = 0;
        
        printf("\n\n\n\t Trabalho prático Algoritmo e Estrutura de dados II");
        printf("\n\n\t Algoritmo Desenvolvidos ");
        printf("\n\t Bubble Sort    -> 1 ");
        printf("\n\t Insertion Sort -> 2 ");
        printf("\n\t Selection Sort -> 3 ");
        printf("\n\t Merge Sort     -> 4 ");
        printf("\n\t Quick Sort     -> 5 ");
        printf("\n\t Gerar Relatorio Final-> 6 ");
        printf("\n\t Gerar Relatorio Saida-> 7 ");
        printf("\n\t Sair           -> 0 ");
        do {
            
            printf("\n\n\t Escolha:   ");
            scanf("%d", &op);
            n_comp=0;
            n_troca=0;
        } while (op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 0 && op != 7);
        system("clear");
        
        switch (op) {
            case 1:
                Vet = (int *) malloc(TamArq * sizeof(int));//Alocando o vetro dinamicamente
        
                printf("\n\t Algoritmo Definido -> * Bubble Sort *\n");
                Preenche_Vetor_Tam_N(Vet);
                strcpy(indentificador,"1-Bubble_Sort.txt");
                bublle_sort(TamArq, Vet, &n_comp, &n_troca, indentificador, &tempo_gasto);
                printf("\n\n \t Sucesso ! ");
                break;

            case 2:
                Vet = (int *) malloc(TamArq * sizeof(int));//Alocando o vetro dinamicamente
        
                printf("\n\tAlgoritmo Definido -> * Insertion Sort *");
                Preenche_Vetor_Tam_N(Vet);
                strcpy(indentificador,"2-Insertion_Sort.txt");
                insertionSort(Vet, TamArq, &n_comp, &n_troca, indentificador, &tempo_gasto);
                printf("\n\n \t Sucesso ! ");
                break;

            case 3:
                Vet = (int *) malloc(TamArq * sizeof(int));//Alocando o vetro dinamicamente
        
                printf("\n\tAlgoritmo Definido -> * Selection Sort *");
                Preenche_Vetor_Tam_N(Vet);
                strcpy(indentificador,"3-Selection_Sort.txt");
                Selection_Sort(TamArq, Vet, &n_comp, &n_troca, indentificador, &tempo_gasto);
                printf("\n\n \t Sucesso ! ");
                break;

            case 4:
                Vet = (int *) malloc(TamArq * sizeof(int));//Alocando o vetro dinamicamente
        
                printf("\n\tAlgoritmo Definido -> * Merge Sort *");
                Preenche_Vetor_Tam_N(Vet);
                strcpy(indentificador,"4-Merge_Sort.txt");
                t0 = clock();
                mergesort(Vet, 0, TamArq - 1, &n_comp, &n_troca);
                tf = clock();
                tempo_gasto = (tf - t0) * 1000.0 / CLOCKS_PER_SEC; 
                Grava_Arquivo_Ordenado(Vet, TamArq, n_comp, n_troca, indentificador, tempo_gasto);
                printf("\n\n \t Sucesso ! ");
                break;

            case 5:
                Vet = (int *) malloc(TamArq * sizeof(int));//Alocando o vetro dinamicamente
        
                printf("\n\tAlgoritmo Definido -> * Quick Sort *");
                Preenche_Vetor_Tam_N(Vet);
                strcpy(indentificador,"5-Quick_Sort.txt");
                t0 = clock();
                quicksort(Vet, 0, TamArq - 1, &n_comp, &n_troca);
                tf = clock();
                tempo_gasto = (tf - t0) * 1000.0 / CLOCKS_PER_SEC;
                Grava_Arquivo_Ordenado(Vet, TamArq, n_comp, n_troca, indentificador, tempo_gasto);
                printf("\n\n \t Sucesso ! ");
                break;
                
            case 6:
                if (Vet != NULL){
                    Relatorio_Final(TamArq);// Gerando o Relatorio Final
                    printf("\n\n \t Sucesso ! ");
                } else {
                    printf("Execute ao menos uma ordenacao! \n");                    
                }
                break;
                
            case 7:
                if (Vet != NULL){
                    Gerar_Saida(Vet, TamArq); // Gerando o relatorio de saida
                    printf("\n\n \t Sucesso ! ");
                }
                else 
                    printf("Primeiro execute uma ordenacao! \n");
                break;
        }
        
    } while (op != 0);
    
    

    free(Vet);

    

    return (EXIT_SUCCESS);
}

