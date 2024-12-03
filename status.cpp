#pragma warning (disable: 4996)
#include <iostream>
#include "status.h"


// Constructor
Status::Status(const string& t, const Date& d, const Hour& h)
	: text(t), date(d), hour(h) {}

// virtual function that prints the status
void Status::print() const
{
	cout << "Text: " << text << endl;
	date.print();
	hour.print();
}
//check if two texts are equales
bool Status::operator==(const Status& s) const
{
	return text == s.text;
}
//chec if two texts doesnt equales
bool Status::operator!=(const Status& s) const
{
	return !(*this == s);
}

