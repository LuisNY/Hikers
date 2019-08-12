
#include "bridge.hpp"

namespace bridge {

Bridge::Bridge(const std::string& name, float length) : name_(name), length_(length) {}


void Bridge::addHiker(const std::shared_ptr<hiker::Hiker> & hiker) {
  hikers_.push_back(hiker);
}

std::string Bridge::getName(){
  return name_;
}


}