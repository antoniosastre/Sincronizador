#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int GuardarConfiguracion(const char *fichero, char **carpetas1, char **carpetas2, int *tipos, int n){
    
    std::ofstream fs(fichero);
    
    fs.open(fichero);
    if (!fs.good()) {
        cerr << "ERROR: No se pudo abrir para escritura " << fichero << endl;
        return -1;
    }
    

    
    
    fs << n << endl;
    
    for (int i=0; i<n; i++) {
        
        fs << strlen(carpetas1[i]) << endl;
        fs << carpetas1[i] << endl;
        
        fs << strlen(carpetas2[i]) << endl;
        fs << carpetas2[i] << endl;
        
        fs << tipos[i] << endl;
        
    }
    

    fs.close();

    
    
    return 0;
}