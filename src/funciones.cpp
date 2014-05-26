//
//  funciones.cpp
//  MP Practica 1
//
//  Created by Antonio Sastre on 10/04/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "funciones.h"
#include <iostream>
#include "Sincronizacion.h"


using namespace std;
Sincronizacion sinc;

void mostrarSincronizaciones(){
    cout << "Sincronizaciones del fichero de configuración:" << endl;
    sinc.imprimir();
}

void ejecutarSincronizaciones(){
    cout << "[[Aquí se ejecutan las sincronizaciones]]" << endl;
}

void ejecutarSincronizaciones(char *c1, char *c2){
    cout << "[[Solo se ejecuta la sincronización entre: \"" << c1 << " y " << c2 << "\" pasada por argumento]]" << endl;
}

void ayuda(){
    cout << endl;
    cout << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Sincronizador de carpetas. Autor: Antonio Sastre." << endl;
    cout << "Uso del programa:" << endl;
    cout << "      <nombre del programa> [opciones]" << endl;
    cout << "Opciones:" << endl;
    cout << "   -c cfgfile : Indica el fichero de configuración a utilizar." << endl;
    cout << "   -e c1 c2 opcion : Enlaza la carpeta c1 con la carpeta c2, utilizando la opción de enlazado indicada. Esta opción deberá ser valor 1 para que c2 sea copia exacta de c1 y el valor 2 para que la sincronización sea mutua entre carpetas." << endl;
    cout << "       Ejemplo de uso:" << endl;
    cout << "           <nombre del programa> -c cfgfile.cfg –e /myfolder1 /myfolder2 2" << endl;
    cout << "   -r c1 c2 : Elimina el enlace de sincronización entre las carpetas c1 y c2 del fichero de configuración indicado." << endl;
    cout << "       Ejemplo de uso:" << endl;
    cout << "           <nombre del programa> -c cfgfile.cfg –r /myfolder1 /myfolder2" << endl;
    cout << "   -s : Sincroniza todas las carpetas accesibles según fichero de configuración indicado." << endl;
    cout << "       Ejemplo de uso:" << endl;
    cout << "       -s c1 c2 : Ejecuta la sincronización entre las dos carpetas dadas por argumento." << endl;
    cout << "           <nombre del programa> -c cfgfile.cfg –s /myfolder1 /myfolder2" << endl;
    cout << "   -h : Muestra este mensaje de ayuda." << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
}

void cargarFicheroCfg(char *ubic){
    cout << "[[Carga de fichero .cfg: " << ubic << "]]"<< endl;
    sinc = Sincronizacion(ubic);
}

void anadirSincronizacion(char *c1, char *c2, char *opt){
    cout << "[[Añade la sincronización: \"" << c1 << " - " << c2 << " - " << opt << "\" a la lista]]"<< endl;
    sinc.insertar(c1, c2, opt);
}

void borrarSincronizacion(char* c1, char *c2){
    cout << "[[Borra la sincronización entre: \"" << c1 << " y " << c2 << "\" de la lista]]"<< endl;
}