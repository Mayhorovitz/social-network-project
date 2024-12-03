#ifndef HOUR_H
#define HOUR_H

#include <iostream>

class Hour
{
	int hour;
	int min;
	int sec;


public:
	Hour();
	Hour(int hour, int min, int sec);

	void print() const;

};

#endif//!HOUR_H
