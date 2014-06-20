#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;



bool copiarFichero(const char *origen, const char *destino){
    
    ifstream ifile(origen);
    ofstream ofile(destino);
    char carac;
    
    //Comprobamos que se han abierto correctamente los dos ficheros.
    
    if (!ifile.good() && !ofile.good()) {
        
        cerr << "ERROR: No se pudo abrir para lectura: " << origen << endl;
        cerr << "ERROR: No se pudo abrir para escritura: " << destino << endl;
        return false;
        
    }else if (!ifile.good()) {
        
        cerr << "ERROR: No se pudo abrir para lectura: " << origen << endl;
        ofile.close();
        return false;
        
    }else if (!ofile.good()){
        
        cerr << "ERROR: No se pudo abrir para escritura: " << destino << endl;
        ifile.close();
        return false;
        
    }else{
        
        while (!ifile.eof()) {
            
            //Hacemos una copia caracter a caracter. Más lenta pero más sencilla.
            
            carac = ifile.get();
            if (!ifile.eof())
                ofile.put(carac);
        }
        
        
        // Cerrar los ficheros
        ifile.close();
        ofile.close();
        
        return true;
        
    }
}