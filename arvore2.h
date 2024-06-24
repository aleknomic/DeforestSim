#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <string>
#include <iostream>

class Arvore{
public:
    int e; //quantidade para derrubar / resistencia
    std::string tipo; //tipo de árvore
    Arvore(int te); //construtor
    void imprimir();
};

Arvore::Arvore(int te){ //1=eucalipto, 2=cedro, 3=ipe
//Tipos são "setados" a partir da resistência
    if (te==1){
        this->e=1;
        this->tipo="Eucalipto";
    } else if(te==2){
        this->e=2;
        this->tipo="Cedro";
    } else if(te==3){
        this->e=3;
        this->tipo="Ipe";
    }
};

void Arvore::imprimir(){
    std::cout << "Tipo: " << this->tipo << std::endl;
    std::cout << "Resistencia: " << this->e << std::endl;
};

#endif