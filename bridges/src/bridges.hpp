
#ifndef HIKERS_PROGRAM_BRIDGES_HPP
#define HIKERS_PROGRAM_BRIDGES_HPP
#include <vector>
#include <hikers/src/hiker.hpp>

namespace bridge {
class Bridge {

	float length_;
	std::vector<hiker::Hiker> hikers_;

public:
	Bridge(float length);
};

}


#endif //HIKERS_PROGRAM_BRIDGES_HPP
