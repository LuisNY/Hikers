#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/node/convert.h>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/detail/node.h>
#include <yaml-cpp/node/detail/node_data.h>
#include <sys/file.h>
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
	}

  // create forest and initialize number of bridges found in yaml file
  int num_bridges = static_cast<int>(config["bridges"].size());
	forest::Forest forest(num_bridges);

	//iterate through bridges found in yaml file, create a new object for each bridge
	//and move unique_ptr to this object to vector contained in forest object
	if(config["bridges"]) {
		std::cout << "found " << config["bridges"].size() << " bridges" << std::endl;
		for(auto br : config["bridges"]){
			std::cout << br.first.as<std::string>() << " is " << br.second["length"].as<int>() << std::endl;
			auto name =  br.second["name"].as<std::string>();
			auto len = br.second["length"].as<float>();
			forest.addBridge(std::move(std::make_unique<bridge::Bridge>(name, len)), name);
		}
	}

	//iterate through hikers, create new object for each hiker found in yaml file,
	//and associate each hiker with the bridge that he/she is crossing
	if(config["hikers"]) {
		std::cout << "found " << config["hikers"].size() << " hikers" << std::endl;
		for(auto hiker : config["hikers"]) {
			std::cout << hiker.first.as<std::string>()  << std::endl;
			std::cout << hiker.second["name"].as<std::string>() << "  " << hiker.second["speed"].as<float>() << std::endl;
			auto hiker_name = hiker.second["name"].as<std::string>();
			auto hiker_speed = hiker.second["speed"].as<float>();

			//create new hiker object
			auto new_hiker = std::make_shared<hiker::Hiker>(hiker_name, hiker_speed);

			for(auto br : hiker.second["bridges"]){
				auto bridge_name = br["name"].as<std::string>();

				if(forest.getBridges().find(bridge_name) != forest.getBridges().end()){
					std::cout << hiker_name << " will cross " << bridge_name << std::endl;
					//add a shared_ptr to new hiker object to a vector of shared_ptr in bridge object
					//the bridge object is pointed by a unique_ptr since each bridge is unique in the forest
					forest.getBridges().find(bridge_name)->second->addHiker(new_hiker);
				}
			}
		}
	}


	forest.computeFastestCrossingTime();

	return 0;
}