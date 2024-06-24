
#include <iostream>
#include "arvore2.h"
#include "floresta.h"
#include "lenhador.h"
#include <time.h>
using namespace std;

void cortar(Floresta **flo, Lenhador q) {
    //Cria uma floresta auxiliar
    Floresta *floaux = *flo;
    //Cria uma floresta para fazer a remoção de arvores ao longo da funçao
    Floresta *remover;
    //Cria uma arvore auxiliar para manter atualizado o tipo de arvore atual que sera ou nao cortada
    Arvore *arvaux;

    //Contador de arvores cortadas
    int contador = 0;

    //Equanto a potencia do lenhador for maior que 0, a floresta não ser nula
    //e existir a arvore atual
    while (q.pot > 0 && floaux->proximo && floaux->arv) {
        //Arvore auxiliar recebe a arvore atual da floresta auxiliar
        arvaux = floaux->arv;
        
        //se a potencia do lenhador for maior ou igual a resistencia da arvore atual
        if (q.pot >= arvaux->e) {
            cout << q.pot << endl;
            cout << arvaux->e << endl;
            //O nó remover recebe o nó atual da floresta, a arvore atual
            remover = floaux;
            cout << "Arvore a ser excluida " << remover->arv << endl;
            //A floresta apontada para o proximo nó, próxima árvore após o nó que iremos remover
            floaux = remover->proximo;
            cout << "Proxima arvore " << floaux->arv << endl;
            //Removemos a arvore desejada
            delete remover;
            //A potencia do lenhador diminui de acordo com a resistencia da arvore que ele acabou de derrubar
            q.pot -= arvaux->e;
            //O contador aumenta em 1
            contador++;
        }
        //se a potencia do lenhador for menor que a resistencia da arvore atual
        else {
            cout << "entrou no else" << endl;
            //A floresta auxiliar avança para a proxima arvore
            floaux = floaux->proximo;
        };
    };

    cout << "O lenhador cortou " << contador << " arvores hoje." << endl;
};


int main(){
    srand(time(0));

    //Cria uma floresta
    Floresta *l = new Floresta();
    
    //Cria um lenhador com potência aleatória (para mais potência, aumente o numero apos o %)
    //Lenhador John((rand() % 20) + 1);
    
    Lenhador John(100);
    
    cout << "O lenhador tem " << John.pot << " de potência." << endl;

    //Adicionar x arvores na floresta (aumente o o numero x em 'i<x' para mais arvores)
    for (int i=0; i < 10; i++){
        int num = (rand() % 3) + 1; //aleatoriza um numero entre 1 e 3
        cout << num << endl;
        Arvore *aux = new Arvore(num); //cria uma arvore com o numero aleatorizado
        l->adicionar(aux); //adiciona a arvore na floresta
    };

    //Imprime a floresta
    l->imprimir();
    
    //Aplica a função cortar utilizando a floresta e o lenhador
    //Há um erro: a floresta nao e excluida apos todas as arvores serem derrubadas
    cortar(&l, John);

    //Imprime a floresta apos a função cortar
    //Há um erro: a floresta não mostra cada nó da floresta como no primeiro imprimir
    //mas as arvores certas estão sendo cortadas.
    l->imprimir();
    
    return 0;
};