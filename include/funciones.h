//
//  funciones.h
//  MP Practica 1
//
//  Created by Antonio Sastre on 10/04/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Sincronizacion.h"

void mostrarSincronizaciones(Sincronizacion *sinc);
void ejecutarSincronizaciones();
void ejecutarSincronizaciones(char *c1, char *c2);
void ayuda();
Sincronizacion * cargarFicheroCfg(char *ubic);
void anadirSincronizacion(char *c1, char *c2, char *opt);
void borrarSincronizacion(char *c1, char *c2);
void salir();
