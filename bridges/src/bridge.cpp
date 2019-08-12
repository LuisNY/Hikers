
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

	auto num_hikers = hikers_.size();

	//build vector with time of crossing for each hiker
	std::vector<float> time_vect;
	for(const auto& h : hikers_){
		std::cout << "adding " << length_/h->getSpeed() << std::endl;
		time_vect.push_back(length_/h->getSpeed());
	}

	//if hikers are 0 return 0
	if(num_hikers==0){
		return 0;
	}

	//if hikers are less than 3 return crossing time of slowest hiker
	if(num_hikers<3){
		return time_vect[num_hikers-1];
	}

	//decide what algo to use
	if(time_vect[1]*2 > time_vect[0]*time_vect[2]){
		return greedyAlgo(time_vect);
	} else {
		return classicAlgo(time_vect);
	}
}

float Bridge::classicAlgo(const std::vector<float>& time_vect){
	float time=0;
	std::cout << "classic algo" << std::endl;
	return time;
}

float Bridge::greedyAlgo(const std::vector<float>& time_vect) {
	float time=0;
	std::cout << "greedy algo" << std::endl;

	auto index = time_vect.size()-1;
	std::cout << "original index " << index << std::endl;
	while(index>0){
		std::cout << "current index " << index << std::endl;
		std::cout << "add " << time_vect[index] << std::endl;
		time += time_vect[index];
		index--;
		if(index>=1){
			std::cout << "add " << time_vect[0] << std::endl;
			time += time_vect[0];
		}
	}
	std::cout << "tot time " << time << std::endl;
	return time;
}


}