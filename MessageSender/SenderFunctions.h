#ifndef SENDERFUNCTIONS_H
#define SENDERFUNCTIONS_H

struct Message{
    std::string note;
    std::string sender;
    std::string receiver;
    Message *next;
};

class sender{
    public:
        messageSend();
        ~messageSend();
        void createUser(std::string name);
        void changeUser(std::string name);
        void postPrivate(std::name, std::string message);
        void postPublic(std::string message);
        void deleteOwn();
        void deleteReceived();
        void viewPrivate();
        void viewPublic();
    protected::
    private::
        Message *messageList;
};

#endif //SENDERFUNCTIONS_H
