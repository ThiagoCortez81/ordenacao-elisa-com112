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
#include "com112_sort.h"


    
int bublle_sort(int tam, int *vet, int *comparacao)
{
    int i = 0;
    int n, aux;
    int qtd_troca=0;

    do 
    {
        for (n = 0; n < (tam - 1); n++) // Estrutura que realiza o percorrimento ate o penultimo elemento
        {
            (*comparacao)++;// Quantidade de comparacao realizada dentro da estrutura 

            if (vet[n] > vet[n + 1]) // Condicao logica que avalia o tamanho do conteudo no vet na posica n
            {
                qtd_troca++; // Variavel que realiza a somatoria de trocas realizadas

                aux = vet[n];
                vet[n] = vet[n + 1];
                vet[n+1] = aux;
            } 
        }
        
        i++; // Variavel que inclementa 1 em seu valor ate se torna maior ou igual ao tamanho e quatidade de troca
        
    } while (i <= tam && qtd_troca);// Estrutura de repeticao com a tamanho do vetor realizando a troca enquando houve



    return qtd_troca;
}
       
void Selection_Sort(int tam,int *vet,int *n_comp,int *n_troca)
{
    int eleito;
    int menor;
    int num;
    int aux;
    int j,i;
    
    for(i=0;i<tam-1;i++)
    {
        
        eleito=i;
        menor=i+1;
        for(j=i+2;j<tam;j++)
        {
            (*n_comp)++;
            if(vet[j]<vet[menor])
                menor=j;
        }
        
        (*n_comp)++;
        if(vet[menor] < vet[eleito])
        {
            (*n_troca)++;
            aux=vet[eleito];
            vet[i]=vet[menor];
            vet[menor]=aux;
        }
    }
  

    
    return;

}

void insertionSort(int *V, int n, int *n_comp, int *n_mov)
{

  int eleito, j;  
  
  // laço com a quantidade de elementos do vetor - 1
  for(int i=1;i<=(n-1);i++)
  {
    eleito = V[i];
    j = i - 1;
    
    // acrescenta 1 comparação
    (*n_comp)++; 
    
    // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
    while(j >= 0 && V[j] > eleito)
    {
      // acrescenta 1 comparação
      (*n_comp)++; 
      
      // acrescenta 1 comparação
      (*n_mov)++; 
      
      V[j+1] = V[j];
      j--;
    }
    
    V[j+1] = eleito;
  }
}

void mergesoft(int *vet,int ini,int fim)
{
    int meio;
     
    
    
    if(ini<fim)
    {
        meio=(ini+fim)/2;
        mergesoft(vet,ini,meio);
        mergesoft(vet,meio+1,fim);
        merge(vet,ini,fim,meio);
    }
    
    
}

void merge(int *vet,int ini,int fim,int meio)
{
    int Comecovet1=ini, Comecovet2=meio+1;// Declarando o começo dos dois vetores 
    int tam= fim-(ini+1); // calculando o tamanho do vetor obitido
    int posLivre=0;// variavel responsavel por verificar a posição livre do vetor auxiliar
    int *VetorAux; // Vetor que obtera a sequencia ordenada 
    
    VetorAux=(int*)malloc(tam*sizeof(int)); // alocando dinamicamente o tamanho do vetor
   
    
    
    while(Comecovet1<=meio && Comecovet2<=fim)// Estrutura de repetição resposavel por avaliar
    {                                              // se o vetor já chegou em seu fim para a comparação
        
        if(vet[Comecovet1]<=vet[Comecovet2]) // Comparando a posição do vetor1 com vetor2 para validar o menor elemento
        {
            VetorAux[posLivre]=vet[Comecovet1];// Salvando menor elemento vetor auxiliar;
            Comecovet1++;
            
        }else{
            VetorAux[posLivre]=vet[Comecovet2];
            Comecovet2++;
        }
        posLivre++;// incrementa a posição livre do vetor auxiliar
    }
    // Estrutura responsavel por verificar se se existe elementos no meio do vetor para serem ordenados
    while(Comecovet1<=meio || Comecovet2<=fim)
    {
        if(Comecovet1<=meio)
        {
            VetorAux[posLivre]=vet[Comecovet1];
            Comecovet1++;
            
        }
        else{
            VetorAux[posLivre]=vet[Comecovet2];
            Comecovet2++;
        }
        posLivre++;
    }
    
       
    for(int i=ini;i<=fim;i++)// Passando o vetor auxiliar ordenado para o vetor original desordenado
    {
        vet[i]=VetorAux[i-ini];
    }
    
    // limpando vetor
    free(VetorAux);
    return ;
}
