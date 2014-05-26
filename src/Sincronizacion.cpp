//
//  Sincronizacion.cpp
//  MP Practica 2
//
//  Created by Antonio Sastre on 13/05/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Sincronizacion.h"
#include <iostream>
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
    
    cout   << "Imprimiendo" << endl;
}
