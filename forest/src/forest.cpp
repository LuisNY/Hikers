
#include "forest.h"

namespace forest {

	//add a bridge object to the map of bridges
  void Forest::addBridge(std::unique_ptr<bridge::Bridge>&& bridge, const std::string& name) {
    bridges_.insert(std::make_pair(name,std::move(bridge)));
  }

	//read the map of bridges
  const std::unordered_map<std::string, std::unique_ptr<bridge::Bridge>>& Forest::getBridges() const {
    return bridges_;
  }

	float Forest::computeFastestCrossingTime() const {
		float tot_time = 0;
		std::cout << "compute crossing time" << std::endl;
		for(auto it = bridges_.begin(); it != bridges_.end(); it++){
			std::cout << it->first << std::endl;
			tot_time += it->second->computeCrossingTime();
		}
		std::cout << "minimum tot time: " << tot_time << std::endl;
		return tot_time;
	}

  void Forest::parseInputFile(const YAML::Node & file) {

		//iterate through bridges found in yaml file, create a new object for each bridge
		//and move unique_ptr to the new bridge object to vector contained in forest object
		if(file["bridges"]) {
			std::cout << "found " << file["bridges"].size() << " bridges" << std::endl;
			for(auto br : file["bridges"]){
				std::cout << br.first.as<std::string>() << " is " << br.second["length"].as<int>() << " ft long" << std::endl;
				auto name =  br.second["name"].as<std::string>();
				auto len = br.second["length"].as<float>();
				addBridge(std::move(std::make_unique<bridge::Bridge>(name, len)), name);
			}
		}

		//iterate through hikers, create new object for each hiker found in yaml file,
		//and associate each hiker with the bridge that he/she is crossing
		if(file["hikers"]) {
			std::cout << "found " << file["hikers"].size() << " hikers" << std::endl;
			for(auto hiker : file["hikers"]) {
				std::cout << "new hiker" << std::endl;
				std::cout << "name: " << hiker.second["name"].as<std::string>() << std::endl;
				std::cout << "speed: " << hiker.second["speed"].as<float>() << "ft/min" << std::endl;
				auto hiker_name = hiker.second["name"].as<std::string>();
				auto hiker_speed = hiker.second["speed"].as<float>();

				//create new hiker object
				auto new_hiker = std::make_shared<hiker::Hiker>(hiker_name, hiker_speed);

				//iterate through all bridges in the forest and associate the new
				//hiker with all the bridges that she's going to cross
				for(auto br : hiker.second["bridges"]){
					auto bridge_name = br["name"].as<std::string>();

					//if hiker is going to cross current bridge
					if(getBridges().find(bridge_name) != getBridges().end()){
						std::cout << hiker_name << " will cross " << bridge_name << std::endl;
						//add a shared_ptr to new hiker object to a vector of shared_ptr in bridge object
						getBridges().find(bridge_name)->second->addHiker(new_hiker);
					}
				}
			}
		}
	}
}