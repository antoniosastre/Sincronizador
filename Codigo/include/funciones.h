//
//  funciones.h
//  MP Practica 1
//
//  Created by Antonio Sastre on 10/04/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Sincronizacion.h"


/*
 *  Funciones auxiliares para las acciones pasadas por parámetros.
 *
 */


void mostrarSincronizaciones(Sincronizacion &sinc); //Lista las sincronizaciones.
void ejecutarSincronizaciones(Sincronizacion &sinc); //Ejecuta todas las sincronizaciones
void ejecutarSincronizaciones(char *c1, char *c2, Sincronizacion &sinc); // Ejecuta sólo la sincronización especificada.
void ayuda(); //Muestra la ayuda por la salida estándar
bool cargarFicheroCfg(char *ubic, Sincronizacion &sinc); //Carga un fichero de configuración.
void anadirSincronizacion(char *c1, char *c2, int opt, Sincronizacion &sinc); //Añade una sincronización a la lista.
void borrarSincronizacion(char *c1, char *c2, Sincronizacion &sinc); //Elimina una sincronización de la lista (y el fichero de configuración)