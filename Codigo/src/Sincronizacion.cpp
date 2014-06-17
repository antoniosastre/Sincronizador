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
    fichero=new char[2];
    carpetas1=new char*[0];
    carpetas2=new char*[0];
    tipos=new int[0];
    sincros=0;
    error=0;
    
}

Sincronizacion :: Sincronizacion(const char* fichero){
    
    int correcto;
    this->fichero = new char[strlen(fichero)+1];
    strcpy(this->fichero, fichero);
    correcto = LeerConfiguracion(this->fichero, carpetas1, carpetas2, tipos, sincros);
    
    if (correcto == 0){
        cout << "[[Fichero leído correctamente. Se han encontrado: " << sincros << " sincronizaciones.]]" << endl;
    }else{
        cout << "[[Error leyendo el archivo de configuracion: " << fichero << " con error "<< correcto << "]]" << endl;
        exit(2);
    }
    
    
}


Sincronizacion :: ~Sincronizacion(){
    
    for (int i = sincros-1; i>=0; i--) {
        delete [] carpetas1[i];
        delete [] carpetas2[i];
    }
    
    delete [] carpetas1;
    delete [] carpetas2;
    
    delete [] tipos;
    delete [] fichero;
    
}

Sincronizacion & Sincronizacion :: operator=(const Sincronizacion &sinc){
    
    this->carpetas1 = new char*[sinc.sincros];
    this->carpetas2 = new char*[sinc.sincros];
    this->tipos = new int[sinc.sincros];
    this->fichero = new char[strlen(sinc.fichero)+1];
    
    strcpy(this->fichero, sinc.fichero);
    this->sincros = sinc.sincros;
    
    for (int i=0; i<sinc.sincros ; i++) {
        this->carpetas1[i]=new char[strlen(sinc.carpetas1[i])+1];
        this->carpetas2[i]=new char[strlen(sinc.carpetas2[i])+1];
        strcpy(this->carpetas1[i], sinc.carpetas1[i]);
        strcpy(this->carpetas2[i], sinc.carpetas2[i]);
        this->tipos[i] = sinc.tipos[i];
    }
    
    
    
    return *this;
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
        
        
        ncarpetas1= new char *[(sincros+1)];
        ncarpetas2= new char *[(sincros+1)];
        
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
        for (int i = 0; i<sincros; i++) {
            
            if (i!=posicion){
                ncarpetas1[j] = new char[strlen(carpetas1[i])+1];
                strcpy(ncarpetas1[j], carpetas1[i]);
                j++;
            }
            
        }
        
        j=0;
        for (int i = 0; i<sincros; i++) {
            
            if (i!=posicion){
                ncarpetas2[j] = new char[strlen(carpetas2[i])+1];
                strcpy(ncarpetas2[j], carpetas2[i]);
                j++;
            }
        }
        
        j=0;
        for (int i = 0; i<sincros; i++) {
            
            if (i!=posicion){
                ntipos[j]= tipos[i];
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
        cout << "[[Enlace de sincronización: \"" << c1 << " - " << c2 << "\" borrado]]" << endl;
    }else if(!existe){
        cout << "[[Enlace de sincronización entre \"" << c1 << " y " << c2 << "\" no existente]]" << endl;
    }else if (borrado != 0){
        cout << "[[El enlace de sincronización: \"" << c1 << " - " << c2 << " - " << "\" no se ha podido borrar de la configuración]]" << endl;
    }
    
    
}


void Sincronizacion::ejecutar(){
    
    for (int i=0; i<sincros; i++) {
        ejecutar(carpetas1[i], carpetas2[i], tipos[i]);
    }
}


void Sincronizacion::ejecutar(char *c1, char *c2){
    
    for (int i=0 ; i < sincros; i++) {
        
        if (strcmp(c1,carpetas1[i]) == 0 && strcmp(c2,carpetas2[i]) == 0) {
            ejecutar(c1, c2, tipos[i]);
            return;
        }
    }
}


void Sincronizacion::ejecutar(char *c1, char *c2, int opt){
    
    int error1;
    int error2;
    
    char **archivos1;
    char **archivos2;
    
    int nf1;
    int nf2;
    
    error1 = getCarpeta(c1, archivos1, nf1);
    error2 = getCarpeta(c2, archivos2, nf2);
    
    if (error1 != 0 || error2 != 0) {
        cout << "[[El programa no puede continuar. Alguna de las carpetas no se puede leer o escribir]]" << endl;
        exit(2);
    }
    
    //---------------------
    //
    //Sincronización tipo 1
    //
    //---------------------
    
    if (opt == 1) {
        int i=0;
        int j=0;
        
        while (i < nf1 || j < nf2) {
            
            if (i < nf1 && j < nf2) {
                
                if (strcmp(archivos1[i],archivos2[j])<0) {
                    char* temp1 = new char[strlen(c1)+strlen(archivos1[i])+2];
                    char* temp2 = new char[strlen(c2)+strlen(archivos1[i])+2];
                    
                    strcpy(temp1, c1);
                    strcat(temp1, "/");
                    strcat(temp1, archivos1[i]);
                    
                    strcpy(temp2, c2);
                    strcat(temp2, "/");
                    strcat(temp2, archivos1[i]);
                    
                    cout << "El archivo " << temp1 << " para la función es fichero da: " << esFichero(temp1) << endl;
                    
                    if (esFichero(temp1)==1) {
                        
                        copiarFichero(temp1, temp2);
                        cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                        
                    }else{
                        crearCarpeta(temp2);
                        ejecutar(temp1, temp2, opt);
                        cout << "Se copia la carpeta " << temp1 << " en " << temp2 << endl;
                    }
                    
                    delete [] temp1;
                    delete [] temp2;
                    i++;
                    
                }else if (strcmp(archivos1[i],archivos2[j])>0){
                    char* temp = new char[strlen(c2)+strlen(archivos2[j])+2];
                    strcpy(temp, c2);
                    strcat(temp, "/");
                    strcat(temp, archivos2[j]);
                    
                    if (esFichero(temp)==1) {
                        
                        eliminarFichero(temp);
                        cout << "Se elimina el fichero " << temp << " de " << c2 << endl;
                        
                    }else{
                        char vacia[6]="vacia";
                        crearCarpeta(vacia);
                        ejecutar(vacia, temp, opt);
                        eliminarCarpeta(temp);
                        eliminarCarpeta(vacia);
                    }
                    delete [] temp;
                    j++;
                    
                }else if (strcmp(archivos1[i],archivos2[j])==0){
                    cout << "Se actualiza el archivo " << archivos1[i] << endl;
                    
                    char* temp1 = new char[strlen(c1)+strlen(archivos1[i])+2];
                    char* temp2 = new char[strlen(c2)+strlen(archivos1[i])+2];
                    
                    strcpy(temp1, c1);
                    strcat(temp1, "/");
                    strcat(temp1, archivos1[i]);
                    
                    strcpy(temp2, c2);
                    strcat(temp2, "/");
                    strcat(temp2, archivos1[i]);
                    
                    cout << temp1 << endl;
                    cout << temp2 << endl;
                    
                    if (esFichero(temp1)==1 && esFichero(temp2)==1){
                        // cout << "Son dos ficheros: " << ultimaModificacion(temp1) << " - " << ultimaModificacion(temp2) << endl;
                        //  if (ultimaModificacion(temp1)>ultimaModificacion(temp2)) {
                        
                        copiarFichero(temp1, temp2);
                        cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                        
                        //   }
                    }else if(esFichero(temp1)==0 && esFichero(temp2)==0){
                        
                        ejecutar(temp1, temp2, opt);
                        
                    }
                    
                    delete [] temp1;
                    delete [] temp2;
                    
                    i++;
                    j++;
                }
                
                
            }else if (i < nf1){
                
                char* temp1 = new char[strlen(c1)+strlen(archivos1[i])+2];
                char* temp2 = new char[strlen(c2)+strlen(archivos1[i])+2];
                
                strcpy(temp1, c1);
                strcat(temp1, "/");
                strcat(temp1, archivos1[i]);
                
                strcpy(temp2, c2);
                strcat(temp2, "/");
                strcat(temp2, archivos1[i]);
                
                cout << "El archivo " << temp1 << " para la función es fichero da: " << esFichero(temp1) << endl;
                
                if (esFichero(temp1)==1) {
                    
                    copiarFichero(temp1, temp2);
                    cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                    
                }else{
                    crearCarpeta(temp2);
                    ejecutar(temp1, temp2, opt);
                    cout << "Se copia la carpeta " << temp1 << " en " << temp2 << endl;
                }
                delete [] temp1;
                delete [] temp2;
                i++;
                
                
            }else if (j < nf2){
                
                char* temp = new char[strlen(c2)+strlen(archivos2[j])+2];
                strcpy(temp, c2);
                strcat(temp, "/");
                strcat(temp, archivos2[j]);
                if (esFichero(temp)==1) {
                    
                    eliminarFichero(temp);
                    cout << "Se elimina el fichero " << temp << " de " << c2 << endl;
                    
                }else{
                    char vacia[6] = "vacia";
                    crearCarpeta(vacia);
                    ejecutar(vacia, temp, opt);
                    eliminarCarpeta(temp);
                    eliminarCarpeta(vacia);
                }
                
                delete [] temp;
                j++;
                
            }
            
        }
        
    }else if(opt == 2){
        
        //---------------------------------------------------
        //
        //Sincronización tipo 2
        //
        //---------------------------------------------------
        
        
        int i=0;
        int j=0;
        
        while (i < nf1 || j < nf2) {
            
            if (i < nf1 && j < nf2) {
                
                if (strcmp(archivos1[i],archivos2[j])<0) {
                    char* temp1 = new char[strlen(c1)+strlen(archivos1[i])+2];
                    char* temp2 = new char[strlen(c2)+strlen(archivos1[i])+2];
                    
                    strcpy(temp1, c1);
                    strcat(temp1, "/");
                    strcat(temp1, archivos1[i]);
                    
                    strcpy(temp2, c2);
                    strcat(temp2, "/");
                    strcat(temp2, archivos1[i]);
                    
                    
                    if (esFichero(temp1)==1) {
                        
                        copiarFichero(temp1, temp2);
                        cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                        
                    }else{
                        crearCarpeta(temp2);
                        ejecutar(temp1, temp2, opt);
                        cout << "Se copia la carpeta " << temp1 << " en " << temp2 << endl;
                    }
                    
                    delete [] temp1;
                    delete [] temp2;
                    i++;
                    
                }else if (strcmp(archivos1[i],archivos2[j])>0){
                    char* temp1 = new char[strlen(c1)+strlen(archivos2[j])+2];
                    char* temp2 = new char[strlen(c2)+strlen(archivos2[j])+2];
                    
                    strcpy(temp1, c1);
                    strcat(temp1, "/");
                    strcat(temp1, archivos2[j]);
                    
                    strcpy(temp2, c2);
                    strcat(temp2, "/");
                    strcat(temp2, archivos2[j]);
                    
                    cout << "El archivo " << temp1 << " para la función es fichero da: " << esFichero(temp1) << endl;
                    
                    if (esFichero(temp2)==1) {
                        
                        copiarFichero(temp2, temp1);
                        cout << "Se copia el fichero " << temp2 << " en " << temp1 << endl;
                        
                    }else{
                        crearCarpeta(temp1);
                        ejecutar(temp2, temp1, opt);
                        cout << "Se copia la carpeta " << temp2 << " en " << temp1 << endl;
                    }
                    
                    delete [] temp1;
                    delete [] temp2;
                    j++;
                    
                }else if (strcmp(archivos1[i],archivos2[j])==0){
                    cout << "Se actualiza el archivo " << archivos1[i] << endl;
                    
                    char* temp1 = new char[strlen(c1)+strlen(archivos1[i])+2];
                    char* temp2 = new char[strlen(c2)+strlen(archivos2[j])+2];
                    
                    strcpy(temp1, c1);
                    strcat(temp1, "/");
                    strcat(temp1, archivos1[i]);
                    
                    strcpy(temp2, c2);
                    strcat(temp2, "/");
                    strcat(temp2, archivos2[j]);
                    
                    cout << temp1 << endl;
                    cout << temp2 << endl;
                    
                    if (esFichero(temp1)==1 && esFichero(temp2)==1){
                        // cout << "Son dos ficheros: " << ultimaModificacion(temp1) << " - " << ultimaModificacion(temp2) << endl;
                        if (ultimaModificacion(temp1)>ultimaModificacion(temp2)) {
                            
                            copiarFichero(temp1, temp2);
                            cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                            
                        }else{
                            
                            copiarFichero(temp2, temp1);
                            cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                            
                        }
                    }else if(esFichero(temp1)==0 && esFichero(temp2)==0){
                        
                        ejecutar(temp1, temp2, opt);
                        
                    }
                    
                    delete [] temp1;
                    delete [] temp2;
                    
                    i++;
                    j++;
                }
                
                
            }else if (i < nf1){
                
                char* temp1 = new char[strlen(c1)+strlen(archivos1[i])+2];
                char* temp2 = new char[strlen(c2)+strlen(archivos1[i])+2];
                
                strcpy(temp1, c1);
                strcat(temp1, "/");
                strcat(temp1, archivos1[i]);
                
                strcpy(temp2, c2);
                strcat(temp2, "/");
                strcat(temp2, archivos1[i]);
                
                cout << "El archivo " << temp1 << " para la función es fichero da: " << esFichero(temp1) << endl;
                
                if (esFichero(temp1)==1) {
                    
                    copiarFichero(temp1, temp2);
                    cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                    
                }else{
                    crearCarpeta(temp2);
                    ejecutar(temp1, temp2, opt);
                    cout << "Se copia la carpeta " << temp1 << " en " << temp2 << endl;
                }
                delete [] temp1;
                delete [] temp2;
                i++;
                
                
            }else if (j < nf2){
                
                char* temp1 = new char[strlen(c1)+strlen(archivos2[j])+2];
                char* temp2 = new char[strlen(c2)+strlen(archivos2[j])+2];
                
                strcpy(temp1, c1);
                strcat(temp1, "/");
                strcat(temp1, archivos2[j]);
                
                strcpy(temp2, c2);
                strcat(temp2, "/");
                strcat(temp2, archivos2[j]);
                
                if (esFichero(temp2)==1) {
                    
                    copiarFichero(temp2, temp1);
                    cout << "Se copia el fichero " << temp2 << " en " << temp1 << endl;
                    
                }else{
                    crearCarpeta(temp1);
                    ejecutar(temp2, temp1, opt);
                    cout << "Se copia la carpeta " << temp2 << " en " << temp1 << endl;
                }
                delete [] temp1;
                delete [] temp2;
                
                j++;
                
            }
            
        }
        
        
        
        
    }
    
    for (int i= nf1-1; i>=0; i--) {
        delete [] archivos1[i];
    }
    
    delete [] archivos1;
    
    for (int i= nf2-1; i>=0; i--) {
        delete [] archivos2[i];
    }
    
    delete [] archivos2;
    
    
    
}










































