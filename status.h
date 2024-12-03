#ifndef __STATUS_H
#define __STATUS_H

#include "date.h"
#include "hour.h"
#include <string>

using namespace std;

class Status
{
    string text;
    Hour hour;
    Date date;

public:
    Status(const string& t, const Date& d, const Hour& h);
    Status(const Status& s) = delete;
    Status& operator=(const Status& s) = delete;
    virtual void print() const;
    bool operator==(const Status& s) const;
    bool operator!=(const Status& s) const;
};

#endif // __STATUS_H
