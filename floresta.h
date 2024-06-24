#ifndef FLORESTA_H_INCLUDED
#define FLORESTA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "arvore2.h"
#include "lenhador.h"
using namespace std;

//Floresta é um no
class Floresta {
    public:
    Arvore *arv;
    Floresta *proximo;
    
    void adicionar(Arvore *a);
    void imprimir();
    void cortar(Lenhador q);
};

void Floresta::adicionar(Arvore *a){ //adicionar arvores na floresta
    // caso 1: floresta vazia
    if (this->arv == NULL){
        this->arv = a; //atribui arvore a para arv da floresta/adiciona arvore na floresta
        this->proximo = NULL; //o proximo vira null porque so tem 1 arvore nessa floresta
        cout << "ADICIONADA" << endl;
    }
    //caso 2: ja tem arvores e esta adionando outra
    else {
        // percorrer a floresta ate encontrar a ultima arvore
        Floresta *p = this;
        while(p->proximo != NULL){
            p = p->proximo;
        }
        // criar novo no com a arvore dentro
        Floresta *novo = new Floresta();
        // ligar o novo nó ao fim da floresta
        novo->arv = a;
        p->proximo = novo;
        cout << "ADICIONADA A PARTIR DO SEGUNDO IF" << endl;
    };
};

void Floresta::imprimir(){
    cout << "\nFloresta: " << endl;
    Floresta *aux = (this);
    //enquanto a floresta nao apontar para vazio
    while(aux != NULL){
        //print a resistencia/tipo da arvore
        cout << aux->arv << endl;
        //segue para a proxima arvore
        aux = aux->proximo;
    };
    cout << "\n \n" << endl;
};

#endif