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
     * @brief Constructor por defecto.
     *
     */
    Sincronizacion();
    
    /**
     * @brief Constructor a partir de un fichero de configuración.
     *
     */
    Sincronizacion(const char* fichero);
    
    /**
     * @brief Mostrar las sincronizaciones por la salida estándar.
     * @post Se muestran las sincronizaciones por la salida estándar.
     */
    void imprimir();
    
    /**
     * @brief Inserta una nueva sincronización entre dos carpetas a la lista de sincronizaciones.
     * @param *c1 Puntero a una cadena-terminada-en-\0 con la ruta de la carpeta de origen.
     * @param *c2 Puntero a una cadena-terminada-en-\0 con la ruta de la carpeta de destino.
     * @param opt Opción de sincronización (1 - De origen a destino, 2 - Mutua);
     */
    void insertar(char *c1, char *c2, int opt);
    
    /**
     * @brief Elimina una sincronización entre dos carpetas de la lista de sincronizaciones.
     * @param *c1 Puntero a una cadena-terminada-en-\0 con la ruta de la carpeta de origen.
     * @param *c2 Puntero a una cadena-terminada-en-\0 con la ruta de la carpeta de destino.
     */
    void eliminar(char *c1, char *c2);
    
    /**
     * @brief Ejecuta las sincronizaciones previamente cargadas del fichero de configuración.
     *
     */
    void ejecutar();
    
    /**
     * @brief Ejecuta exclusivamente la sincronizacion previamente cargada del fichero de configuración y definida en los parámetros..
     * @param *c1 Puntero a una cadena-terminada-en-\0 con la ruta de la carpeta de origen.
     * @param *c2 Puntero a una cadena-terminada-en-\0 con la ruta de la carpeta de destino.
     */
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
    
    
    void ejecutar(char *c1, char *c2, int opt);
    
    
    
    
    
};





#endif /* defined(__MP_Practica_2__Sincronizacion__) */
