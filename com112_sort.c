/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   com112_sort.c
 * Author: demo
 *
 * Created on 6 de Abril de 2018, 21:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

void bublle_sort(int tam, int *vet, int *n_comp, int *n_troca, char *indentificador, double *tempo_gasto) {
    int n, aux, i = 0;
    clock_t t0, tf;
    t0 = clock();

//        int i, aux;
    int houve_troca = 1;

    // laço com a quantidade de elementos do vetor e enquanto houver troca
    while (i <= tam && houve_troca)
        {
            houve_troca = 0;

            // laço que percorre da primeira à penúltima posição do vetor
            for (int j = 0; j < (tam - 1); j++)
            {
                // acrescenta 1 comparação
                (*n_comp)++;

                if (vet[j] > vet[j + 1]) {

                    // sinaliza que houve troca nesta iteração
                    houve_troca = 1;

                    // acrescenta 1 movimentação
                    (*n_troca)++;

                    aux = vet[j];
                    vet[j] = vet[j + 1];
                    vet[j + 1] = aux;
                }
            }
            i++;
        }

    tf = clock();
    //Tempo total gasto
    *tempo_gasto = (tf - t0) * 1000.0 / CLOCKS_PER_SEC;
    // Retorna a quantidade de troca realizada



    Grava_Arquivo_Ordenado(vet, tam, *n_comp, *n_troca, indentificador, *tempo_gasto);

    return;
}

void Selection_Sort(int tam, int *vet, int *n_comp, int *n_troca, char *indentificador, double *tempo_gasto) {
    int eleito;
    int menor;
    int num;
    int aux;
    int j, i;
    clock_t t0, tf;
    t0 = clock();


    /*for (i = 0; i < tam - 1; i++) {

        eleito = i;
        menor = i + 1;
        for (j = i + 2; j < tam; j++) {
            (*n_comp)++;
            if (vet[j] < vet[menor])
                menor = j;
        }

        (*n_comp)++;
        if (vet[menor] < vet[eleito]) {
            (*n_troca)++;
            aux = vet[eleito];
            vet[i] = vet[menor];
            vet[menor] = aux;
        }
    }*/
    int pos;
    for (int i = 0; i < tam - 1; i++) {
        eleito = vet[i];
        menor = vet[i + 1];
        pos = i + 1;

        // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
        for (j = i + 1; j <= tam - 1; j++) {
            // acrescenta 1 comparação
            (*n_comp)++;

            if (vet[j] < menor) {
                menor = vet[j];
                pos = j;
            }
        }

        // acrescenta 1 comparação
        (*n_comp)++;
        if (menor < eleito) {
            // acrescenta 1 comparação
            (*n_troca)++;

            vet[i] = vet[pos];
            vet[pos] = eleito;
        }
    }

    tf = clock();
    //Tempo total gasto
    *tempo_gasto = (tf - t0) * 1000.0 / CLOCKS_PER_SEC;

    Grava_Arquivo_Ordenado(vet, tam, *n_comp, *n_troca, indentificador, *tempo_gasto);
    return;
}

void insertionSort(int *V, int n, int *n_comp, int *n_mov, char *indentificador, double *tempo_gasto) {

    int eleito, j;
    clock_t t0, tf;
    t0 = clock();



    // laço com a quantidade de elementos do vetor - 1
    for (int i = 1; i <= (n - 1); i++) {
        eleito = V[i];
        j = i - 1;

        // acrescenta 1 comparação
        (*n_comp)++;

        // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
        while (j >= 0 && V[j] > eleito) {
            // acrescenta 1 comparação
            (*n_comp)++;

            // acrescenta 1 movimentação
            (*n_mov)++;

            V[j + 1] = V[j];
            j--;
            
        }

        V[j + 1] = eleito;
        
    }

    
    
    tf = clock();
    //Tempo total gasto
    *tempo_gasto = (tf - t0) * 1000.0 / CLOCKS_PER_SEC;

    Grava_Arquivo_Ordenado(V, n, *n_comp, *n_mov, indentificador, *tempo_gasto);
    
    return;
}

void mergesort(int *vet, int ini, int fim, int *n_comp, int *n_mov) {
    if (ini < fim) {

        int meio = (fim + ini) / 2;


        mergesort(vet, ini, meio, n_comp, n_mov);

        mergesort(vet, meio + 1, fim, n_comp, n_mov);

        merge(vet, ini, fim, meio, n_comp, n_mov);

    }

}

void merge(int *vet, int ini, int fim, int meio, int *n_comp, int *n_mov) {
    int com1 = ini, com2 = meio + 1, comAux = 0, tam = fim - ini + 1;

    int *vetAux;

    vetAux = (int *) malloc(tam * sizeof (int)); // Vetor auxiliar que obtera a sequencia ordenada

    // Estrutura de repetição resposavel por avaliar
    while (com1 <= meio && com2 <= fim) {

        // Comparando a posição do vetor1 com vetor2 para validar o menor elemento
        if (vet[com1] < vet[com2]) {


            vetAux[comAux] = vet[com1]; // Salvando menor elemento vetor auxiliar;
            (*n_comp)++; // Comparação

            com1++;

        } else {

            vetAux[comAux] = vet[com2];
            (*n_comp)++; // Comparação

            com2++;

        }

        comAux++; // incrementa a posição livre do vetor auxiliar
        (*n_mov)++; //Movimentação

    }

    // Estrutura responsavel por verificar se se existe elementos no meio do vetor para serem ordenados

    while (com1 <= meio) {
        (*n_comp)++;
        vetAux[comAux] = vet[com1];

        comAux++;

        com1++;

    }

    // Estrutura responsavel por verificar se se existe elementos no meio do vetor para serem ordenados

    while (com2 <= fim) { //Caso ainda haja elementos na segunda metade
        (*n_comp)++;
        vetAux[comAux] = vet[com2];

        comAux++;

        com2++;

    }

    // Passando o vetor auxiliar ordenado para o vetor original desordenado
    for (comAux = ini; comAux <= fim; comAux++) { //Move os elementos de volta para o vetor original

        vet[comAux] = vetAux[comAux - ini];
        //(*n_mov)++;
    }


    free(vetAux);

    return;
}

void quicksort(int *v, int ini, int fim, int *n_comp, int *n_mov) {
    int meio;

    if (ini < fim) {
        meio = separa(v, ini, fim, n_comp, n_mov);
        quicksort(v, ini, meio, n_comp, n_mov);
        quicksort(v, meio + 1, fim, n_comp, n_mov);
    }


}

int separa(int *V, int p, int r, int *n_comp, int *n_mov)
{
  int pivo, i, j;
  pivo = V[(p+r)/2];
  i = p - 1;
  j = r + 1;
   
  while(i < j)
  { 
    // encontra o primeiro elemento menor que o pivo, a partir do fim, para trocar de lado
    do
    {
      j--;
      
      // acrescenta 1 comparação
      (*n_comp)++;
      
    }while(V[j] > pivo);
    
    // encontra o primeiro elemento maior que o pivo, a partir do inicio, para trocar de lado
    do
    {
      i++;
    
      // acrescenta 1 comparação
      (*n_comp)++;
      
    }while(V[i] < pivo);   
  
    // realiza troca de elementos do vetor
    if(i < j)
    {
      int aux;
      aux = V[i];
      V[i] = V[j];
      V[j] = aux;
      
      // acrescenta 1 movimentação
      (*n_mov)++; 
    }
  }
  return j;
}