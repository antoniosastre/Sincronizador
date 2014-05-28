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
                
                //copiarFichero(temp1, temp2);
                cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
                delete [] temp1;
                delete [] temp2;
                i++;
                
            }else if (strcmp(archivos1[i],archivos2[j])>0){
                char* temp = new char[strlen(c2)+strlen(archivos2[j])+2];
                strcpy(temp, c2);
                strcat(temp, "/");
                strcat(temp, archivos2[j]);
                //eliminarFichero(temp);
                cout << "Se elimina el fichero " << temp << " de " << c2 << endl;
                delete [] temp;
                j++;
                
            }else if (strcmp(archivos1[i],archivos2[j])==0){
                cout << "Se respeta el archivo " << archivos1[i] << endl;
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
            
            //copiarFichero(temp1, temp2);
            cout << "Se copia el fichero " << temp1 << " en " << temp2 << endl;
            delete [] temp1;
            delete [] temp2;
            i++;
            
            
        }else if (j < nf2){
            
            char* temp = new char[strlen(c2)+strlen(archivos2[j])+2];
            strcpy(temp, c2);
            strcat(temp, "/");
            strcat(temp, archivos2[j]);
            //eliminarFichero(temp);
            cout << "Se elimina el fichero " << temp << " de " << c2 << endl;
            delete [] temp;
            j++;
            
        }
            
        }
        
    }else if(opt == 2){
        
        
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











































