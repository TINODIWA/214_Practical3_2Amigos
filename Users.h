#ifndef USERS_H
#define USERS_H

#include "ChatRoom.h"
// #include "Command.h"

#include <string>
#include <vector>

using namespace std;

class Users
{
    public:
        Users();
        ~Users();

        virtual void registerUser(Users user) = 0;
        void send(string message, ChatRoom room);
        void receive(string message, Users fromUser, ChatRoom room);
        // void addCommand(Command command);
        void executeAll();

    protected:
        ChatRoom *chatRooms;
        string name;
        // vector<Command*> commandQueue;
};

#endif
