#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"
#define MAX(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

//constructor
ABB::ABB(){
  this->raiz=NULL;
  this->n=0;
}

//destructor
ABB::~ABB(){
  if (raiz != NULL){
    eliminarSubarbol(this->raiz);
  }   
}

void ABB::insertar (int nuevoElemento){
  Nodo* aux= new Nodo;
  aux->contenido = nuevoElemento;
  aux->padre = NULL;
  aux->hijoIzquierdo = NULL;
  aux->hijoDerecho = NULL;

  if (n == 0){
    this->raiz = aux;
  }else{
    Nodo* buscarPadre = buscarHueco(raiz, nuevoElemento);
    if (nuevoElemento <= buscarPadre->contenido){
      buscarPadre->hijoIzquierdo = aux;
    }else{
      buscarPadre->hijoDerecho = aux;
    }
    aux->padre = buscarPadre;
  }

  this->n++;
}

Nodo* ABB::buscar(int elementoABuscar){
  return buscarRecursivo(this->raiz, elementoABuscar);
}

void ABB::eliminar (int elementoAEliminar){
  Nodo* aux=buscar(elementoAEliminar);
  eliminarNodo(aux);

  n--;
  if (n == 0){
    raiz = NULL;
  }
      
}

bool ABB::esABB(){
  return esSubABB(this->raiz);
}

bool ABB::esAVL(){
  return (esSubABB(this->raiz) && esSubAVL(this->raiz));
}

void ABB::eliminarSubarbol (Nodo *raizSubarbol){
  assertdomjudge(raizSubarbol != NULL);

  if (raizSubarbol->hijoIzquierdo != NULL){
    eliminarSubarbol(raizSubarbol->hijoIzquierdo);
  }  

  if (raizSubarbol->hijoDerecho != NULL){
    eliminarSubarbol(raizSubarbol->hijoDerecho);
  }
      

  Nodo* aux = raizSubarbol->padre;
  if (aux != NULL){
    if (aux->hijoIzquierdo == raizSubarbol){
      aux->hijoIzquierdo = NULL;
    }
        
    if (aux->hijoDerecho == raizSubarbol){
      aux->hijoDerecho = NULL;
    }
          
  }

  delete raizSubarbol;
}

Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){
  assertdomjudge(raizSubarbol != NULL);

  if (elementoAInsertar <= raizSubarbol->contenido){
    if (raizSubarbol->hijoIzquierdo != NULL){
      return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
    }else{
      return raizSubarbol;
    } 
  }else{
    if (raizSubarbol->hijoDerecho != NULL){
      return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
    }else{
      return raizSubarbol;
    }  
  }
}

Nodo* ABB::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar){
  if (raizSubarbol == NULL){
    return NULL;
  } else{

    if (raizSubarbol->contenido == elementoABuscar){
      return raizSubarbol;
    }else if (elementoABuscar < raizSubarbol->contenido){
      return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    }else{
      return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    }
          
  }
}

Nodo* ABB::buscarMaximo (Nodo *raizSubarbol){
  assertdomjudge(raizSubarbol != NULL);

  if (raizSubarbol->hijoDerecho == NULL){
    return raizSubarbol;
  }else{
    return buscarMaximo(raizSubarbol->hijoDerecho);
  }
      
}

Nodo* ABB::buscarMinimo (Nodo *raizSubarbol){
  assertdomjudge(raizSubarbol != NULL);

  if (raizSubarbol->hijoIzquierdo == NULL){
    return raizSubarbol;
  }else{
    return buscarMinimo(raizSubarbol->hijoIzquierdo);
  }
      
}

void ABB::eliminarNodo (Nodo *nodoParaEliminar){
  Nodo* aux = NULL;

    if (nodoParaEliminar != NULL){
      if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL){
        Nodo* aux2 = nodoParaEliminar->padre;

        if(aux2!=NULL){
          if (aux2->hijoIzquierdo == nodoParaEliminar){
            aux2->hijoIzquierdo = NULL;
          }
            
          if (aux2->hijoDerecho == nodoParaEliminar){
            aux2->hijoDerecho = NULL;
          }
                
        }
        delete nodoParaEliminar;

      }else{
        if (nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho != NULL){
          if (alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo)){
            aux = buscarMinimo(nodoParaEliminar->hijoDerecho);
          }else{
            aux = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
          }    
        }else if (nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL){
          aux = buscarMinimo(nodoParaEliminar->hijoDerecho);
        }else{
          aux = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        }
        
        nodoParaEliminar->contenido = aux->contenido;
        eliminarNodo(aux);

      }
  }
}

int ABB::alturaNodo(Nodo *raizSubarbol){
  if (raizSubarbol == NULL){
    return -1;
  }else{
    return (MAX(alturaNodo(raizSubarbol->hijoIzquierdo), alturaNodo(raizSubarbol->hijoDerecho)) + 1);
  }
        
}

bool ABB::esSubABB(Nodo *raizSubarbol){
  if (raizSubarbol == NULL){
    return true;
  }else{
    bool esABBI = true;
    if (raizSubarbol->hijoIzquierdo != NULL){
      esABBI = (buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido < raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoIzquierdo);
    }
    bool esABBD = true;

    if (raizSubarbol->hijoDerecho != NULL){
      esABBD = (buscarMinimo(raizSubarbol->hijoDerecho)->contenido > raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoDerecho);
    }
        
    return (esABBI && esABBD);

  }
}

bool ABB::esSubAVL(Nodo *raizSubarbol){
  if (raizSubarbol == NULL){
    return true;
  }else{
    int a = alturaNodo(raizSubarbol->hijoDerecho) - alturaNodo(raizSubarbol->hijoIzquierdo);
    return (a > -2 && a < 2 && esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho));
  }
}

void ABB::imprimir(){
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol){
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

void ABB::leerArbol(){
  raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre){
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}


