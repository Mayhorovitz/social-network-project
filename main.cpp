#include "faceBook.h"
#include "general.h"
#include <iostream>

using namespace std;

int chooseUserOrPage(FaceBook& facebook);
int chooseUser(FaceBook& facebook);
int chooseFanPage(FaceBook& facebook);
void addEntities(FaceBook& facebook);
int  chooseEntityToRemove(FaceBook& facebook,int choice);

int main() {

    int choice;

    FaceBook facebook;

    addEntities(facebook);

    do {
        cout << "please choose an option" << endl;
        cout << "1. Add new user" << endl;
        cout << "2. Add new fan page" << endl;
        cout << "3. Add a status to user / fan page" << endl;
        cout << "4. Show all statuses of user / fan page" << endl;
        cout << "5. Show the 10 most recent statuses of a certain friend's friends" << endl;
        cout << "6. Link two users as friends" << endl;
        cout << "7. Unlink two users as friends" << endl;
        cout << "8. Add a fan to a fan page" << endl;
        cout << "9. Remove a fan from a fan page" << endl;
        cout << "10. Show all entities registered in the system" << endl;
        cout << "11. Show all friends of a specific member / fans of a specific fan page" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            //Add new user
        case 1: {

            facebook.addUser();
            break;
        }
              //Add new fan page
        case 2: {

            facebook.addFanPage();

            break;
        }
              //Add a status to user / fan page
        case 3: {
            int choice = chooseUserOrPage(facebook);
            Status* st = General::readStatus();
            facebook.getEntity(choice).addStatus(*(st));

            break;
        }
              //Show all statuses of user / fan page
        case 4: {
            int choice = chooseUserOrPage(facebook);
            facebook.getEntity(choice).showAllStatuses();

            break;
        }
              // Show the 10 most recent statuses of a certain friend's friends
        case 5: {
            int choice = chooseUser(facebook);
            facebook.getEntity(choice).printLastStatuses();
            break;
        }
              // Link two users as friends
        case 6: {
            cout << "first friend: " << endl;
            int choice = chooseUser(facebook);
            cout << "second friend: " << endl;
            int choice2 = chooseUser(facebook);

            facebook.getEntity(choice).addEntity(facebook.getEntity(choice2));

            break;

        }
              //Unlink two users as friends
        case 7: {
            cout << "first friend: " << endl;
            int choice = chooseUser(facebook);
            cout << "friend to remove: " << endl;
            int choice2 = chooseEntityToRemove(facebook, choice);

            facebook.getEntity(choice).deleteEntity(facebook.getEntity(choice2));


            break;

        }
              //add fan to a fan page
        case 8: {
            cout << "chooce user: " << endl;
            int choice = chooseUser(facebook);
            cout << "chooce fan page: " << endl;
            int choice2 = chooseFanPage(facebook);

            facebook.getEntity(choice).addEntity(facebook.getEntity(choice2));

            break;

        }
              //Remove a fan from a fan page
        case 9: {
            cout << "chooce fan page: " << endl;
            int choice = chooseFanPage(facebook);
            cout << "chooce user: " << endl;
            int choice2 = chooseEntityToRemove(facebook, choice);

            facebook.getEntity(choice).deleteEntity(facebook.getEntity(choice2));

            break;

        }
              //Show all entities registered in the system
        case 10: {
            facebook.showAllUsers();
            facebook.showAllFanPages();

            break;
        }
               //Show all friends of a specific member / fans of a specific fan page
        case 11:
        {
            int choice = chooseUserOrPage(facebook);
            facebook.getEntity(choice).printEntities();
          
            break;
        }
        case 12:
            cout << "Exit" << endl;
            break;
        
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 12);

    return 0;
}

//get the iser choice 
int chooseUserOrPage(FaceBook& facebook) {
    int choice;
    cout << "Select a user - 1  or fan page - 2 :";
    cin >> choice;
    cin.ignore();
    while (choice < 1 || choice > 2) {
        cout << "Invalid choice: " << endl;
        cout << "Enter your new choice: " << endl;
        cin >> choice;
        cin.ignore();
    }
        if (choice == UserChoose) {
            return chooseUser(facebook);
        }
        else {
            return chooseFanPage(facebook);
        }
   
    return choice;
}
//chooce user from the list
int chooseUser(FaceBook& facebook) {
    int choice;
    string name;
    facebook.showAllUsers();
    cout << "Enter the name of your choice: ";
    getline(cin, name);
    choice = facebook.IsEntityExist(name);
    while (choice == notFound) {
        cout << "Invalid choice. " << endl;
        cout << "Enter your new choice: " << endl;
        getline(cin, name);
        choice = facebook.IsEntityExist(name);
    }
    return choice;
}
//chooce fan page from the list
int chooseFanPage(FaceBook& facebook) {
    int choice;
    string name;
    facebook.showAllFanPages();
    cout << "Enter the name of your choice: ";
    getline(cin, name);
    choice = facebook.IsEntityExist(name);
    while (choice == notFound) {
        cout << "Invalid choice. " << endl;
        cout << "Enter your new choice: " << endl;
        getline(cin, name);
        choice = facebook.IsEntityExist(name);
    }
    return choice;
}
//choose fan or friends to unlink
int  chooseEntityToRemove(FaceBook& facebook, int choice)
{
    int remove;
    string name;
    facebook.getEntity(choice).printEntities();
    cout << "Enter the name of your choice: ";
    getline(cin, name);
    remove = facebook.IsEntityExist(name);
    while (remove == notFound) {
        cout << "Invalid choice. " << endl;
        cout << "Enter your new choice: " << endl;
        getline(cin, name);
        remove = facebook.IsEntityExist(name);
    }
    return remove;
}


//add users and pages to the system 
void addEntities(FaceBook& facebook) {
    
    facebook.addUser("may", 21, 5, 1998);
    facebook.addUser("lior", 19, 6, 1998);
    facebook.addUser("keren", 20, 3, 2000);

    facebook.addFanPage("cpp");
    facebook.addFanPage("oop");
    facebook.addFanPage("programming");

    facebook.getEntity(0)+=(facebook.getEntity(1));
    facebook.getEntity(1)+=(facebook.getEntity(2));
    facebook.getEntity(1)+=(facebook.getEntity(3));
    facebook.getEntity(2)+=(facebook.getEntity(4));


    facebook.getEntity(0).addStatus("i love cpp", 14, 27, 2, 2024, "image1.jpg");
    facebook.getEntity(0).addStatus("good after noon", 15, 27, 2, 2024 ,"");
    facebook.getEntity(1).addStatus("i love programming", 14, 27, 2, 2024, "");
    facebook.getEntity(1).addStatus("cpp its the best", 15, 27, 2, 2024, "");
    facebook.getEntity(2).addStatus("i love programming", 14, 27, 2, 2024, "");
    facebook.getEntity(2).addStatus("i love cpp", 15, 27, 2, 2024, "");
    facebook.getEntity(3).addStatus("good morning", 8, 27, 2, 2024, "sun.png");
    facebook.getEntity(3).addStatus("i love programming", 15, 27, 2, 2024, "");
    facebook.getEntity(4).addStatus("i love programming", 14, 27, 2, 2024, "");
    facebook.getEntity(4).addStatus("good night", 20, 27, 2, 2024, "");
    facebook.getEntity(5).addStatus("i love programming", 14, 27, 2, 2024, "");
    facebook.getEntity(5).addStatus("i love cpp", 15, 27, 2, 2024, "");
}