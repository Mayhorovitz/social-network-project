#include "hour.h"

#include <iostream>

using namespace std;


// Constructor
Hour::Hour(){}
Hour::Hour(int hour, int min, int sec) : hour(hour), min(min), sec(sec) {}

//print
void Hour::print() const {
	cout << "Hour: " << hour << ":" << min << ":" << sec << endl;

}
