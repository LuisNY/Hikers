
#include "forest.h"

namespace forest {

  Forest::Forest(int num_bridges) :
    num_bridges_(num_bridges),
    time_ (nullptr) {}

  void Forest::addBridge(std::unique_ptr<bridge::Bridge>&& bridge) {
    bridges_.push_back(std::move(bridge));
  }

  //std::vector<std::unique_ptr<bridge::Bridge>> Forest::getBridges(){
    //return bridges_;
  //}
}