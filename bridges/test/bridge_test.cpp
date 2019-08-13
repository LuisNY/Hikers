#include <iostream>
#include "../src/bridge.hpp"
#include <algorithm>
#include <assert.h>

int main(){

	std::shared_ptr<hiker::Hiker> h1 = std::make_shared<hiker::Hiker>("A", 100);
	std::shared_ptr<hiker::Hiker> h2 = std::make_shared<hiker::Hiker>("B", 50);
	std::shared_ptr<hiker::Hiker> h3 = std::make_shared<hiker::Hiker>("C", 25);
	std::shared_ptr<hiker::Hiker> h4 = std::make_shared<hiker::Hiker>("D", 10);
	std::shared_ptr<hiker::Hiker> h5 = std::make_shared<hiker::Hiker>("D", 20);

	bridge::Bridge br1("bridge1", 100);
	br1.addHiker(h1);
	br1.addHiker(h2);
	br1.addHiker(h3);
	br1.addHiker(h4);

	assert(br1.computeCrossingTime() == 17);

	bridge::Bridge br2("bridge2", 100);
	br2.addHiker(h1);
	br2.addHiker(h5);
	br2.addHiker(h3);
	br2.addHiker(h4);

	assert(br2.computeCrossingTime() == 21);

}