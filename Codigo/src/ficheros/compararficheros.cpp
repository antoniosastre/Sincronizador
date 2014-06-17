#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;


bool compararFicheros(const char* f1, const char* f2){
    
    ifstream file1(f1);
    ifstream file2(f2);
    
    if (!file1.good() && !file2.good()) {
        
        cerr << "ERROR: No se pudo abrir para lectura: " << f1 << endl;
        cerr << "ERROR: No se pudo abrir para lectura: " << f2 << endl;
        return false;
        
    }else if (!file1.good()) {
        
        cerr << "ERROR: No se pudo abrir para lectura: " << f1 << endl;
        file2.close();
        return false;
        
    }else if (!file2.good()){
        
        cerr << "ERROR: No se pudo abrir para lectura: " << f2 << endl;
        file1.close();
        return false;
        
    }else{
        
        while (!file1.eof() && !file2.eof()) {
            
            if(file1.get() != file2.get()){
                file1.close();
                file2.close();
                return false;
            }
            
        }
        
        if (file1.eof() && !file2.eof()){
            file1.close();
            file2.close();
            return false;
        }
        
        if (!file1.eof() && file2.eof()){
            file1.close();
            file2.close();
            return false;
        }
        
        file1.close();
        file2.close();
        
        return true;
        
    }
    
}