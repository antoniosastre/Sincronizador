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
    //char** aux;
    
    
    fe.open(fichero);
    if (!fe)
        return 1;
    
        fe.getline(buffer, MAX_FICHERO_CONFIG_LINE_SIZE);
    sincs = atoi(buffer);
    
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