#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>
#include <unistd.h>

using namespace std;

bool eliminarCarpeta(const char *nombre) {
	return rmdir(nombre)==0;
}

