
#ifndef HIKERS_PROGRAM_BRIDGES_HPP
#define HIKERS_PROGRAM_BRIDGES_HPP
#include <vector>
#include <hikers/src/hiker.hpp>
#include <memory>
#include <algorithm>

namespace bridge {
class Bridge {

	std::string name_;
	float length_;

	//the bridge object is pointed by a unique_ptr since each bridge is unique in the forest
	//but each bridge has a vector of shared_ptr that can point to the hikers that will cross the bridge
	//the choice of vector<> is due to the fact that we want to iterate through all hikers and sort them
	std::vector<std::shared_ptr<hiker::Hiker>> hikers_;

public:
	Bridge(const std::string&, float length);
	void addHiker(const std::shared_ptr<hiker::Hiker>&);
	void sortHikers();
	float computeCrossingTime();
	const std::vector<std::shared_ptr<hiker::Hiker>>& getHikers();
};

}


#endif //HIKERS_PROGRAM_BRIDGES_HPP
