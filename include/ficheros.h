/**
  * @file ficheros.h
  * @brief Fichero cabecera de las funciones para el proyecto de MP
  *
  */
#ifndef __FICHEROS__H__PROFESOR
#define __FICHEROS__H__PROFESOR


/**
 * @brief Comprueba si el contenido de dos ficheros es el mismo
 * @param f1 Nombre del primer fichero a comparar
 * @param f2 Nombre del segundo fichero a comparar
 * @return true si los dos ficheros tienen el mismo contenido, false en caso contrario
 *
 */
bool compararFicheros(const char* f1, const char* f2);



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
int LeerConfiguracion(const char *fichero, char **&carpetas1, char **&carpetas2, int *&tipos, int &n);




/**
 * @brief Guarda la configuración de sincronización a un fichero de configuración válido. En caso de existir este fichero previamente al uso de esta función, queda sobrescrito. Un fichero de configuración válido es aquel cuya primera línea contiene el número de sincronizaciones contenidas en el fichero. Seguidamente, el fichero contiene todas las sincronizaciones. Hay grupos de 5 líneas por cada sincronización, donde la primera es el número de caracteres de la segunda; la segunda contiene el nombre de la primera carpeta a sincronizar; la tercera línea contiene el número de caracteres de la cuarta; la cuarta contiene el nombre de la segunda carpeta a sincronizar; y la quinta línea contiene el tipo de sincronización (valor 1 ó 2). Ver el fichero config.cfg como ejemplo.
 * @param fichero Nombre del fichero de configuración a crear
 * @param carpetas1 lista de primeras carpetas de cada sincronización
 * @param carpetas2 lista de segundas carpetas de cada sincronización
 * @param tipos lista de tipos de cada sincronización
 * @param n Número de sincronizaciones 
 * @pre Los parámetros de salida carpetas1, carpetas2 y tipos tienen memoria reservada con memoria dinámica para, al menos, n componentes. La primera sincronización se corresponde con los parámetros (carpetas1[0], carpetas2[0], tipos[0]); la segunda, con los parámetros (carpetas1[1], carpetas2[1], tipos[1]), etc., hasta la n-ésima configuración, contenida en los parámetros (carpetas1[n-1], carpetas2[n-1], tipos[n-1]). Ver el fichero ejemplos.cpp para comprobar ejemplo de su uso.
 * @post Si la función se ejecuta sin devolver error, se crea en la carpeta indicada el fichero de configuración dado por el parámetro fichero.
 * @return El valor 0 si el fichero de configuración se creó correctamente, y valor distinto de cero en caso contrario.
 *
 */
int GuardarConfiguracion(const char *fichero, char **carpetas1, char **carpetas2, int *tipos, int n);



/**
 * @brief Comprueba si un fichero pasado por argumento es fichero o no
 * @param archivo Nombre del fichero a comprobar su tipo
 * @pre El archivo de entrada debe existir. En caso contrario, no se asegura el correcto funcionamiento de la función
 * @return El valor 0 si archivo es un fichero, o distinto de 0 en caso contrario (es carpeta o no existe)
 *
 */
bool esFichero(char *archivo);


/**
 * @brief Obtiene los ficheros y carpetas contenidos en un directorio dado
 * @param dir Nombre del directorio del que se desea conocer su contenido
 * @param files Parámetro de salida con los nombres de ficheros y carpetas dentro del directorio dir. Es reservado con memoria dinámica dentro de la función, por lo que es responsabilidad del usuario de esta función liberar dicha memoria. Se recomienda leer el fichero ejemplos.cpp para ver un ejemplo de uso de esta función.
 * @param n Parámetro de salida con el número de componentes en files
 * @pre dir debe existir y ser una carpeta. En caso contrario, no se asegura el correcto funcionamiento de la función
 * @post En caso de ejecutarse sin errores, la función devuelve en files un vector de cadenas de caracteres reservado dentro de la función con memoria dinámica. Este vector tiene tamaño n.
 * @return El valor 0 si no hubo errores, o distinto de 0 en caso contrario
 *
 */
int getCarpeta(const char *dir, char **&files, int &n);



/**
 * @brief Comprueba el tamaño de un fichero pasado por argumento
 * @param archivo Nombre del fichero a comprobar su tamaño
 * @pre El archivo de entrada debe existir. En caso contrario, no se asegura el correcto funcionamiento de la función
 * @return El tamaño del fichero pasado por argumento
 *
 */
int tamFichero(char *archivo);



/**
 * @brief Comprueba la fecha de última modificación de un fichero pasado por argumento
 * @param archivo Nombre del fichero a comprobar su fecha de última modificación
 * @pre El archivo de entrada debe existir. En caso contrario, no se asegura el correcto funcionamiento de la función
 * @return Un código entero con un valor que indica la fecha y hora de última modificación del fichero. A mayor valor, más reciente es el fichero.
 *
 */
int ultimaModificacion(char *archivo);



/**
 * @brief Crea una carpeta cuyo nombre es pasado por argumento
 * @param nombre Nombre de la carpeta a crear
 * @post De ejecutarse sin devolver error, la carpeta cuyo nombre se pasa por argumento es creada en la ruta especificada
 * @return true si se pudo crear la carpeta, false en caso contrario.
 *
 */
bool crearCarpeta(const char *nombre);


/**
 * @brief Elimina una carpeta cuyo nombre es pasado por argumento. Dicha carpeta no debe contener ficheros.
 * @param nombre Nombre de la carpeta a eliminar
 * @post De ejecutarse sin devolver error, la carpeta cuyo nombre se pasa por argumento es eliminada en la ruta especificada. 
 * @return true si se pudo eliminar la carpeta, false en caso contrario.
 *
 */
bool eliminarCarpeta(const char *nombre);


/**
 * @brief Copia un fichero origen en otro destino
 * @param origen Nombre del fichero origen
 * @param destino Nombre del fichero destino
 * @pre El fichero origen debe existir previa ejecución de esta función
 * @post De ejecutarse sin devolver error, el fichero de nombre destino se crea, con el mismo contenido que el fichero origen
 * @return true si se pudo copiar el fichero origen en el fichero destino, false en caso contrario.
 *
 */
bool copiarFichero(const char *origen, const char *destino);


/**
 * @brief Elimina un fichero 
 * @param fichero Nombre del fichero a eliminar
 * @pre El fichero debe existir previa ejecución de esta función
 * @post De ejecutarse sin devolver error, el fichero de nombre fichero se elimina
 * @return true si se pudo eliminar el fichero, false en caso contrario.
 *
 */
bool eliminarFichero(const char *fichero);

#endif
