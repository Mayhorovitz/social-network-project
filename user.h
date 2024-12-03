#ifndef __USER_H
#define __USER_H

#include "status.h"
#include "entity.h"
#include "date.h"

class FanPage;
class User : public Entity {

    Date birthDate;


public:
    User(const string& n, int day, int month, int year);
    virtual ~User();
    User(const User&) = delete;

    User& operator=(const User& u) = delete;
    int getNumOfFriends() const;
    virtual void printLastStatuses() const override;
    virtual void printEntities() const override;
    // virtual function that prints all user's friends

};


#endif // __USER_H