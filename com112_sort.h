/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   com112_sort.h
 * Author: demo
 *
 * Created on 6 de Abril de 2018, 21:34
 */

#ifndef COM112_SORT_H
#define COM112_SORT_H


void bublle_sort(int tam, int *vet, int *comparacao, int *n_troca, char *indentificador, double *tempo_gasto);

void Selection_Sort(int tam, int *vet, int *n_comp, int *n_troca, char *indentificador, double *tempo_gasto);

void insertionSort(int *V, int n, int *n_comp, int *n_mov, char *indentificador, double *tempo_gasto);

void mergesort(int *vet, int ini, int fim, int *n_comp, int *n_mov);

void merge(int *vet, int ini, int fim, int meio, int *n_comp, int *n_mov);

void quicksort(int *v, int ini, int fim, int *n_comp, int *n_mov);

int separa(int *v, int ini, int fim, int *n_comp, int *n_mov);



#endif /* COM112_SORT_H */

