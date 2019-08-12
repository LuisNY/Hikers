
#ifndef HIKERS_PROGRAM_FOREST_H
#define HIKERS_PROGRAM_FOREST_H
#include <bridges/src/bridge.hpp>
#include <vector>

namespace forest {

class Forest {

  int num_bridges_;
  std::unique_ptr<int> time_; // in secs


public:
  std::vector<std::unique_ptr<bridge::Bridge>> bridges_;
  Forest(int num_bridges);
  void addBridge(std::unique_ptr<bridge::Bridge>&&);

  //std::vector<std::unique_ptr<bridge::Bridge>> getBridges();
};

}

#endif //HIKERS_PROGRAM_FOREST_H
