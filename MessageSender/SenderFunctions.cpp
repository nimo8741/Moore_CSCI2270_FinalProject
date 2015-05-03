#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include "SenderFunctions.h"

using namespace std;

Sender::Sender(){
    messageList = NULL;
    idCounter = 0;
}

Sender::~Sender(){
    for(int i = 0; i < users.size(); i++){
        users[i] = "";
    }
}

/*Function prototype
void Sender::createUser(string name(

Function description:
This program either creates a user or sets the
desired user as the current user.  This decision is
based on whether the user name already exists within
the users vector

Example:
Sender test;
test.createUser("Billy");

Precondition:
Txt file that contains the user names and info
has been read it.

Post condition:
Switches the currentUser to whatever user is
passed into the function and if necessary,
adds the passed in user name to the users vector.
*/

void Sender::createUser(string name){
    bool found  = false;
    for(int i = 0; i < users.size(); i++){
        if(name == users[i]){
            found = true;
            currentUser = name;
            cout<<"Welcome back "<<name<<"!"<<endl<<endl;
        }
    }
    if(found == false){
        cout<<endl;
        cout<<"User not found. Creating new MessageSender User"<<endl;
        cout<<"Please wait..."<<endl;
        cout<<endl;
        users.push_back(name);
        cout<<"New user "<<name<<" has been created!"<<endl;
        cout<<endl;
        currentUser = name;
        organizeUsers();
    }
}

/*
Function prototype:
void Sender::organizeUsers();

Function description:
This function reorders the users vector into
alphabetical order.

Precondition:
The Txt file that contains the user names and
information has been read in.

Post condition:
The users vector is in alphabetical order.
*/

void Sender::organizeUsers(){
    string swapName;
    int n = users.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(users[j] > users[j+1]){
                swapName = users[j];
                users[j] = users[j+1];
                users[j+1] = swapName;
            }
        }
    }
}

/*
Function prototype:
void Sender::printUsers();

Function description:

Precondition:

Post condition:

*/

void Sender::printUsers(){
    if(users.size() == 0){    //this if condition should never happen but I included it anyways
        cout<<"No active users"<<endl;
    }
    else{
        cout<<endl;
        cout<<"Users:"<<endl;
        for(int i = 0; i < users.size(); i++){
            cout<<i+1<<" : "<<users[i]<<endl;
        }
        cout<<endl;
    }
}

/*
Function prototype:
void Sender::changeUser();

Function description:

Precondition:

Post condition:

*/

void Sender::changeUser(string name){
    bool found  = false;
    for(int i = 0; i < users.size(); i++){
        if(name == users[i]){
            found = true;
        }
    }
    if(found == false){
        cout<<endl;
        cout<<"User not found. Creating new MessageSender User"<<endl;
        cout<<"Please wait..."<<endl;
        cout<<endl;
        users.push_back(name);
        cout<<"New user "<<name<<" has been created!"<<endl;
        cout<<endl;
        currentUser = name;
        organizeUsers();
    }
    else if(found == true){
        cout<<endl;
        cout<<"Welcome back "<<name<<"!"<<endl;
        currentUser = name;
        cout<<endl;
    }
}

/*
Function prototype:
void Sender::postMessage();

Function description:

Precondition:

Post condition:

*/

void Sender::postMessage(string name, string message){
    Message *current = new Message;
    Message *temp = new Message;
    temp = messageList;
    current->note = message;
    current->sender = currentUser;
    current->receiver = name;
    current->previous = NULL;
    current->next = NULL;
    current->id = idCounter;
    idCounter++;
    if(temp == NULL){//for the initial posting
        messageList = current;
    }
    else{
        while(temp->next != NULL){//to get to the end of the message board
            temp = temp->next;
        }
        temp->next = current;
        current->previous = temp;
    }
}

/*
Function prototype:
void Sender::findUser();

Function description:

Precondition:

Post condition:

*/

bool Sender::findUser(string input){
    bool exists = false;
    for(int i = 0; i < users.size(); i++){
        if(input == users[i]){
            exists = true;
        }
    }
    return exists;
}

string Sender::curUser(){
    return currentUser;
}

void Sender::viewMessages(){   //Loop through all messages and print out Private then Public messages
    vector<int> msgID;
    int msgCounter = 1;  //Ties into vector to "remember" spot for different rando msg ID's
    Message *trav = new Message;
    trav = messageList;

    //Private
    cout << endl << "     PRIVATE" << endl;
    bool isEmpty = true;
    while(trav != NULL){
        if (currentUser == "admin" and trav->receiver != "all"){
            cout << msgCounter << ": " << trav->sender << " to " << trav->receiver << " - " << trav->note << endl;
            msgID.push_back(trav->id);
            msgCounter++;
            isEmpty = false;
        }
        else if (trav->receiver == currentUser){
            cout << msgCounter << ": " << trav->sender << " - " << trav->note << endl;
            msgID.push_back(trav->id);
            msgCounter++;
            isEmpty = false;
        }
        else if (trav->sender == currentUser && trav->receiver != "all"){
            cout << msgCounter << ": YOU to " << trav->receiver << " - " << trav->note << endl;
            msgID.push_back(trav->id);
            msgCounter++;
            isEmpty = false;
        }
        trav = trav->next;
    }
    if(isEmpty == true){
        cout<<"Your inbox is empty"<<endl;
    }

    //Public
    trav = messageList;
    cout << endl << "     PUBLIC" << endl;
    bool isitEmpty = true;
    while (trav != NULL){
        if (trav->receiver == "all"){
            cout << msgCounter << ": " << trav->sender << " - " << trav->note << endl;
            msgID.push_back(trav->id);
            msgCounter++;
            isitEmpty = false;
        }
        trav = trav->next;
    }
    if(isitEmpty == true){
        cout<<"Your inbox is empty"<<endl;
    }
    cout << endl;


}

