
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

	/*
	 * There are 2 general algorithms that can be used to solve this problem:
	 * 1) the first is the 'obvious' one, where one hiker crosses the bridge with the fastest hiker
	 * and the fastest hiker then goes back to pick up a new hiker, until there are no hikers left
	 * 2) the second is the 'classical' algorithm, where the idea is that slow hikers cross together
	 * to minimize the crossing time.
	 *
	 * There is no algo that will perform better in all cases, so the key of the problem is to understand what
	 * algo needs to be used according to the input values.
	 *
	 * However, it is noticeable that no matter what algorithm is used, there is a common number of trips that need to
	 * be done in both algorithms. The idea in this program is to find the minimum time required to complete the trips
	 * that the two algorithms have in common, and then add to this time the fastest of the remaining times calculated
	 * by the two different algorithms.
	*/

	//set initial time to 0 min
	float time = 0;

	//add to 'time' the minimum time required to complete the trips that the two algorithms have in common
	while(index>1){
		time += time_vect[index] + time_vect[0];
		index -= 2;
	}
	time += time_vect[1];

	//at this point 'time' does not includes the time to complete all trips yet
	//we create here two additional time variables: 'time_temp1' and 'time_temp2'
	//but we will only add the minimum of these two to 'time' variable
	//time_temp1 uses the 'obvious' algorithm while time_temp2 uses the 'classic' algorithm
	float time_temp1 = 0,  time_temp2 = 0;

	//obvious algo, fastest hiker crosses back and forth each time
	index = num_hikers-2;
	while(index>1){
		time_temp1 += time_vect[index] + time_vect[0];
		index -= 2;
	}

	//'factor' is an even number equal to the number of hikers minus 2
	//and decreased by 1 in case such number is odd
	//'factor' is used to compute time_temp2
	auto factor = ((num_hikers-2)%2==0 ? num_hikers-2 : num_hikers-3);
	time_temp2 = time_vect[1] * factor;

	//finally add to the already partially computed 'time'
	//the minimum value between 'time_temp1' and 'time_temp2'
	time += std::min(time_temp1, time_temp2);
	std::cout << "time for current bridge: " << time << std::endl;
	return time;
}



}