#include <iostream>
#include <forest/src/forest.h>
#include <experimental/filesystem>

int main() {

	YAML::Node config;
	try {
		//current directory is /bin but example.yaml is one level up
		auto path = std::experimental::filesystem::current_path();
		config = YAML::LoadFile(path.generic_string()+"/../example.yaml");
	} catch(...){
		std::cout << "error loading yaml file" << std::endl;
		return -1;
	}

  // create forest object
	forest::Forest forest;

	//parse input yaml file
	forest.parseInputFile(config);

	//compute fastest crossing time on all bridges in the forest
	float fastest_time = forest.computeFastestCrossingTime();
	std::cout << "the fastest crossing time is: " << fastest_time << std::endl;

	return 0;
}