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
    
    /**
     * @brief Lee la configuración de sincronización desde un fichero de configuración válido. Un fichero de configuración válido es aquel cuya primera línea contiene el número de sincronizaciones contenidas en el fichero. Seguidamente, el fichero contiene todas las sincronizaciones. Hay grupos de 5 líneas por cada sincronización, donde la primera es el número de caracteres de la segunda; la segunda contiene el nombre de la primera carpeta a sincronizar; la tercera línea contiene el número de caracteres de la cuarta; la cuarta contiene el nombre de la segunda carpeta a sincronizar; y la quinta línea contiene el tipo de sincronización (valor 1 ó 2). Ver el fichero config.cfg como ejemplo.
     * @param fichero Nombre del fichero de configuración a leer
     * @param carpetas1 Parámetro de salida que contiene la lista de primeras carpetas de cada sincronización
     * @param carpetas2 Parámetro de salida que contiene la lista de segundas carpetas de cada sincronización
     * @param tipos Parámetro de salida que contiene la lista de tipos de cada sincronización
     * @param n Número de sincronizaciones leídas desde fichero
     * @pre Los parámetros de salida de la función no deben tener memoria reservada antes de llamar a esta función
     * @post Si la función no devuelve error, los parámetros de salida carpetas1, carpetas2 y tipos tienen memoria reservada con memoria dinámica, y carpetas1 y carpetas2 se representan como vectores a jirones. Es responsabilidad del usuario de esta función liberar la memoria. Ver el fichero ejemplos.cpp como ejemplo de uso.
     * @return El valor 0 si el fichero de configuración se leyó correctamente, y valor distinto de cero en caso contrario. En caso de leerse correctamente, la primera sincronización se corresponde con los parámetros (carpetas1[0], carpetas2[0], tipos[0]); la segunda, con los parámetros (carpetas1[1], carpetas2[1], tipos[1]), etc., hasta la n-ésima configuración, contenida en los parámetros (carpetas1[n-1], carpetas2[n-1], tipos[n-1])
     *
     */
    
    Sincronizacion();
    Sincronizacion(const char* fichero);
    void imprimir();
    void insertar(char *c1, char *c2, int opt);
    void eliminar(char *c1, char *c2);
    void ejecutar();
    void ejecutar(char *c1, char *c2);
    ~Sincronizacion();
    Sincronizacion & operator=(const Sincronizacion &sinc);
    int sincros;
    int error;
    
private:
    
    char *fichero;
    char **carpetas1;
    char **carpetas2;
    int *tipos;
    int config;
    
    
    void ejecutar(char *c1, char *c2, int opt);
    
    
    
    
    
};





#endif /* defined(__MP_Practica_2__Sincronizacion__) */
