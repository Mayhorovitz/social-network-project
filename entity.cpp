#include "entity.h"
#include <iostream>

using namespace std;

// Constructor
Entity::Entity(const string& name) : name(name) {}

// Destructor
Entity::~Entity()
{
    for (auto it = statuses.begin(); it != statuses.end(); ++it)
    {
        delete* it;
    }
    statuses.clear(); 
}

// Get name
const string& Entity::getName() const {
    return name;
}

// Get number of entities
int Entity::getEntitiesSize() const {
    return entities.size();
}

// Get statuses
const vector<Status*>& Entity::getStatuses() const {
    return statuses;
}

// Print name
void Entity::print() const {
    cout << name << endl;
}

// Add a new status
void Entity::addStatus(Status& status)
{
    statuses.push_back(&status);
}

// Show all statuses
void Entity::showAllStatuses() const {
    cout << "All statuses of " << name << endl;

    for (size_t i = 0; i < statuses.size(); ++i)
    {
        cout << "status " << i + 1 << endl;
        statuses[i]->print(); 
        cout << "-----------------------" << endl;
    }

    cout << endl;
}

// Add a new entity to the entities vecror
bool Entity::addEntity(Entity& other) {
    if (!checkIfEntityExist(other.getName()) && name != other.getName())
    {
        entities.push_back(&other);
        other.addEntity(*this);
        return true;
    }

    return false;
}

// Delete an entity from the entities vecror
void Entity::deleteEntity(Entity& other)
{
    auto it = find(entities.begin(), entities.end(), &other);
    if (it != entities.end()) {
        entities.erase(it);

        auto otherIt = find(other.entities.begin(), other.entities.end(), this);
        if (otherIt != other.entities.end()) {
            other.entities.erase(otherIt);
        }
    }
}

// Check if the entity already exists
bool Entity::checkIfEntityExist(const string& name) const {
    auto it = entities.begin();

    for (; it != entities.end(); ++it)
    {
        if ((*it)->getName() == name)
            return true;
    }

    return false;
}

// Adds 2 users to each other's friend lists
Entity& Entity::operator+=(Entity& entity)
{
    addEntity(entity);
    return *this;
}

// Compare number of entities between 2 entities
bool Entity::operator>(const Entity& entity)
{
    return entities.size() > entity.getEntitiesSize();
}

// Add a new status
void Entity::addStatus(const string& text, int hour, int day, int month, int year, const string& line) {
    Status* st = nullptr;
    Date date(day, month, year);
    Hour h(hour, 0, 0);
    if (line == "")
    st = new Status(text, date, h);

    else {
        st = new ImageStatus(text, date, h, line);
    }

    statuses.push_back(st);
}
