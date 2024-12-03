#include "general.h"
#include "faceBook.h"
#include <iostream>

using namespace std;

//reads input to creats a new user of Facebook
Entity* General::readUser(const FaceBook& f)
{
	string name;
	int day, month, year;
	cout << "enter user name: ";
	getline(cin, name);
	// check if the user already exist
	while (f.IsEntityExist(name) != notFound) {
		cout << "User with name " << name << " already exists in the system." << endl;
		getline(cin, name);
	
	}
	cout << "enter birth date" << endl;
	cout << "day: ";
	cin >> day;
	cout << "month: ";
	cin >> month;
	cout << "year: ";
	cin >> year;

	cin.ignore();
	Entity* pNewEntity = new User(name, day, month, year);

	return pNewEntity;
}

// reads input to creats a new fan page of Facebook
Entity* General::readFanPage(const FaceBook& f)
{
	string name;
	cout << "enter fan page name: ";
	getline(cin, name);
	// check if the fan page already exist
	while (f.IsEntityExist(name) != notFound) {
		cout << "fan page with name " << name << " already exists in the system. choose new name " << endl;
		getline(cin, name);
	}

	Entity* pNewEntity = new FanPage(name);

	return pNewEntity;

}
//reads input to creats new status
Status* General::readStatus()
{
    string text;  
    string line;
    Date date;
    Hour hour;
    int choice;
    bool c;
    Status* st = nullptr;

    cout << endl << "Please enter one of the options:" << endl << "1. Text Status" << endl << "2. Image Status" << endl << "3. Video Status" << endl;
    cin >> choice;
    cin.ignore();


    while (choice != VideoStatusChoose && choice != TextStatusChoose && choice != ImageStatusChoose) {
        cout << "Invalid choice: " << endl;
        cout << "Enter your new choice: " << endl;
        cin >> choice;
   
    }

    switch (choice)
    {
    //text status
    case 1:

        cout << endl << "Please enter your status: " << endl;
        getline(cin, text);  

        readTextStatus(date, hour);  

        st = new Status(text, date, hour);  
        break;
    //image status
    case 2:
        cout << endl << "Please describe your image: " << endl;
        getline(cin, text);  

        readTextStatus(date, hour);  
        cout << endl << "Put image file: " << endl;
        getline(cin, line);
        getline(cin, text);

        st = new ImageStatus(text, date, hour,line);  
        break;
    //video status
    case 3:
        cout << endl << "Please describe your video: " << endl;
        getline(cin, text); 

        readTextStatus(date, hour);  
        cout << endl << "Put video file: " << endl;
        getline(cin, line);
        getline(cin, text);

        st = new VideoStatus(text, date, hour, line);  
        break;
    }
    return st;
}
//get status hour and date
void General::readTextStatus(Date& date, Hour& hour)
{
    int year, day, h, min, sec, month;
    
    cout << "Enter hour of status(hour minutes seconds): ";
    cin >> h >> min >> sec;
    cout << "Enter date (day month year): ";
    cin >> day >> month >> year;

    date = Date(day, month, year);
    hour = Hour(h, min, sec);
}