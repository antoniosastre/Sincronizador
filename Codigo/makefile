todo: sincro funciones main
	g++ -o ./bin/sincronizador ./obj/main.o ./obj/funciones.o ./obj/Sincronizacion.o -L ./lib -lficheros
	
funciones:
	g++ -c -o ./obj/funciones.o ./src/funciones.cpp -I ./include

sincro: libreria
	g++ -c -o ./obj/Sincronizacion.o ./src/Sincronizacion.cpp -I ./include

main:
	g++ -c -o ./obj/main.o ./src/main.cpp -I ./include

libreria: ficheros
	ar -rcs ./lib/libficheros.a ./obj/ficheros/compararficheros.o ./obj/ficheros/copiarfichero.o ./obj/ficheros/crearcarpeta.o ./obj/ficheros/eliminarcarpeta.o ./obj/ficheros/eliminarfichero.o ./obj/ficheros/esfichero.o ./obj/ficheros/getcarpeta.o ./obj/ficheros/guardarconfiguracion.o ./obj/ficheros/leerconfiguracion.o ./obj/ficheros/tamfichero.o ./obj/ficheros/ultimamodificacion.o

ficheros:
	g++ -c -o ./obj/ficheros/compararficheros.o ./src/ficheros/compararficheros.cpp
	g++ -c -o ./obj/ficheros/copiarfichero.o ./src/ficheros/copiarfichero.cpp
	g++ -c -o ./obj/ficheros/crearcarpeta.o ./src/ficheros/crearcarpeta.cpp
	g++ -c -o ./obj/ficheros/eliminarcarpeta.o ./src/ficheros/eliminarcarpeta.cpp
	g++ -c -o ./obj/ficheros/eliminarfichero.o ./src/ficheros/eliminarfichero.cpp
	g++ -c -o ./obj/ficheros/esfichero.o ./src/ficheros/esfichero.cpp
	g++ -c -o ./obj/ficheros/getcarpeta.o ./src/ficheros/getcarpeta.cpp
	g++ -c -o ./obj/ficheros/guardarconfiguracion.o ./src/ficheros/guardarconfiguracion.cpp
	g++ -c -o ./obj/ficheros/leerconfiguracion.o ./src/ficheros/leerconfiguracion.cpp
	g++ -c -o ./obj/ficheros/tamfichero.o ./src/ficheros/tamfichero.cpp
	g++ -c -o ./obj/ficheros/ultimamodificacion.o ./src/ficheros/ultimamodificacion.cpp