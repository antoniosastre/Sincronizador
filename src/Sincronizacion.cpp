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
    strcpy(this->fichero, fichero);
    correcto = LeerConfiguracion(fichero, carpetas1, carpetas2, tipos, sincros);
    
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
        }else{
            cout << "   Tipo: " << tipos[i] << endl << endl;
        }
        
    }
    
}

void Sincronizacion::insertar(char *c1, char *c2, int opt){
    
    bool existe = false;
    int guardado = -1;
    
    for (int i=0 ; i < sincros; i++) {
        
            if (strcmp(c1,carpetas1[i]) == 0 && strcmp(c2,carpetas2[i]) == 0) {
                existe = true;
            }
        
    }
    
    if(!existe){
        
        
        char ** ncarpetas1, ** ncarpetas2;
        
        
        ncarpetas1= new char *[sincros+1];
        ncarpetas2= new char *[sincros+1];
        
        int * ntipos= new int[sincros+1];

        
        for (int i = 0; i<sincros; i++) {
            ncarpetas1[i] = new char[strlen(carpetas1[i])+1];
            strcpy(ncarpetas1[i], carpetas1[i]);
        }

        
        for (int i = 0; i<sincros; i++) {
            ncarpetas2[i] = new char[strlen(carpetas2[i])+1];
            strcpy(ncarpetas2[i], carpetas2[i]);
        }
        
        for (int i = 0; i<sincros; i++) {
            ntipos[i]= tipos[i];
        }
        
        ncarpetas1[sincros] = new char[strlen(c1)+1];
        strcpy(ncarpetas1[sincros], c1);
        ncarpetas2[sincros] = new char[strlen(c2)+1];
        strcpy(ncarpetas2[sincros], c2);
        
        ntipos[sincros]=opt;
        
        guardado = GuardarConfiguracion(this->fichero, ncarpetas1, ncarpetas2, ntipos, sincros+1);
        
        for (int i = sincros-1; i>=0; i--) {
            delete [] carpetas1[i];
        }
        
        for (int i = sincros; i>=0; i--) {
            delete [] ncarpetas1[i];
        }
        
        delete [] carpetas1;
        delete [] ncarpetas1;

        
        for (int i = sincros-1; i>=0; i--) {
            delete [] carpetas2[i];
        }
        
        for (int i = sincros; i>=0; i--) {
            delete [] ncarpetas2[i];
        }
        delete [] carpetas2;
        delete [] ncarpetas2;
        
        delete [] tipos;
        delete [] ntipos;
        
        LeerConfiguracion(fichero, carpetas1, carpetas2, tipos, sincros);
        
    }
    
    if (guardado == 0 && !existe) {
        cout << "[[Enlace de sincronización: \"" << c1 << " - " << c2 << " - " << opt << "\" añadido]]" << endl;
    }else if(existe){
        cout << "[[Enlace de sincronización entre \"" << c1 << " y " << c2 << "\" ya existente]]" << endl;
    }else if (guardado != 0){
        cout << "[[El enlace de sincronización: \"" << c1 << " - " << c2 << " - " << opt << "\" no se ha podido guardar en la configuración]]" << endl;
    }else{
        cout << "[[Imprime algo]]" << endl;
    }
    
    
}


void Sincronizacion::eliminar(char *c1, char *c2){
    
    bool existe = false;
    int posicion = -1;
    int borrado = -1;
    
    for (int i=0 ; i < sincros; i++) {
        
            if (strcmp(c1,carpetas1[i]) == 0 && strcmp(c2,carpetas2[i]) == 0) {
                existe = true;
                posicion = i;
            }
        
    }
    
    if(existe){
        
        
        char ** ncarpetas1, ** ncarpetas2;
        
        
        ncarpetas1= new char *[sincros-1];
        ncarpetas2= new char *[sincros-1];
        
        int * ntipos= new int[sincros-1];
        
        int j = 0;
        for (int i = 0; i<sincros-1; i++) {
           
            if (i!=posicion){
            ncarpetas1[j] = new char[strlen(carpetas1[i])+1];
            strcpy(ncarpetas1[j], carpetas1[i]);
                j++;
            }
    
        }
        
        j=0;
        for (int i = 0; i<sincros-1; i++) {
            
            if (i!=posicion){
            ncarpetas2[j] = new char[strlen(carpetas2[i])+1];
            strcpy(ncarpetas2[j], carpetas2[i]);
                j++;
            }
        }
        
        j=0;
        for (int i = 0; i<sincros-1; i++) {
            
            if (i!=posicion){
            ntipos[i]= tipos[i];
                j++;
            }
        }
        
        borrado = GuardarConfiguracion(this->fichero, ncarpetas1, ncarpetas2, ntipos, sincros-1);
        
        
        for (int i = sincros-1; i>=0; i--) {
            delete [] carpetas1[i];
        }
        
        for (int i = sincros-2; i>=0; i--) {
            delete [] ncarpetas1[i];
        }
        delete [] carpetas1;
        delete [] ncarpetas1;
        
        for (int i = sincros-1; i>=0; i--) {
            delete [] carpetas2[i];
        }
        
        for (int i = sincros-2; i>=0; i--) {
            delete [] ncarpetas2[i];
        }
        
        delete [] carpetas2;
        delete [] ncarpetas2;
        
        delete [] tipos;
        delete [] ntipos;
        
        LeerConfiguracion(fichero, carpetas1, carpetas2, tipos, sincros);
        
    }
    
    if (borrado == 0 && existe) {
        cout << "[[Enlace de sincronización: \"" << c1 << " - " << c2 << " - " << "\" borrado]]" << endl;
    }else if(!existe){
        cout << "[[Enlace de sincronización entre \"" << c1 << " y " << c2 << "\" no existente]]" << endl;
    }else if (borrado != 0){
        cout << "[[El enlace de sincronización: \"" << c1 << " - " << c2 << " - " << "\" no se ha podido borrar de la configuración]]" << endl;
    }
    
    
}
