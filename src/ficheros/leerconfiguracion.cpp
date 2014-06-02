#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

#define MAX_FICHERO_CONFIG_LINE_SIZE 5000


int LeerConfiguracion(const char *fichero, char **&carpetas1, char **&carpetas2, int *&tipos, int &n){
    
    ifstream fe;
    int sincs;
    char buffer[MAX_FICHERO_CONFIG_LINE_SIZE+1];
    
    
    fe.open(fichero);
    if (!fe)
        return 1;
    
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
    sincs = atoi(buffer);
    
    carpetas1 = new char *[sincs];
    carpetas2 = new char *[sincs];
    tipos = new int [sincs];
    
    int control;
    
    for (int i=0; i<sincs; i++) {
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        control = atoi(buffer);
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        if (control == strlen(buffer)) {
            carpetas1[i] = new char [strlen(buffer)+1];
            strcpy(carpetas1[i], buffer);
        }else{
            cout << "[[Archivo de configuración CORRUPTO]]" << endl;
        }
        
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        control = atoi(buffer);
        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        if (control == strlen(buffer)) {
            carpetas2[i] = new char [strlen(buffer)+1];
            strcpy(carpetas2[i], buffer);
        }else{
            cout << "[[Archivo de configuración CORRUPTO]]" << endl;
        }

        
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
        
        tipos[i] = atoi(buffer);
        
        if (atoi(buffer) != 1 && atoi(buffer) != 2) {
            cout << "[[Archivo de configuración CORRUPTO]]" << endl;
        }
        
        
    }
    
    n=sincs;
    
    fe.close();
    
    return 0;

}