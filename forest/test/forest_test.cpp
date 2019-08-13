#include <iostream>
#include <vector>
#include <assert.h>
#include "../src/forest.h"
#include <experimental/filesystem>
int main(){

	YAML::Node config;
	try {
		auto path = std::experimental::filesystem::current_path();
		std::cout <<path.generic_string() << std::endl;
		config = YAML::LoadFile(path.generic_string()+"/../../../forest/test/test.yaml");
	} catch(...){
		std::cout << "error loading yaml file" << std::endl;
		assert(false);
		return -1;
	}

	forest::Forest f;
	f.parseInputFile(config);

	//make sure parseInputFile() works properly
	assert(f.getBridges().size() == 1);
	assert(f.getBridges().find("item_1") != f.getBridges().end());
	assert(f.getBridges().find("item_1")->first == "item_1");
	assert(f.getBridges().find("item_1")->second->getHikers().size() == 1);
	assert(f.getBridges().find("item_1")->second->getHikers()[0]->getSpeed() == 12);
}