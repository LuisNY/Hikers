
#include "forest.h"

namespace forest {

  Forest::Forest(int num_bridges) :
    num_bridges_(num_bridges),
    time_ (nullptr) {}

  void Forest::addBridge(std::unique_ptr<bridge::Bridge>&& bridge, const std::string& name) {
    bridges_.insert(std::make_pair(name,std::move(bridge)));
  }

  const std::unordered_map<std::string, std::unique_ptr<bridge::Bridge>>& Forest::getBridges() const {
    return bridges_;
  }

	float Forest::computeFastestCrossingTime() {
		float tot_time = 0;
		std::cout << "bridges" << std::endl;
		for(auto it = bridges_.begin(); it != bridges_.end(); it++){
			std::cout << it->first << std::endl;
			tot_time += it->second->computeCrossingTime();
		}
		std::cout << "minimum tot time: " << tot_time << std::endl;
		return tot_time;
	}


}