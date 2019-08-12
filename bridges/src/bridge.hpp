
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
	std::vector<std::shared_ptr<hiker::Hiker>> hikers_;

public:
	Bridge(const std::string&, float length);

	void addHiker(const std::shared_ptr<hiker::Hiker>&);

	void sortHikers();
	float computeCrossingTime();



};

}


#endif //HIKERS_PROGRAM_BRIDGES_HPP
