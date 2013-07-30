#include "iohelper.h"

#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

std::vector<std::string> IOHelper::contentsOfFolder(std::string folder) {

	std::vector<std::string> files;

	DIR* directory;

	directory = opendir(folder.c_str());
	if (directory != NULL) {

		struct dirent *dirp;
		while((dirp = readdir(directory))) {

			struct stat filestat;
			std::string filepath = folder + "/" + dirp->d_name;

			// Skip if directory or invalid file.
			if (stat(filepath.c_str(), &filestat) || S_ISDIR(filestat.st_mode)) continue;

			files.push_back(dirp->d_name);
		}
	}
	closedir(directory);

	return files;
}