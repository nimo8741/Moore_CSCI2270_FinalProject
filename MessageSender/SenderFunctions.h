#ifndef SENDERFUNCTIONS_H
#define SENDERFUNCTIONS_H
#include <vector>
#include <iostream>

struct Message{
    std::string note;
    std::string sender;
    std::string receiver;
    int id;
    Message *next;
    Message *previous;
};

class Sender{
    public:
        Sender();
        ~Sender();
        void createUser(std::string name);
        void changeUser(std::string name);
        void postMessage(std::string name, std::string message);
        void deleteMessage();
        void viewMessages();
        void printUsers();
        void organizeUsers();
        bool found(std::string input);
        void readFromFile();
        void writeToFile();
        void deleteAll();
    protected:
    private:
        Message *messageList;
        std::vector<std::string> users;
        std::string currentUser;
        int idCounter;
};

#endif //SENDERFUNCTIONS_H
