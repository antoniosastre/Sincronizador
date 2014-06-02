//
//  funciones.h
//  MP Practica 1
//
//  Created by Antonio Sastre on 10/04/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Sincronizacion.h"

void mostrarSincronizaciones(Sincronizacion &sinc);                             //Listo
void ejecutarSincronizaciones(Sincronizacion &sinc);
void ejecutarSincronizaciones(char *c1, char *c2, Sincronizacion &sinc);
void ayuda();                                               //Listo
bool cargarFicheroCfg(char *ubic, Sincronizacion &sinc);                          //Listo
void anadirSincronizacion(char *c1, char *c2, int opt, Sincronizacion &sinc);   //Listo
void borrarSincronizacion(char *c1, char *c2, Sincronizacion &sinc);              //Listo
