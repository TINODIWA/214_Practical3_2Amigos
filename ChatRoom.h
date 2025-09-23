#ifndef CHATROOM_H
#define CHATROOM_H

#include "Users.h"
// #include "Iterator.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ChatRoom
{
    public:
        ChatRoom();
        ~ChatRoom();

        virtual void registerUser(Users* user) = 0;
        virtual void sendMessage(string message, Users* fromUser) = 0;
        virtual void saveMessage(string message, Users* fromUser) = 0;
        virtual void removeUser(Users* user) = 0;
        // virtual Iterator* createIterator() = 0;
        vector<Users*> getUsers();
        vector<string> getChatHistory();

    private:
        vector<Users*> users;
        vector<string> chatHistory;
};

#endif