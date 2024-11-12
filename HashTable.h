#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!
//#include "../PRA_2324_P1/Node.h"
//#include "../PRA_2324_P1/List.h"
template <typename V>
class HashTable: public Dict<V> {

    private:
	int n;//Nº elementos alamacendos en tabla hash
	int max;//Tamñ tabla hash / Nº total de cubetas 
	ListLinked<TableEntry<V>>* table;//Tabla de cubetas: representada por un array de punteros a lista enlazadas(ListLinked) que almacenan pares clave->valor(TableEntry)

    public:
	int h(std::string key){
	
	}
	
	HashTable(int size):max(size),n(0){
		table = new ListLinked<TableEntry<V>>[max];
	}
	
	~HashTable(){
	delete[] table;	
	}
        
	int capacity(){
	return max;
	}
	
	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
	
	
	
	}

	V operator[](std::string key){
	
	}
//FUNCIONES ABSTRACTAS DE DICT======================


	void insert(std::string key, V value) override{
	
	
	}

	V search(std::string key) override{
	
	
	}

	V remove(std::string key) override{
	
	
	}

	int entries()override{
	
	
	}

};

#endif
