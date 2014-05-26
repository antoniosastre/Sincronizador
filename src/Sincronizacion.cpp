//
//  Sincronizacion.cpp
//  MP Practica 2
//
//  Created by Antonio Sastre on 13/05/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Sincronizacion.h"
#include <iostream>
#include <cstring>
using namespace std;




Sincronizacion :: Sincronizacion(){
    
}

Sincronizacion :: Sincronizacion(const char* fichero){
    
    int correcto;
    correcto = LeerConfiguracion("config.cfg", carpetas1, carpetas2, tipos, sincros);
    
    if (correcto == 0){
    cout << "[[Fichero leído correctamente. Se han encontrado: " << sincros << " sincronizaciones.]]" << endl;
    }else{
        cout << "[[Error leyendo el archivo de configuracion: " << fichero << " con error "<< correcto << "]]" << endl;
    }
    
    
}

void Sincronizacion::imprimir(){
    
    cout << endl;
    
    for (int i = 0; i < sincros; i++) {
        
        cout << "[Sincro " << i+1 << "]" << endl;
        cout << "   Orig: " << carpetas1[i] << endl;
        cout << "   Dest: " << carpetas2[i] << endl;
        
        if (tipos[i] == 1) {
            cout << "   Tipo: Orig -> Dest" << endl << endl;
        }else if (tipos[i] == 2){
            cout << "   Tipo: Orig <-> Dest" << endl << endl;
        }
        
    }
    
}

void Sincronizacion::insertar(char *c1, char *c2, char *opt){
    
    for (int i=0 ; i < sincros; i++) {
        for (int j=0 ; j < sincros; j++) {
            
            if (i != j && strcmp(&c1[i],carpetas1[j]) == 0 && strcmp(&c2[i],carpetas2[j]) == 0) {
                
            }
            
        }
    }
    
    
}
