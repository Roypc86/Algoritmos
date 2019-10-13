#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:
template <typename T>
class llnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia los atributos se dejan publicos.
		T key;
		llnode<T> *prev, *next;
		//enum colors color;

		// Constructor por omision.
		llnode(){
		};

      // Inicializacion de los datos miembro.
		llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y) {};

		~llnode(){

		}
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist{
	public:
		llist(){
            nil=new llnode<T>;
            nil->next=nil;
            nil->prev=nil;
        };
			// Constructor (crea una lista vacia)

		llist(const llist<T>& obj){
            nil=new llnode<T>;
            nil->next=nil;
            nil->prev=nil;

			llnode<T>* copy= obj.nil->prev;
            printf("Valor: %d \t prev: %d \t next: %d \n", copy->key, copy->prev->key, copy->next->key);

			while(copy!=obj.nil){
				listInsert(new llnode<T>(copy->key, copy->prev, copy->next));
				copy=copy->prev;
				printf("Valor: %d \t prev: %d \t next: %d \n", copy->key, copy->prev->key, copy->next->key);
			}

			nil->prev=obj.nil->prev;
			nil->next=obj.nil->next;

		};
			// Constructor copia

		~llist(){
		    delete nil;
		};
			// Destructor (borra la lista)

		llnode<T>* listSearch(const T& k){
            llnode<T>* search= nil->next;
            while((search!=nil)&&(search->key != k)){
                    search=search->next;
            }
            if(search==nil){
                search=NULL;
                printf("Hola desde el NULL search \n");
            }
			return search;
		};
			// Busca la llave iterativamente. Si la encuentra, devuelve un
            // apuntador al nodo que la contiene; sino devuelve NULL.

		void listInsert(llnode<T>* x){
			if(nil->next==nil){
				nil->next= x;
				nil->prev=x;
				x->prev=nil;
				x->next=nil;
			}else{
				x->prev= nil;
				x->next=nil->next;
				x->next->prev=x;
				nil->next=x;
			}
		};
			// Inserta el nodo x en la lista.

		llnode<T>* listDelete(llnode<T>* x){
			llnode<T>* erase= nil->next;
			while((erase!=nil)&&(erase->key != x->key)){
				erase=erase->next;
			}
			if(erase!=nil){
				erase->prev->next=erase->next;
				erase->next->prev=erase->prev;
			}else{
                erase=NULL;
			}
			return erase;
		};
			// Saca de la lista la llave contenida en el nodo apuntado por x.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de el.

		llnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve el nodo centinela. (Para efectos de revision de la tarea).

		private:

		llnode<T> *nil;	    // nodo centinela

};

#endif	// LINKED_LIST_llist
