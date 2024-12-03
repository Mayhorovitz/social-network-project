#ifndef __VIDEOSTATUS_H
#define __VIDEOSTATUS_H

#include "status.h"


class VideoStatus : public Status
{
	string VideoFileName;
public:


	VideoStatus(const string& t, const Date& d, const Hour& h, const string& video);
	virtual void print() const override;
	// virtual function that prints the status

};

#endif // __VIDEOSTATUS_H
