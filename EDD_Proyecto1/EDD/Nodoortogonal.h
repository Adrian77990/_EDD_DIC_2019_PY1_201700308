//
// Created by MSI on 12/13/2019.
//

#ifndef EDD_PROYECTO1_NODOORTOGONAL_H
#define EDD_PROYECTO1_NODOORTOGONAL_H

using namespace std;
#include <string>

class Nodo{
public:
    Nodo *siguientex;
    Nodo *siguientey;
    Nodo *siguientez;
    Nodo *atrasx;
    Nodo *atrasy;
    Nodo *atrasz;

    string nombre;
    int mes;
    int ano;

    Nodo(string nombre,int mes,int ano){
        this->nombre = nombre;
        this->mes = mes;
        this->ano=ano;
        siguientex =siguientey=siguientez=atrasx=atrasy=atrasz = NULL;
    }
};
#endif //EDD_PROYECTO1_NODOORTOGONAL_H
