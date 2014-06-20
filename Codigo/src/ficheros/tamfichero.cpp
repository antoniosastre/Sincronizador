#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int tamFichero(char *archivo){
    
    ifstream fe;
    int tam = 0;
    
    fe.open(archivo);
    if (!fe) return -1;
    
    //Calcula el tamaño del fichero en número de caracteres.
    
    while (!fe.eof()) {
        fe.get();
        tam++;
    }
    
    return tam;
}