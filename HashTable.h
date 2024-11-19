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
	
	//Obtenmos la cubeta asociada a la clave
	int h(std::string key){
		int ascii = 0; 
	
		for (int i = 0; i < key.size();i++){
			ascii += int(key.at(i));
		}
		return ascii % max; 
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
		for ( int i = 0; i< th.max;i++){
			out << "Cubo " << i <<":";

			for (int j =0; j <  th.table[i].size();j++){
				out << "["<<th.table[i].get(j).key <<" -> " <<th.table[i].get(j).value<<"] ";
			}
		
			out<< "\n";
		}

		return out;

	}
	
	
	

	V operator[](std::string key){
		int index = h(key);
		//BUsca en la lista enlazada dentro de la cubetaa el valor correspondido
		for (int j = 0; j < table[index].size();j++){
		if (table[index].get(j).key == key){
			return table[index].get(j).value;
			}
		}

		throw std::runtime_error("Clave no encontrada en TablaHash");

	}
//FUNCIONES ABSTRACTAS DE DICT======================


	void insert(std::string key, V value) override{
		int index = h(key);
		TableEntry<V> entry(key,value);
		
		for (int j=0; j < table[index].size();j++){
		if (table[index].get(j).key  == key){
			throw std::runtime_error("Clave ya existente");
			}	
		}
		table[index].prepend(entry);
		n++;
		
	}

	V search(std::string key) override{
		int index = h(key);

		for (int j =0; j < table[index].size();j++){
			if (table[index].get(j).key == key){
				return table[index].get(j).value;
			}	
		}
		throw std::runtime_error("Clave no existente");
	
	}

	V remove(std::string key) override{
		int index = h(key);

		for( int j = 0; j < table[index].size();j++){
			if(table[index].get(j).key == key){
				V value = table[index].get(j).value;
				table[index].remove(j);
				n--;
				return value;
			}
		
		}
		throw std::runtime_error("Clave no encontrada");
	}

	int entries()override{
		return n;
	
	}

};

#endif
