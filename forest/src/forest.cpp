
#include "forest.h"

namespace forest {

  Forest::Forest(int num_bridges) :
    num_bridges_(num_bridges),
    time_ (nullptr) {}

  void Forest::addBridge(std::unique_ptr<bridge::Bridge>&& bridge, const std::string& name) {
    bridges_.insert(std::make_pair(name,std::move(bridge)));
  }

  const std::unordered_map<std::string, std::unique_ptr<bridge::Bridge>>& Forest::getBridges(){
    return bridges_;
  }
}