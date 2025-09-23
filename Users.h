#ifndef USERS_H
#define USERS_H

// #include "Command.h"

#include <string>
#include <vector>

using namespace std;

class ChatRoom;

class Users
{
    public:
        Users(ChatRoom* room, string name);
        ~Users();

        void send(string message, ChatRoom* room);
        void receive(string message, Users* fromUser, ChatRoom* room);
        // void addCommand(Command command);
        void executeAll();
        string getName();

    protected:
        ChatRoom* chatRooms;
        string name;
        // vector<Command*> commandQueue;
};

#endif
