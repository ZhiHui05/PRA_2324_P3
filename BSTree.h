#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
//TERMINADO SERACH E INSERT
//FALTA AUN
template <typename T> 
class BSTree {
    private:
        //miembros privados
	int nelem; //Nº elementos almacenados en ABB
	BSNode<T> *root;// Nodo raíz 
	
//======================================
	//Buscador de elementos
	BSNode<T>* search(BSNode<T> *n, T e) const{
		if (n == nullptr){
			throw std::runtime_error("Elemento no encontrado");				}
		else if( n.elem < e){
			return search(n.right,e);
		}
		else if (n.elem > e){
			return search(n.left,e);
		}
		else
			return  n;
	}
//=====================================
	BSNode<T>* insert(BSNode<T>* n, T e){
		if (n == nullptr){
			return new BSNode<T>(e);
		}
		else if ( n.elem == e){
			throw std::runtime_error("Elemento ya existente");
		}
		else if ( n.elem < e){
			return insert(n.right,e);
		}
		else
			return insert(n.left,e);
		return n;
	}


    public:
        // miembros públicos
    	BSTree():nelem(0),root(nullptr){}
//======================================
	int size() const{
		return nelem;
	}
//=======================================
	T search(T e) const{
		return search(root,e);
	}
//======================================
	T operator[](T e) const{
		return search (e);
	}
//======================================
	void insert(T e){
		root = insert(root,e);
	}
//=====================================
};

#endif
