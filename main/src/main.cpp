#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/node/convert.h>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/detail/node.h>
#include <yaml-cpp/node/detail/node_data.h>

#include <forest/src/forest.h>

int main() {

	YAML::Node config = YAML::LoadFile("/home/luigipepe/hikers/example.yaml");

	if(config["hikers"]) {
		std::cout << config["hikers"].size() << " hikers" << std::endl;
		for(auto hiker : config["hikers"]){
			std::cout << hiker.first.as<std::string>()  << std::endl;
			std::cout << hiker.second["name"].as<std::string>() << "  " << hiker.second["speed"].as<float>() << std::endl;
		}
	}

	if(config["bridges"]) {
		std::cout << config["bridges"].size() << " bridges" << std::endl;
		for(auto br : config["bridges"]){
			std::cout << br.first.as<std::string>() << " is " << br.second["length"].as<int>() << std::endl;
			std::cout << br.second["hikers"].size() << " hikers" << std::endl;
			for(auto h : br.second["hikers"]){
				std::cout << h["name"].as<std::string>() << std::endl;
				std::cout << h["speed"].as<float>() << std::endl;
			}
		}
	}

	forest::Forest f;
	bridge::Bridge(12);
	hiker::Hiker h("A", 100);
	std::cout << "first hiker: name " << h.getName() << ", speed " << h.getSpeed();


	return 0;
}