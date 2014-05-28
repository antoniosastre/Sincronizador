#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>


using namespace std;



bool esFichero(char *archivo) {

	struct stat _buf;
	stat(archivo, &_buf);
	return !S_ISDIR(_buf.st_mode);
}

