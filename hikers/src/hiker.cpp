#include "hiker.hpp"

namespace hiker {


Hiker::Hiker(const std::string &name, float speed) :
	name_(name), speed_(speed) {}

std::string Hiker::getName() const {
	return name_;
}

float Hiker::getSpeed() const {
	return speed_;
}


}