#include "imageStatus.h"

// Constructor
ImageStatus::ImageStatus(const string& t, const Date& d, const Hour& h,const string& image) : Status(t, d, h), ImageFileName(image) { }

// virtual function that prints the status
void ImageStatus::print() const
{
	cout << "\033[1;35m";
	Status::print();
	system(ImageFileName.c_str());
	cout << "\033[0m";
}