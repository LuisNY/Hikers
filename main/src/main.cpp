#include <iostream>
#include <forest/src/forest.h>

int main() {

	std::string path_to_file;
	std::cout << "Enter path to input file: " << std::endl;
	std::cin >> path_to_file;

	YAML::Node file;
	try {
		file = YAML::LoadFile(path_to_file);
	} catch(...){
		std::cout << "Error loading yaml file" << std::endl;
		return -1;
	}

  // create forest object
	forest::Forest forest;

	//parse input yaml file
	forest.parseInputFile(file);

	//compute fastest crossing time on all bridges in the forest
	float fastest_time = forest.computeFastestCrossingTime();
	std::cout << "The fastest crossing time is: " << fastest_time << std::endl;

	return 0;
}