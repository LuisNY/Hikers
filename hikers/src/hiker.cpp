#include "hiker.hpp"

namespace hiker {

Hiker::Hiker(const std::string &name, const float speed) :
	name_(name), speed_(speed) {}

float Hiker::getSpeed() const {
	return speed_;
}

}