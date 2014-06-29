#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>


using namespace std;

#define MAX_FICHERO_CONFIG_LINE_SIZE 5000


int LeerConfiguracion(const char *fichero, char **&carpetas1, char **&carpetas2, int *&tipos, int &n){
    
    ifstream fe;
    int sincs;
    char buffer[MAX_FICHERO_CONFIG_LINE_SIZE+1];
    
    fe.open(fichero);
<<<<<<< HEAD
    if (!fe){
        ofstream temp(fichero);
        temp.close();
        fe.open(fichero);
    }
    if (!fe)  return -1;
=======
    if (!fe)
        //Aquí debería crear el fichero porque no existe.
        //Luego debería seguir normalmente.
        return -1;
>>>>>>> FETCH_HEAD
    
    fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
    sincs = atoi(buffer);
    
    int control;
    
    //Comprobación de integridad del fichero.
    //Primero se lee completamente el fichero para comprobar que los datos son consistentes.
    
    for (int i=0; i<sincs; i++) {
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        control = atoi(buffer);
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        if (control != strlen(buffer)) {
            cout << "[[Archivo de configuración CORRUPTO]]" << endl;
            return -1;
        }
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        control = atoi(buffer);
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        if (control != strlen(buffer)) {
            cout << "[[Archivo de configuración CORRUPTO]]" << endl;
            return -1;
        }
        
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        if (atoi(buffer) != 1 && atoi(buffer) != 2) {
            cout << "[[Archivo de configuración CORRUPTO]]" << endl;
            return -1;
        }
        
        
    }
    
    fe.close();
    
    
    //Lectura del fichero.
    //En la segunda lectura, sabiendo que los datos son correctos, guardamos los datos.
    
    fe.open(fichero);
    if (!fe)
        return -1;
    
    fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
    
    carpetas1 = new char *[sincs];
    carpetas2 = new char *[sincs];
    tipos = new int [sincs];
    
    
    for (int i=0; i<sincs; i++) {
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        carpetas1[i] = new char [strlen(buffer)+1];
        strcpy(carpetas1[i], buffer);
        
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        carpetas2[i] = new char [strlen(buffer)+1];
        strcpy(carpetas2[i], buffer);
        
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        tipos[i] = atoi(buffer);
        
    }
    
    n=sincs;
    
    fe.close();
    
    return 0;
    
}