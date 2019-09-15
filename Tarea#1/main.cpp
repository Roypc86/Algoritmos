#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"

using namespace std;

//struct timespec strart_time;

int esCorrecto(int *arreglo, int tamano){
    printf("Arreglo desordenado de tamano: %d [ ",tamano);
    int contador=0;
    for (int ind=0; ind<tamano; ind++){
        printf("%d ,",*(arreglo+ind));
        if(ind>0){
            if(*(arreglo+ind)<(*(arreglo+ind-1))){
                printf("\n \n FALLO \n \n");
                return 0;
            }
        }
        contador++;
    }
    printf(" ] contador: %d /n ",contador);
}
void seleccion(int * arreglo, int tamano){
    int min=0;
    int temp=0;
    for (int ind=0; ind<tamano-1; ind++){
        min=ind;
        for(int ind2=ind; ind2<tamano; ind2++){
            if(arreglo[ind2]< arreglo[min]){
                min=ind2;
                ///printf("Minimo: "<< *(arreglo+min)<<endl;
            }
        }
        temp=arreglo[ind];
        arreglo[ind]= arreglo[min];
        arreglo[min]=temp;
    }
    //esCorrecto(arreglo, tamano);
}

void insercion(int * arreglo, int tamano){
    int num=0;
    int pos=0;

    for(int ind=0; ind<tamano; ind++){
        num=arreglo[ind];//se salva el numero a compararr
        pos=ind;
        while((pos>0)&&(num<arreglo[pos-1])){
            arreglo[pos]=arreglo[pos-1];
            pos--;
        }
        arreglo[pos]=num;
    }
    }

void mergesortAux(int * arreglo, int ini, int fin);
void merge(int *arreglo, int ini,int media, int fin);

void mergesort(int * arreglo, int tamano){
    mergesortAux(arreglo, 0, tamano);
}


void mergesortAux(int * arreglo, int ini, int fin){
    if(ini<fin){
        int media=(ini+fin)/2;
        mergesortAux(arreglo,ini, media);
        mergesortAux(arreglo,media+1, fin);
        merge(arreglo, ini, media, fin);
    }
}

void imprima( string nombre, int *arreglo,int tamano){
    //printf("\t ", nombre);
    for(int ind=0; ind<tamano; ind++){
        printf(", %d",arreglo[ind]);
    }
}
void merge(int *arreglo, int ini,int media, int fin){
    ///Arreglos auxiliares

    int tamAux1=media-ini+1;
    int tamAux2=fin-media;
    int aux1[tamAux1];
    int aux2[tamAux2];
    int contAux1=0;
    int contAux2=0;
    int ptrIni=ini;
    
    for(int indAux1=0; indAux1<(media-ini+1); indAux1++){
        aux1[indAux1]= arreglo[ini+indAux1];
    }
    for(int indAux2=0; indAux2<(fin-media); indAux2++){
        aux2[indAux2]= arreglo[indAux2+media+1];
    }
        while((contAux1<tamAux1) &&(contAux2<tamAux2)){///Ordenamiento de los registros aux
        if(aux1[contAux1]<aux2[contAux2]){
            arreglo[ptrIni]=aux1[contAux1];
            contAux1++;
        }else{
            arreglo[ptrIni]=aux2[contAux2];
            contAux2++;
        }
        ptrIni++;
    }
    ///Recorrido en busca de elementos sobrantes
    while(contAux1<tamAux1){
        arreglo[ptrIni]= aux1[contAux1];
        contAux1++;
        ptrIni++;
    }
    while(contAux2<tamAux2){
        arreglo[ptrIni]= aux2[contAux2];
        contAux2++;
        ptrIni++;
    }
}


int main()
{
    srand(time(NULL));
    int tamano=100000;
    int num=0;
    printf("Digite el tamano \t");
    
    int arreglo[tamano];
    for(int ind=0; ind<tamano; ind++){
        num=rand()%tamano;
        arreglo[ind]=num;
    }
   // printf("Arreglo desordenado de tamano: %d [",tamano);
    //for(int ind=0; ind<tamano; ind++){
     //   printf("%d ,",arreglo[ind]);
    //}
    //printf(" ]");
   // printf(" \n Seleccion: %d \n", tamano);
    
    //struct timespec start_time;
	//clock_gettime(CLOCK_MONOTONIC, &start_time);
	
//    seleccion( arreglo, tamano);
    
  //  struct timespec final_time;
    //clock_gettime(CLOCK_MONOTONIC, &final_time);


    //printf("\n Insercion: %d \n ", tamano);
    //struct timespec start_time;
//	clock_gettime(CLOCK_MONOTONIC, &start_time);	
  //  insercion(arreglo, tamano);
    //struct timespec final_time;
   //clock_gettime(CLOCK_MONOTONIC, &final_time);
   
	struct timespec start_time;
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
    printf( "Ordenamiento por mezcla %d \n ", tamano);
    mergesort(arreglo, tamano);
    
    struct timespec final_time;
    clock_gettime(CLOCK_MONOTONIC, &final_time);
    
    double timeDuration= final_time.tv_sec - start_time.tv_sec+ 1e-9*(final_time.tv_nsec - start_time.tv_nsec);
    printf("Time execution: %.9fls \n", timeDuration); 
    return 0;
}
