
#ifndef HIKERS_PROGRAM_FOREST_H
#define HIKERS_PROGRAM_FOREST_H
#include <bridges/src/bridges.hpp>
#include <memory>
#include <vector>

namespace forest {

class Forest {

  std::unique_ptr<int> time_; // in secs
  std::vector<bridge::Bridge> bridges_;

public:
  Forest();

};

}

#endif //HIKERS_PROGRAM_FOREST_H
