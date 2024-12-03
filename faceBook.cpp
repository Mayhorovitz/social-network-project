#include "faceBook.h"
#include "general.h"
#include <iostream>

using namespace std;
// Constructor
FaceBook::FaceBook()  {}
//Distructor
FaceBook::~FaceBook() {
    auto it = entities.begin();

    for (; it != entities.end(); ++it)
    {
        delete (*it);
    }

    entities.resize(0);
}

//getters
const string& FaceBook::getEntityName(int i) const
{
    return entities[i]->getName();
}
//get number of entities in facebook
int FaceBook::getSize() const {
    return entities.size();
}
//get entity
Entity& FaceBook::getEntity(int i) const {
    return *entities[i];
}
//get number of users in facebook
int FaceBook::getNumOfUsers() const {
    int counter = 0;
    for (int i = 0; i < entities.size(); i++) {
        if (typeOfEntity(i) == 'U')
            counter++;
    }
    return counter;

}
//get number of pages in facebook
int FaceBook::getNumOfPages() const {
    int counter = 0;
    for (int i = 0; i < entities.size(); i++) {
        if (typeOfEntity(i) == 'F')
            counter++;
    }
    return counter;
}
//return the type of the entity
char FaceBook::typeOfEntity(int i) const
{

    if (typeid(*(entities[i])) == typeid(User))
        return 'U';

    else if (typeid(*(entities[i])) == typeid(FanPage))
        return 'F';
}

//add user to facebook
void FaceBook::addUser() {
    Entity* pEntity;

    pEntity = General::readUser(*this);

    entities.push_back(pEntity);


}
//add fan page to facebook
void FaceBook::addFanPage() {
    Entity* pEntity;

    pEntity = General::readFanPage(*this);

    entities.push_back(pEntity);

}

//check if the entity exist in entities vector
int FaceBook::IsEntityExist(string name) const {
    auto it = entities.begin();


    for (int i = 0; it != entities.end(); ++it, ++i)
    {
        if (name == (*it)->getName())
        {
            return i;
        }
    }

    if (it == entities.end())
        return notFound;
}


//print all the users
void FaceBook::showAllUsers() {
    auto it = entities.begin();
    for (; it != entities.end(); ++it)
    {
        if (typeid(*(*it)) == typeid(User))
            cout << (*it)->getName() << endl;
    }
}
//print all the fan pages
void FaceBook::showAllFanPages() {
    auto it = entities.begin();
    for (; it != entities.end(); ++it)
    {
        if (typeid(*(*it)) == typeid(FanPage))
            cout << (*it)->getName() << endl;
    }
}


//add user directly to facebook
void FaceBook::addUser(string name, int day, int month, int year) {
    Entity* newUser = new User(name, day, month, year);
    entities.push_back(newUser);
    
}

//add fan page directly to facebook
void FaceBook::addFanPage(string name) {
    Entity* newPages = new FanPage(name);
    entities.push_back(newPages);
}
