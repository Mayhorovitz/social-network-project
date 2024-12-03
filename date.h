#ifndef __DATE_H
#define __DATE_H

class Date
{

	int day;
	int month;
	int year;


public:
	Date();
	Date(int d, int m, int y);
	void print() const;
};


#endif // __DATE_H
