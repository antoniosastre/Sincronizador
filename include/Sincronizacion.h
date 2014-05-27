//
//  Sincronizacion.h
//  MP Practica 2
//
//  Created by Antonio Sastre on 13/05/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __MP_Practica_2__Sincronizacion__
#define __MP_Practica_2__Sincronizacion__

#include <iostream>
#include "ficheros.h"

class Sincronizacion{
    
public:
    
    Sincronizacion();
    Sincronizacion(const char* fichero);
    ~Sincronizacion();
    void imprimir();
    void insertar(char *c1, char *c2, int opt);
    void eliminar(char *c1, char *c2);
    void ejecutar();
    void ejecutar(char *c1, char *c2);
    
private:
    
    char *fichero;
    int sincros;
    char **carpetas1;
    char **carpetas2;
    int *tipos;
    int config;
    //char barra[2];
    
    
    void ejecutar(char *c1, char *c2, int opt);
    
    
    
    
    
};





#endif /* defined(__MP_Practica_2__Sincronizacion__) */
