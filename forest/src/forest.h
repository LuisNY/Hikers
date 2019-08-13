
#ifndef HIKERS_PROGRAM_FOREST_H
#define HIKERS_PROGRAM_FOREST_H
#include <bridges/src/bridge.hpp>
#include <vector>
#include <unordered_map>
#include <yaml-cpp/yaml.h>

namespace forest {

class Forest {

	//the forest object has an unordered_map of unique_ptr to bridge objects
	std::unordered_map<std::string, std::unique_ptr<bridge::Bridge>> bridges_;

public:

  Forest() = default;
  void addBridge(std::unique_ptr<bridge::Bridge>&&, const std::string&);
  const std::unordered_map<std::string, std::unique_ptr<bridge::Bridge>>& getBridges() const;
	float computeFastestCrossingTime() const;
	void parseInputFile(const YAML::Node&);
};

}

#endif //HIKERS_PROGRAM_FOREST_H
