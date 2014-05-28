#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>


using namespace std;

int getCarpeta(const char *dir, char **&files, int &n) {

	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir)) == 0) {
		return -1;
	}

	n= 0;
	while ((dirp = readdir(dp)) != 0) {
		n++;
	}

	closedir(dp);

	n-= 2; // Quitamos 2 por la carpeta "." y la carpeta ".."
	files= new char *[n];
	if (files == 0)
		return -2;

	dp= opendir(dir);
	
	int j= 0;
	for (int i= 0; i<n+2; i++) {

		dirp= readdir(dp);
		if ((strcmp(dirp->d_name, ".") != 0) && (strcmp(dirp->d_name, "..") != 0)) {
			files[j]= new char [strlen(dirp->d_name)+1];

			if (files[j] == 0) {
				for (int k= 0; k<j; k++)
					delete [] files[k];
				delete [] files;
				files= 0;
				n= 0;
				return -2;
			}

			strcpy(files[j], dirp->d_name);
			j++;
		}
	}
		

	return 0;
}