/*
Function prototype:
void Sender::deleteMessage();

Function description:

Precondition:

Post condition:

*/

void Sender::deleteMessage(){
    viewMessages();
    //Copy code from view messages to have same vector of msg id's to match with what the user is deleting
    vector<int> msgID;
    int msgCounter = 0;  //Ties into vector to "remember" spot for different rando msg ID's
    Message *trav = new Message;
    trav = messageList;

    //Private
    while (trav != NULL){
        if (currentUser == "admin" and trav->receiver != "all"){
            msgID.push_back(trav->id);
        }
        else if (trav->receiver == currentUser){
            msgID.push_back(trav->id);
        }
        else if (trav->sender == currentUser && trav->receiver != "all"){
            msgID.push_back(trav->id);
        }
        msgCounter++;
        trav = trav->next;
    }

    //Public
    trav = messageList;
    while (trav != NULL){
        if (trav->receiver == "all"){
            msgID.push_back(trav->id);
        }
        msgCounter++;
        trav = trav->next;
    }

    //END Copy with couts deleted
    cout << "Which message would you like to delete?  Or select 0 to exit" << endl;
    cout << "1";
    for (int i = 1; i < msgID.size(); ++i){
        cout <<", " << i+1;
    }
    cout << endl;
    string del;
    getline(cin >> ws, del);
    while (stoi(del) >> msgID.size()+1){
        cout << "Not a valid message, please select a valid message number or 0." << endl;
        getline(cin >> ws, del);
    }
    if (stoi(del) == 0){
        return;
    }
    int delID = msgID[stoi(del)-1];

    //Find the message to be deleted in the linked list
    trav = messageList;
    while(trav->id != delID){
        trav = trav->next;
    }
    if ((currentUser == "admin") or (trav->receiver == "all" and trav->sender == currentUser) or (trav->receiver == currentUser)){
        if(trav->next != NULL){
            trav->previous->next = trav->next;
            trav->next->previous = trav->previous;
            delete trav;
        }
        else if(trav->next == NULL){
            trav->previous->next = NULL;
            delete trav;
        }
    }
    else{
        cout<<endl;
        cout<<"You do not have access to delete this message."<<endl;
        cout<<"You must be trying to delete a public message you sent"<<endl;
        cout<<"or a private message that you received from someone else."<<endl<<endl;
    }
}

/*
Function prototype:
void Sender::deleteAll();

Function description:

Precondition:

Post condition:

*/

void Sender::deleteAll(){
    messageList = NULL;
    for(int i = 0; i < users.size(); i++){
        if(users[i] != "admin"){
            users[i].clear();
        }
    }
    users.resize(1);
    users[0] = "admin";
    idCounter = 0;
}

/*
Function prototype:
void Sender::readFromFile();

Function description:

Precondition:

Post condition:

*/

void Sender::readFromFile(){
    ifstream infile;
    infile.open("Messages.txt");
    string section, user, msg, counter;
    //Users
    getline(infile, section,'%');
    istringstream userStream(section);
    users.clear();
    while(getline(userStream, user)){
        users.push_back(user);
    }
    //Messages:   msgID*sender*reciever*note
    getline(infile, section, '%');
    istringstream msgStream(section);
    Message *tail = new Message;
    tail = messageList;
    while(getline(msgStream, msg)){
        istringstream lineStream(msg);
        string msgID, sender, receiver, note;
        Message *newMessage = new Message;
        getline(lineStream, msgID, '*');
        getline(lineStream, sender, '*');
        getline(lineStream, receiver, '*');
        getline(lineStream, note, '*');
        newMessage->id = stoi(msgID);
        newMessage->sender = sender;
        newMessage->receiver = receiver;
        newMessage->note = note;
        if (messageList == NULL){
            messageList = newMessage;
            tail = messageList;
        }
        else{
            tail->next = newMessage;
            newMessage->previous = tail;
            newMessage->next = NULL;
            tail = tail->next;
        }
    }
    //ID count
    getline(infile, section, '%');
    idCounter = stoi(section);
}

/*
Function prototype:
void Sender::writeToFile();

Function description:

Precondition:

Post condition:

*/

void Sender::writeToFile(){
    /*Write to file in following format:
    user1
    user2
    %msg1*sender*receiver*note
    msg2*sender*receiver*note
    %IDCount
    %
    */
    ofstream outfile;
    outfile.open("Messages.txt");
    for (int i = 0; i < users.size(); ++i)
    {
        outfile << users[i] << endl;
    }
    outfile << '%';
    Message *trav = messageList;
    while (trav != NULL){
        //FIx for not deleting message itself, only content
        if (trav->sender != "" and trav->note != "")
            outfile << trav->id <<"*"<< trav->sender <<"*"<< trav->receiver <<"*"<<trav->note << endl;
        trav = trav->next;
    }
    outfile << '%';
    outfile << idCounter << endl;
    outfile << '%';
    return;
}
