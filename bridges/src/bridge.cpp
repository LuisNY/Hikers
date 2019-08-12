
#include "bridge.hpp"

namespace bridge {

struct comparator {
	bool operator()(std::shared_ptr<hiker::Hiker> i, std::shared_ptr<hiker::Hiker> j){
		return i->getSpeed() > j->getSpeed();
	}
};

Bridge::Bridge(const std::string& name, float length) : name_(name), length_(length) {}


void Bridge::addHiker(const std::shared_ptr<hiker::Hiker> & hiker) {
  hikers_.push_back(hiker);
}


void Bridge::sortHikers() {

	std::sort(hikers_.begin(), hikers_.end(), comparator());

	for(auto h:hikers_){
		std::cout << h->getName() << std::endl;
	}
}

float Bridge::computeCrossingTime() {

	sortHikers(); //sort hikers in vector so that the gastest is in first position etc..
	float time=0;

	


	return time;
}


}