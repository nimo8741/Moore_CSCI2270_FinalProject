#ifndef SENDERFUNCTIONS_H
#define SENDERFUNCTIONS_H
#include <vector>
#include <iostream>

struct Message{
    std::string note;
    std::string sender;
    std::string receiver;
    Message *next;
    Message *previous;
};

class sender{
    public:
        sender();
        ~sender();
        void createUser(std::string name);
        void changeUser(std::string name);
        void postMessage(std::string name, std::string message);
        void deleteOwn();
        void deleteReceived();
        void viewPrivate();
        void viewPublic();
        void printUsers();
        void organizeUsers();
        bool found(std::string input);
    protected:
    private:
        Message *messageList;
        std::vector<std::string> users;
        std::string currentUser;
};

#endif //SENDERFUNCTIONS_H
