#pragma warning (disable: 4996)
#include "fanPage.h"
#include "user.h"
#include <iostream>
#include <cstring>

using namespace std;

//Constructor
FanPage::FanPage(const string& n) : Entity(n){}


//Distructor
FanPage::~FanPage() {}

//print all the page fans
void FanPage::printEntities() const
{
	if (getEntitiesSize() == 0) {
		cout << getName() << " has no fans" << endl;
	}
	else {
		auto it = entities.begin();

		cout << endl << getName() << " fans:" << endl;

		for (; it != entities.end(); ++it)
		{

			cout << (*it)->getName() << endl;
		}

	}
	cout << endl;
}

void FanPage::printLastStatuses() const {}