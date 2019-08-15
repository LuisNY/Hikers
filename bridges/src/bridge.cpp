
#include "bridge.hpp"

namespace bridge {

//needed comparator to sort the vector of shared_ptr
struct comparator {
	bool operator()(std::shared_ptr<hiker::Hiker> i, std::shared_ptr<hiker::Hiker> j){
		return i->getSpeed() > j->getSpeed();
	}
};

//constructor
Bridge::Bridge(const std::string& name, float length) : name_(name), length_(length) {}

//add pointer to new hiker that will cross this bridge
void Bridge::addHiker(const std::shared_ptr<hiker::Hiker> & hiker) {
  hikers_.push_back(hiker);
}

const std::vector<std::shared_ptr<hiker::Hiker>>& Bridge::getHikers(){
	return hikers_;
}

//sort hikers according to their speed such that the fastest is at index 0
void Bridge::sortHikers() {

	std::sort(hikers_.begin(), hikers_.end(), comparator());
}

//compute minimum time required for all hikers to cross this bridge
float Bridge::computeCrossingTime() {

	sortHikers(); //sort hikers in vector so that the fastest is in first position etc..

	auto num_hikers = hikers_.size();

	//build a new vector with time it takes for each hiker to cross this bridge
	std::vector<float> time_vect;
	for(const auto& h : hikers_){
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

	//set index to last elem of time_vect
	auto index = num_hikers-1;

	//set initial time (CMT) to 0 min
	float CMT = 0;

	//add to 'time' the minimum time required to complete the trips that the two algorithms have in common
	while(index>1){
		CMT += time_vect[index] + time_vect[0];
		index -= 2;
	}
		CMT += time_vect[1];

	//at this point 'time' does not includes the time to complete all trips yet
	//we create here two additional time variables: 'RTo' and 'RTc'
	//but we will only add the minimum of these two to 'time' variable
	//RTo uses the 'obvious' algorithm while RTc uses the 'classic' algorithm
	float RTo = 0,  RTc = 0;

	//obvious algo, fastest hiker crosses back and forth each time
	index = num_hikers-2;
	while(index>1){
		RTo += time_vect[index] + time_vect[0];
		index -= 2;
	}

	//'factor' is an even number equal to the number of hikers minus 2
	//and decreased by 1 in case such number is odd
	//'factor' is used to compute time_temp2
	auto factor = ((num_hikers-2)%2==0 ? num_hikers-2 : num_hikers-3);
	RTc = time_vect[1] * factor;

	//finally add to the already partially computed 'time'
	//the minimum value between 'time_temp1' and 'time_temp2'
	CMT += std::min(RTo, RTc);
	std::cout << "time for current bridge: " << CMT << std::endl;
	return CMT;
}



}