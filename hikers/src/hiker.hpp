
#ifndef HIKERS_HIKER_HPP
#define HIKERS_HIKER_HPP
#include <iostream>

namespace hiker {
class Hiker {

	std::string name_;
	float speed_; // ft/minute

public:

	Hiker(const std::string &name, float speed);
	Hiker() = delete;
	Hiker(const hiker::Hiker&) = default;
	~Hiker() = default;
	float getSpeed() const;
	std::string getName() const;
};
}

#endif //HIKERS_HIKER_HPP
