#include "date.h"
#include <iostream>

using namespace std;


// Constructor
Date::Date() {}
Date::Date(int day, int month, int year) : day(day), month(month) ,year(year) {}
//print
void Date::print() const {
	cout << "Date: " << day << "/" << month << "/" << year << endl;

}