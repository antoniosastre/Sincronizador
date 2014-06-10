#include <cstdio>

bool eliminarFichero(const char *fichero){
    return std::remove(fichero)==0;
}