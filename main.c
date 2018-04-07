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

/*
 * 
 */
int main() {

    int op;
    printf("\n\n\n\t Trabalho prático Algoritmo e Estrutura de dados II");
    
    printf("\n\n\t Algoritmo Desenvolvidos ");
   
    printf("\n\t Bubble Sort    -> 1 ");
    printf("\n\t Insertion Sort -> 2 ");
    printf("\n\t Selection Sort -> 3 ");
    printf("\n\t Merge Sort     -> 4 ");
    printf("\n\t Quick Sort     -> 5 ");
    
    do{
      printf("\n\n\t Escolha:   ");
      scanf("%d",&op);
    }while(op != 1 && op != 2 && op!=3 && op!=4 && op!=5);
    
    switch(op)
    {
        case 1:
            break;
            
        case 2:
            break;
            
        case 3:
            break;
            
        case 4:
            break;
            
        case 5:
            break;    
    }
            
    
    
    
    
    return (EXIT_SUCCESS);
}

