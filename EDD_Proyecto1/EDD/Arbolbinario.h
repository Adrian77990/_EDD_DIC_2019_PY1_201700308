//
// Created by MSI on 12/12/2019.
//

#ifndef EDD_PROYECTO1_ARBOLBINARIO_H
#define EDD_PROYECTO1_ARBOLBINARIO_H


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Arbolbinario {
public:
    string valor;
};
    class Nodo {
    public:
        Arbolbinario dato;
        Nodo *derecha;
        Nodo *izquierda;
        Nodo *padre;
    };
    Nodo *creacion(Arbolbinario,Nodo *);
    void insertar(Nodo *&, Arbolbinario,Nodo *);

    Nodo *arbol = NULL;
    string regreso ="";


    Nodo


#endif //EDD_PROYECTO1_ARBOLBINARIO_H
