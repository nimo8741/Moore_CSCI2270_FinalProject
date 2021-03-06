#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "SenderFunctions.h"

using namespace std;

int main(){
    Sender *action = new Sender;
    cout<<"Welcome to MessageSender!"<<endl;
    cout<<endl;
    action->readFromFile();
    string username;
    cout<<"Please Login"<<endl;
    cout<<"Username: ";
    getline(cin >> ws, username);
    cout<<endl;
    action->createUser(username);
    string cmd;
    while(cmd != "6"){
        cout << "======Main Menu=====" << endl;
		cout << "1. View Messages" << endl;
		cout << "2. View active users"<<endl;
		cout << "3. Send Message" << endl;
		cout << "4. Delete Messages" << endl;
		cout << "5. Switch Users"<<endl;
		cout << "6. Exit MessageSender"<<endl;
        if (action->curUser() == "admin"){
            cout << "7. Delete all" << endl;
        }

		cin>>cmd;
		if(action->curUser() == "admin" && cmd != "1" && cmd != "2" && cmd != "3" && cmd != "4" && cmd != "5" && cmd != "6" and cmd != "7"){
            cout<<"Please select an appropriate command."<<endl;
            cout<<"An appropriate command is a number 1 through 7."<<endl;
		}
		else if(action->curUser() != "admin" && cmd != "1" && cmd != "2" && cmd != "3" && cmd != "4" && cmd != "5" && cmd != "6" and cmd != "7"){
            cout<<"Please select an appropriate command."<<endl;
            cout<<"An appropriate command is a number 1 through 6."<<endl;
		}
		else{
            if(cmd == "1"){
                action->viewMessages();
            }
            else if(cmd == "2"){
                action->printUsers();
            }
            else if(cmd == "3"){
                cout<<"Please type the message you wish to send"<<endl;
                string in_message;
                getline(cin >> ws, in_message);
                cout<<endl;
                cout<<"For a public message, please type 'all'"<<endl;
                cout<<"For a private message, please type the name of an active user"<<endl;
                cout<<"Please choose a recipient for the message"<<endl;
                cout<<"You may type 'quit' should you wish to leave this option."<<endl;
                bool found = false;
                bool quit = false;
                string recipient;
                bool good = false;
                while(found != true && quit != true){
                    getline(cin >> ws, recipient);
                    found = action->findUser(recipient);
                    if(recipient == "all"){
                        quit = true;
                        good = true;
                    }
                    else if(found == false && recipient != "quit"){
                        cout<<"Please choose an active user or type 'quit' to leave this option"<<endl;
                    }
                    if(recipient == action->curUser()){
                        cout<<"Why would you want to send a message to yourself?"<<endl;
                        cout<<"Please choose an active user or type 'quit' to leave this option"<<endl;
                        found = false;
                    }
                    else if(found == true){
                        quit = true;
                        good = true;
                    }
                    if(recipient == "quit"){
                        quit = true;
                        good = false;
                    }
                }
                cout<<endl;
                if(good == true){
                    action->postMessage(recipient, in_message);
                }
            }
            else if(cmd == "4"){
                action->deleteMessage();
            }
            else if(cmd == "5"){
                cout<<"Please Login"<<endl;
                cout<<"Username: ";
                string userChange;
                getline(cin >> ws, userChange);
                action->changeUser(userChange);
            }
            else if(cmd == "6"){
                cout<<"Thank you for using MessageSender!"<<endl<<endl;
                action->writeToFile();
            }
            else if(cmd == "7"){
                if(action->curUser() == "admin"){
                    cout << "Deleting all users and messages" << endl;
                    action->deleteAll();
                }
                else{
                    cout<<endl;
                    cout<<"You do not have access to perform this function."<<endl;
                    cout<<"You must be the admin to delete all"<<endl;
                    cout<<"How would you have known to select this?"<<endl<<endl;
                }
            }
		}
    }
}

