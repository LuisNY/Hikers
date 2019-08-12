#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/node/convert.h>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/detail/node.h>
#include <yaml-cpp/node/detail/node_data.h>

#include <forest/src/forest.h>

int main() {

	YAML::Node config = YAML::LoadFile("/home/luigipepe/hikers/example.yaml");
  //std::vector<std::shared_ptr<hiker::Hiker>> hikers;

  // create forest and initialize number of bridges found in input file
  int num_bridges = static_cast<int>(config["bridges"].size());
	forest::Forest forest(num_bridges);

	//iterate through bridges found in yaml file, create a new object for each bridge
	//and move unique_ptr to this obbect to vector container in forest object
	if(config["bridges"]) {
		std::cout << config["bridges"].size() << " bridges" << std::endl;
		for(auto br : config["bridges"]){
			std::cout << br.first.as<std::string>() << " is " << br.second["length"].as<int>() << std::endl;
			std::string name =  br.second["name"].as<std::string>();
			float len = br.second["length"].as<int>();
			forest.addBridge(std::move(std::make_unique<bridge::Bridge>(name, len)));
		}
	}

	//iterate through hikers, create new object for each hiker in yaml file,
	//and associate each hiker with the bridge that he/she is crossing
	if(config["hikers"]) {
		std::cout << config["hikers"].size() << " hikers" << std::endl;
		for(auto hiker : config["hikers"]) {
			std::cout << hiker.first.as<std::string>()  << std::endl;
			std::cout << hiker.second["name"].as<std::string>() << "  " << hiker.second["speed"].as<float>() << std::endl;
			std::string name = hiker.second["name"].as<std::string>();
			float speed = hiker.second["speed"].as<float>();
			std::cout << hiker.second["bridges"].size() << " bridges" << std::endl;
			for(auto br : hiker.second["bridges"]){
        std::cout << "br name: " << br["name"].as<std::string>() << std::endl;
        std::cout << "br len: " << br["length"].as<std::string>() << std::endl;

        auto new_hiker = std::make_shared<hiker::Hiker>(name, speed);
        for(auto it = forest.bridges_.begin(); it!=forest.bridges_.end(); it++){
					if((*it)->getName() == br["name"].as<std::string>()) {
						std::cout << "trovato " << (*it)->getName() << std::endl;
						(*it)->addHiker(new_hiker);
					}
        }

			}
		}
	}


	bridge::Bridge("coa", 12);
	hiker::Hiker h("A", 100);
	std::cout << "first hiker: name " << h.getName() << ", speed " << h.getSpeed();


	return 0;
}