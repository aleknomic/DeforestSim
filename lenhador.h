#ifndef LENHADOR_H_INCLUDED
#define LENHADOR_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "floresta.h"
#include "arvore2.h"
using namespace std;

class Lenhador{
    public:
    int pot; //potência de trabalho diário

    Lenhador(int tpot); //construtor/set
};

Lenhador::Lenhador(int tpot){
    this->pot = tpot;
};

#endif