bool existe(char *filename);

bool copiarFichero(const char *origen, const char *destino){
    
    return false;
}

bool existe(char *filename) {
    
    ifstream fichero;
    
    fichero.open(filename);
    if (fichero.good()) {
        
        fichero.close();
        return true;
    }
    
    return false;
}
