#ifndef __ENTITY_H
#define __ENTITY_H

#include "status.h"
#include "imageStatus.h"
#include <iostream>
#include <string>
#include <vector>


class Entity {

public:
    Entity(const string& name);
    virtual ~Entity(); // Virtual destructor
    const string& getName() const; 
    int getEntitiesSize() const;
    const vector<Status*>& getStatuses() const;
    void print() const;
    void showAllStatuses() const;
    bool addEntity(Entity& other);
    void deleteEntity(Entity& other);
    void addStatus(Status& status);
    bool checkIfEntityExist(const string& name) const;
    Entity& operator+=(Entity& entity);
    bool operator>(const Entity& entity);
    void addStatus(const string& text, int hour, int day, int month, int year, const string& line);

    virtual void printLastStatuses() const = 0;
    virtual void printEntities() const = 0;

protected:

    string name;
    vector<Status*> statuses;
    vector<Entity*> entities;

};

#endif // __ENTITY_H
