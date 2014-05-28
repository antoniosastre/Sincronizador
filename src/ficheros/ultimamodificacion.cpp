#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>


using namespace std;






int ultimaModificacion(char *archivo) {

	struct stat _buf;
	stat(archivo, &_buf);
	return _buf.st_mtime/100;
}

