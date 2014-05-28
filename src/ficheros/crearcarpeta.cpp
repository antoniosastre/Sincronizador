#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>

using namespace std;


bool crearCarpeta(const char *nombre) {

	return mkdir(nombre, S_IRWXU | S_IRWXG | S_IRWXO)==0;
}

