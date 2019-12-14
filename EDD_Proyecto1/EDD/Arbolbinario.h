//
// Created by MSI on 12/12/2019.
//
/*


#ifndef EDD_PROYECTO1_ARBOLBINARIO_H
#define EDD_PROYECTO1_ARBOLBINARIO_H


#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Arbolbinario {
public:
    string dato;

    class Nodo {
    public:
        Arbolbinario *valor;
        Nodo *derecha;
        Nodo *izquierda;
        Nodo *padre;
    };


    Nodo *arbol = NULL;
    Nodo *arbol2 = NULL;
    string regreso = "";


    Nodo *creacion(Arbolbinario arbol, Nodo *padre) {
        Nodo *nuevo = new Nodo();

        nuevo->dato = arbol;
        nuevo->derecha = NULL;
        nuevo->izquierda = NULL;
        nuevo->padre = padre;
        return nuevo;
    }

    void replaceChars(string &modifyMe, const string &findMe, const string &newChars) {
        size_t i = modifyMe.find(findMe, 0);
        if (i != string::npos)
            modifyMe.replace(i, findMe.size(), newChars);
    }


    void insertar(Nodo *&arbol, Arbolbinario abb, Nodo *padre) {
        if (arbol == NULL) {
            Nodo *temp = creacion(abb, padre);
            arbol = temp;
            cout << "raiz" << endl;
        } else {
            if (!busqueda(arbol, abb)) {
                string datoraiz = arbol->dato.valor;
                if ((abb.valor) < (datoraiz)) {
                    insertar(arbol->izquierda, abb, arbol);
                    cout << "nodo a la izquierda" << endl;
                } else {
                    insertar(arbol->derecha, abb, arbol);
                    cout << "nodo a la derecha" << endl;
                }
            } else {
                cout << "ya existe el nodo" << abb.valor << endl;
            }
        }
    }

    bool busqueda(Nodo *arbol, Arbolbinario abb) {
        if (arbol == NULL) {
            cout << "El arbol esta vacio" << endl;
            return false;

        } else if (arbol->dato.valor == abb.valor) {

            cout << "nodo encontrado" << endl;
            return true;
        } else if (abb.valor < arbol->dato.valor) {
            return busqueda(arbol->izquierda, abb);
        } else {
            return busqueda(arbol->derecha, abb);
        }
    }

    void mostrar(Nodo *arbol, int aux) {
        if (arbol == NULL) { return; }
        else {
            mostrar(arbol->derecha, aux + 1);
            for (int i = 0; i < aux; i++) {
                cout << " ";
            }
            cout << arbol->dato.valor << endl;
            mostrar(arbol->izquierda, aux + 1);
        }
    }


};

#endif //EDD_PROYECTO1_ARBOLBINARIO_H
*/
