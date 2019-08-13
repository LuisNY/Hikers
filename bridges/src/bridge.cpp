
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
		//std::cout << "adding " << length_/h->getSpeed() << std::endl;
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

	//set initial time to 0 min
	float time = 0;

	//set index to last elem of time_vect
	auto index = num_hikers-1;

	//add to 'time' the time for all obligated trips needed to bring hikers back and forth
	while(index>1){
		time += time_vect[index] + time_vect[0];
		index -= 2;
	}

	//at this point 'time' does not includes all trips yet
	//we create here two additional time variables: 'time_temp1' and 'time_temp2'
	//but we will only add the minimum of these two to 'time' variable
	float time_temp1 = 0,  time_temp2 = 0;

	index = num_hikers-2;
	while(index>1){
		time_temp1 += time_vect[index] + time_vect[0];
		index -= 2;
	}
	time += time_vect[1];

	//'factor' is an even number given by the number of hikers after the first two
	//and adjusted by 1 in case this number is odd
	//'factor' is used to compute time_temp2
	auto factor = ((num_hikers-2)%2==0 ? num_hikers-2 : num_hikers-3);
	time_temp2 = time_vect[1] * factor;

	//finally add to the already partially computed 'time'
	//the min value between 'time_temp1' and 'time_temp2'
	time += std::min(time_temp1, time_temp2);

	std::cout << "time for this bridge is " << time << std::endl;
	return time;
}



}