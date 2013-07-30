#include "iohelper.h"

#include <iostream>
#include <string>
#include <vector>

int main() {

	std::vector<std::string> files = IOHelper::contentsOfFolder("xyz");

	for (std::vector<std::string>::iterator file = files.begin(); file != files.end(); ++file) {
		
		std::cout << *file << std::endl;
	}

	return 0;
}