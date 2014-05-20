todo: sincro funciones main
	g++ -o ./bin/sincronizador ./obj/main.o ./obj/funciones.o ./obj/Sincronizacion.o -L ./lib -lficheros
	
funciones:
	g++ -c -o ./obj/funciones.o ./src/funciones.cpp -I ./include

sincro:
	g++ -c -o ./obj/Sincronizacion.o ./src/Sincronizacion.cpp -I ./include

main:
	g++ -c -o ./obj/main.o ./src/main.cpp -I ./include