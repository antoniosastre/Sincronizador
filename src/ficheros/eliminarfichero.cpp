#include <cstdio>
<<<<<<< HEAD

bool eliminarFichero(const char *fichero){
    return std::remove(fichero)==0;
=======
#include <iostream>

using namespace std;

bool eliminarFichero(const char *fichero){
    
    if( remove(fichero) != 0 ){
        cout << "[[No se ha podido eliminar: " << fichero << " ]]"<< endl;
        return false;
    }else{
        return true;
    }
    
>>>>>>> FETCH_HEAD
}