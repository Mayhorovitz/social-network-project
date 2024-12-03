#ifndef __FANPAGE_H
#define __FANPAGE_H

#include "status.h"
#include "entity.h"

class User;

class FanPage : public Entity {
 
public:
    FanPage(const string& n);
    FanPage(const FanPage& fp) = delete;
    virtual ~FanPage();
    FanPage& operator=(const FanPage& fp) = delete;
    virtual void printEntities() const override;
    // virtual function that prints all user's friends

    virtual void printLastStatuses() const override;

};

#endif // __FANPAGE_H

