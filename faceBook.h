#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "status.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include "fanPage.h"
#include "entity.h"

const int UserChoose = 1, FanPageChoose = 2, TextStatusChoose = 1, ImageStatusChoose = 2, VideoStatusChoose = 3, notFound = -1;

class FaceBook {

    vector<Entity*> entities;



public:
    FaceBook();
    ~FaceBook();
    FaceBook(const FaceBook& f) = delete;
    FaceBook& operator=(const FaceBook& f) = delete;
    int getSize() const;
    Entity& getEntity(int i) const;
    int getNumOfUsers() const;
    int getNumOfPages() const;
    const string& getEntityName(int i) const;
    int IsEntityExist(string name) const;
    char typeOfEntity(int i) const;
    void addUser();
    void addFanPage();
    void showAllUsers();
    void showAllFanPages();

    void addUser(string name, int day, int month, int year);
    void addFanPage(string name);

 
};

#endif // __FACEBOOK_H