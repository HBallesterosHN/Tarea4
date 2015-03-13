#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz == NULL)//caso base de recursividad si el arbol esta vacio
        return 0;
    return raiz->num+suma(raiz->hijo_izq)+suma(raiz->hijo_der);// de lo contrario devuelvo mi suma mas la suma de hijos izquierdos mas la suma de hijos derechos
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
     if(raiz == NULL)//caso base de recursividad si el arbol esta vacio
        return 0;
    int contador =1;//contador se inicializa en 1 para contar la raiz
    contador += cantidadNodos(raiz->hijo_izq);//suma nodos a la izquierda
    contador += cantidadNodos(raiz->hijo_der);//suma nodos a la derecha
    return contador;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
return suma(raiz)/cantidadNodos(raiz);//se utilizan las 2 funciones declaradas arriba, se les manda la raiz y se retorna el promedio del resultado
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    if(raiz==NULL || raiz->num == num)//caso base de recursividad si el arbol esta vacio o el nodo que buscamos esta en la raiz
        return 1;
        int conta=1;//contador se inicializa en 1 para contar la raiz
            if(raiz->num<num) //si el numero es mayor que la raiz
            return conta+= cuantosPasos(raiz->hijo_der,num); //contamos los hijos derechos y retornamos el contador
                else if(raiz->num>num) //si el numero es menor que la raiz
                return conta+= cuantosPasos(raiz->hijo_izq,num); //contamos los hijos izquierdos y retornamos el contador
}

//Devuelve verdadero si el arbol dado esta ordenado estilo AVL, de lo contrario devuelve falso.
int sumaHojas(NodoArbolBinario* raiz)
{
int x=0;// variable acumuladora de ojas
if(raiz == NULL) return NULL;//caso base de recursividad si el arbol esta vacio retornamos 0
        x=(sumaHojas(raiz->hijo_izq)+sumaHojas(raiz->hijo_der)); //si tiene nodos, sumamos las hojas del hijo izquierdo mas las hojas del hijo derecho y lo acumulamos en x
        if(x==NULL)return 1; //si no tenia hojas la raiz se dvuelve 1
        else return x;// si no se devuelve la suma de las hojas de las raices
}
int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
