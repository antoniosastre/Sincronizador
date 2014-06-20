#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int GuardarConfiguracion(const char *fichero, char **carpetas1, char **carpetas2, int *tipos, int n){
    
    std::ofstream fs(fichero);
    
    //Comprobamos que se ha abierto el fichero.
    if (!fs.good()) {
        cerr << "ERROR: No se pudo abrir para escritura " << fichero << endl;
        return -1;
    }
    
    
    
    //Guardamos el número de sincronizaciones en la primera línea.
    
    fs << n << endl;
    
    
    //Por cada sincronización...
    for (int i=0; i<n; i++) {
        
        //Se guarda el nº de caracteres y el nombre de la carpeta de origen
        fs << strlen(carpetas1[i]) << endl;
        fs << carpetas1[i] << endl;
        
        //Y de la de destino
        fs << strlen(carpetas2[i]) << endl;
        fs << carpetas2[i] << endl;
        
        //Y el tipo de sincronización
        fs << tipos[i] << endl;
        
    }
    
    
    fs.close();
    
    
    
    return 0;
}