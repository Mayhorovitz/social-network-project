#include "videoStatus.h"

// Constructor
VideoStatus::VideoStatus(const string& t, const Date& d, const Hour& h, const string& video) : Status(t, d, h), VideoFileName(video) { }
// virtual function that prints the status
void VideoStatus::print() const
{
	cout << "\033[1;31m";
	system(VideoFileName.c_str());
	Status::print();
	cout << "\033[0m";
}