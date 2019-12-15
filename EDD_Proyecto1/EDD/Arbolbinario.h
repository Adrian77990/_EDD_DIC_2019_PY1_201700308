//
// Created by MSI on 12/12/2019.
//



#ifndef EDD_PROYECTO1_ARBOLBINARIO_H
#define EDD_PROYECTO1_ARBOLBINARIO_H


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string concatenar = "";

class Nodoarbol {
public:
    Nodoarbol *derecha;
    Nodoarbol *izquierda;
    Nodoarbol *padre;
    string playlist;
};

class Arbolbinario {
public:
    Nodoarbol * raiz =NULL;


    Nodoarbol *crearnodo(string nombreplay)
    {
        Nodoarbol *nuevonodo = new Nodoarbol();
        nuevonodo->playlist = nombreplay;
        nuevonodo->derecha = NULL;
        nuevonodo->izquierda = NULL;
        return nuevonodo;
    }


    bool busqueda(Nodoarbol *raiz, string dato){
         if(raiz==NULL){
             cout<<"Se encuentra vacio"<<endl;
             return false;
         }else if(raiz->playlist == dato){
             cout<<"el dato ya existe"<<endl;
             return true;
         }else if(dato < raiz->playlist){
             return busqueda(raiz->izquierda,dato);
         } else{
             return busqueda(raiz->derecha,dato);
         }
    }

    void declararnodosdot(Nodoarbol *raiz)
    {
        if(raiz==NULL){
            return;
        }else{
            concatenar += raiz->playlist;
            concatenar+="[shape=box, style=filled, fillcolor=white, color=blue, label=<<TABLE border=\"0\" cellborder=\"0\"><TR><TD width=\"45\" height=\"45\" fixedsize=\"true\"><IMG SRC=\"C:/Users/MSI/CLionProjects/EDD_Proyecto1/playlist.png\" scale=\"true\"/>";
            concatenar+="</TD><td><font point-size=\"15\" >";
            concatenar+=raiz->playlist;
            concatenar+="</font></td></TR></TABLE>>]\n";
            concatenar+="\n";
        if(raiz->izquierda !=NULL){
            concatenar += raiz->playlist;
            concatenar+="[shape=box, style=filled, fillcolor=white, color=blue, label=<<TABLE border=\"0\" cellborder=\"0\"><TR><TD width=\"45\" height=\"45\" fixedsize=\"true\"><IMG SRC=\"C:/Users/MSI/CLionProjects/EDD_Proyecto1/playlist.png\" scale=\"true\"/>";
            concatenar+="</TD><td><font point-size=\"15\" >";
            concatenar+=raiz->playlist;
            concatenar+="</font></td></TR></TABLE>>]\n";
            concatenar+="\n";
            declararnodosdot(raiz->izquierda);
        }

            if(raiz->derecha !=NULL){
                concatenar += raiz->playlist;
                concatenar+="[shape=box, style=filled, fillcolor=white, color=blue, label=<<TABLE border=\"0\" cellborder=\"0\"><TR><TD width=\"45\" height=\"45\" fixedsize=\"true\"><IMG SRC=\"C:/Users/MSI/CLionProjects/EDD_Proyecto1/playlist.png\" scale=\"true\"/>";
                concatenar+="</TD><td><font point-size=\"15\" >";
                concatenar+=raiz->playlist;
                concatenar+="</font></td></TR></TABLE>>]\n";
                concatenar+="\n";
                declararnodosdot(raiz->derecha);
            }

        }
    }

    void uniondenodos(Nodoarbol *raiz)
    {
        if(raiz==NULL){
            return;
        }
        else{
            concatenar += raiz->playlist;
            concatenar += "\n";

            if(raiz->izquierda!=NULL){
                concatenar += raiz->playlist;
                concatenar += "->";
                uniondenodos(raiz->izquierda);
            }
            if(raiz->derecha!=NULL){
                concatenar += raiz->playlist;
                concatenar += "->";
                uniondenodos(raiz->derecha);
            }


        }
    }

    void replaceChars(string& modifyMe,const string& findMe, const string& newChars){
        size_t i = modifyMe.find(findMe, 0);
        if(i != string::npos)
            modifyMe.replace(i, findMe.size(), newChars);
    }

    void graficar(string datos){
        FILE *f;
        char direccion[] = "grafo_arbol.txt";
        f = fopen(direccion,"w");
        if(f==NULL)
        {
            cout << "no se creó el archivo" << endl;
        }
        else
        {
            ofstream archivo;
            archivo.open(direccion);

            //--------------------Aqui inicia la escritura del archivo-------------------

            archivo << "digraph G{ " << endl;
            archivo <<"graph [nodesep=0.3];"<<endl;
            archivo<<"node[shape=box];"<<endl;
//    archivo <<
            archivo<<"subgraph cluster_0{"<<endl;
            archivo<<datos<<endl;
            archivo<<"label=\"Arbol Binario De Busqueda\";"<<endl;
            archivo <<"}"<<endl;

            archivo << "}" << endl;

            //---------------------Aqui termina el archivo----------------

            archivo.close();
            system("dot -Tpng grafo_arbol.txt -o grafo_arbol.png");
            system("grafo_arbol.png");

        }
    }

    void insertarenelarbol(Nodoarbol *& raiz, string nombre)
    {
        if(raiz==NULL){
            Nodoarbol *nuevonodo = crearnodo(nombre);
            raiz = nuevonodo;
            cout<<"raiz creada"<<endl;
        }
        else{
            if(!busqueda(raiz,nombre)){
                string valor = raiz->playlist;
                if(nombre < valor){
                    insertarenelarbol(raiz->izquierda,nombre);
                    cout<<"inserto a la izquierda"<<endl;
                }else{
                    insertarenelarbol(raiz->derecha,nombre);
                    cout<<"inserto a la derecha"<<endl;
                }

            }else{
                //cout<<"ya existe el nodo"<<endl;
            }
        }
    }

};










#endif //EDD_PROYECTO1_ARBOLBINARIO_H

