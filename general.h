#ifndef __GENERAL_H
#define __GENERAL_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "Facebook.h"
#include "date.h"
#include "status.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include "user.h"
#include "fanPage.h"

class FaceBook;
class General
{

public:

	static Entity* readUser(const FaceBook& f);
	static Entity* readFanPage(const FaceBook& f);
	static Status* readStatus();
	static void readTextStatus(Date& date, Hour& hour);

};


#endif // __GENERAL_H