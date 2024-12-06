#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
#include "TableEntry.h"
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
	T search(BSNode<T> *n, T e) const{
		if (n == nullptr){
			throw std::runtime_error("Elemento no encontrado");				}
		else if((n->elem) < e){
			return search(n->right,e);
		}
		else if ((n->elem) > e){
			return search(n->left,e);
		}
		else
			return  n->elem;
	}
//=====================================
	BSNode<T>* insert(BSNode<T>* n, T e){
		if (n == nullptr){
			return new BSNode<T>(e);
		}
		else if (( n->elem) == e){
			throw std::runtime_error("Elemento ya existente");
		}
		else if ( (n->elem) < e){
			n->right = insert(n->right,e);
		}
		else
			n->left = insert(n->left,e);
		return n;
	}
//======================================
	void print_inorden(std::ostream &out, BSNode<T>* n)const{
		if(n != nullptr){
			print_inorden(out,n->left);
			out<< n->elem <<" ";
			print_inorden(out,n->right);

		}
	}
//=====================================
	BSNode<T>* remove(BSNode<T>* n, T e){
		if( n == nullptr){
		throw std::runtime_error("Error Tree vacío");
		}	
		else if ((n->elem) < e){
			n->right = remove(n->right,e);
		}
		else if ((n->elem) > e){
			n->left = remove(n->left,e);
		}
		else{
			if (n->left != nullptr && n->right != nullptr){
			n->elem = max (n->left);
			n->left = remove_max(n->left);
			}
			else {// 1 ó 0 descendientes
			     n = (n->left != nullptr) ? n->left: n->right;
			}
		}
		return n;
	}


//=====================================
	T max(BSNode<T>* n) const{
		if (n == nullptr){
		throw std::runtime_error("Error root vacío");
		}	
		else if(n->right != nullptr){
		return max(n->right);
		}
		else return n->elem;
	}

//=====================================
	BSNode<T>* remove_max(BSNode<T>* n){
		if ( n->right == nullptr){
			return n->left;
		}	
		else {
			n->right = remove_max(n->right);
			return n;
		}
	}
//=====================================
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
		nelem++;
	}
//======================================
	friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
	out<<"[";
	bst.print_inorden(out,bst.root);
	out<<"]";
	
	return out;
	}
//=====================================
	void remove (T e){
		root = remove( root ,e);
		nelem--;
	}



};

#endif
