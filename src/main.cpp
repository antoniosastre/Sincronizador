//
//  main.cpp
//  MP Practica 1
//
//  Created by Antonio Sastre on 10/04/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include <iostream>
#include "funciones.h"
#include "Sincronizacion.h"
#include <cstdlib>

using namespace std;


int main(int argc, const char * argv[]){

    int cflag = 0;
    bool mostrarAyuda = false;
    Sincronizacion sinc;

    if (argc<=1) {
        mostrarAyuda = true;
    }else{
    
        for (int i=1; i<argc; i++) {
            if (argv[i][0] == '-' && argv[i][1] == 'h') {
                mostrarAyuda = true;
                
            }else if (argv[i][0] == '-' && argv[i][1] == 'c') {
                
                if(i+1<argc && argv[i+1][0] != '-'){
                    cflag=1;
                    if(!cargarFicheroCfg((char *)argv[++i], sinc)){
                        cout << "[[No se ha podido leer la configuración]]" << endl;
                        return 1;
                    }
                }else{
                    mostrarAyuda = true;
                }
                
            }
        }
        
        
        for (int i=1; i<argc; i++) {
            
            
            if (argv[i][0] == '-' && argv[i][1] == 'e') {
                
                if (cflag==1 && i+3<argc && argv[i+1][0] != '-' && argv[i+2][0] != '-' && argv[i+3][0] != '-'){
                    char *c1 = (char *)argv[++i];
                    char *c2 = (char *)argv[++i];
                    int opt = atoi(argv[++i]);
                    if (opt==1 || opt==2) {
                        anadirSincronizacion(c1, c2, opt, sinc);
                    }else{
                        mostrarAyuda = true;
                    }
                    
                }else{
                    mostrarAyuda = true;
                }
                
                
            }else if(cflag==1 && argv[i][0] == '-' && argv[i][1] == 'l'){

                    mostrarSincronizaciones(sinc);
           
            }else if(argv[i][0] == '-' && argv[i][1] == 's'){
                
                if (cflag==1 && i+2<argc && argv[i+1][0] != '-' && argv[i+2][0] != '-'){
                    char *c1 = (char *)argv[++i];
                    char *c2 = (char *)argv[++i];
                    ejecutarSincronizaciones(c1, c2, sinc);
                    
                }else if(cflag==1){
        
                    ejecutarSincronizaciones(sinc);
                
                }else{
                   mostrarAyuda = true;
                }

                
            }else if(argv[i][0] == '-' && argv[i][1] == 'r'){
                
                
                if (cflag==1 && i+2<argc && argv[i+1][0] != '-' && argv[i+2][0] != '-'){
                    char *c1 = (char *)argv[++i];
                    char *c2 = (char *)argv[++i];
                    borrarSincronizacion(c1, c2, sinc);
                    
                }else{
                    mostrarAyuda = true;
                }
                
            }
            
        }
 
    }
    
    if (mostrarAyuda) ayuda();
    
    return 0;
}