/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   com112_file.h
 * Author: demo
 *
 * Created on 7 de Abril de 2018, 13:42
 */

#ifndef COM112_FILE_H
#define COM112_FILE_H

void GeraArquivo_N_Numeros(int tam);

void GeraArquivo_N_Numeros_Ordenados(int TamArq);

void Preenche_Vetor_Tam_N(int *Vet);

void Grava_Arquivo_Ordenado(int *Vet, int tam, int n_comp, int n_troca, char *indentificador, double tempo_gasto);

void Relatorio_Final(int tam);

void Gerar_Saida(int *Vet, int tam);

int MenuRelatorio(int TamArq);

void LimpaArquivos();


#endif /* COM112_FILE_H */

