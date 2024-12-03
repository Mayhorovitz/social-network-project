#pragma warning (disable: 4996)
#include "user.h"
#include "fanPage.h"
#include <iostream>

using namespace std;


//Constructor
User::User(const string& name, int day, int month, int year) :
    Entity(name), birthDate(day, month, year) {}

//Distructor
User::~User(){}

int User::getNumOfFriends() const {
    int counter = 0;
    for (int i = 0; i < entities.size(); i++) {
        if (typeid(*(entities[i])) == typeid(User))
            counter++;
    }
    return counter;

}
//print all user friends
void User::printEntities() const
{
    if (getNumOfFriends() == 0) {
        cout << getName() << " has no friends" << endl;
    }
    else {
        auto it = entities.begin();

        cout << getName() << " friends:" << endl;

        for (; it != entities.end(); ++it)
        {
            if (typeid(*(*it)) == typeid(User))
                cout << (*it)->getName() << endl;
        }
        cout << endl;
    }
}
// virtual function that prints all last update statuses of user's friends
void User::printLastStatuses() const
{
    auto arr = entities;

    auto Eitr = arr.begin();

    for (; Eitr != arr.end(); ++Eitr)
    {
        if (typeid(*(*Eitr)) == typeid(User))
        {
            cout << (*Eitr)->getName() << "'s statuses:" << endl;

            const vector<Status*>& statuses = (*Eitr)->getStatuses();

            if (statuses.size() < 10)
            {
                for (auto it = statuses.begin(); it != statuses.end(); ++it)
                {
                    (*it)->print();
                    cout << endl << "-----------------------" << endl;
                }
            }
            else
            {
                auto Bitr = statuses.end() - 1;
                for (int j = 0; j < 10; j++)
                {
                    (*Bitr)->print();
                    cout << "-----------------------" << endl;
                    Bitr--;
                }
            }
        }
    }
}
