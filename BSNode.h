#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
        // miembros públicos
	T elem;
	BSNode<T>* left;
	BSNode<T>* right;

	//constructor
	BSNode(T elem): elem(elem),left(nullptr),right(nullptr){}

	friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
	
		out<<"Elemento Nodo: "<< bsn.elem;

		return out;
	}
    
};

#endif
