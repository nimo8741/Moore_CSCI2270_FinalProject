#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "SenderFunctions.h"

using namespace std;

sender::sender(){

}

sender::~sender(){
    for(int i = 0; i < users.size(); i++){
        users[i] = "";
    }
}

void sender::createUser(string name){
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
}

void sender::organizeUsers(){
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

void sender::printUsers(){
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

void sender::changeUser(string name){
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

void sender::postMessage(string name, string message){
    Message *current = new Message;
    Message *temp = new Message;
    temp = messageList;
    current->note = message;
    current->sender = currentUser;
    current->receiver = name;
    current->previous = NULL;
    current->next = NULL;
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

bool sender::found(string input){
    bool exists = false;
    for(int i = 0; i < users.size(); i++){
        if(input == users[i]){
            exists = true;
        }
    }
    return exists;
}

void sender::deleteOwn(){

}

void sender::deleteReceived(){

}

void sender::viewPrivate(){

}

void sender::viewPublic(){

}
