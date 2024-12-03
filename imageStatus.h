#ifndef __IMAGESTATUS_H
#define __IMAGESTATUS_H

#include "status.h"

class ImageStatus : public Status
{
	string ImageFileName;
public:

	ImageStatus(const string& t, const Date& d, const Hour& h, const string& image);
	virtual void print() const override;


};

#endif // __IMAGESTATUS_H