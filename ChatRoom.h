#ifndef CHATROOM_H
#define CHATROOM_H

#include "Users.h"
// #include "Iterator.h"

#include <string>
#include <vector>

using namespace std;

class ChatRoom
{
    public:
        ChatRoom();
        ~ChatRoom();

        virtual void registerUser(Users user) = 0;
        void sendMessage(string message, Users fromUser);
        void saveMessage(string message, Users fromUser);
        virtual void removeUser(Users user) = 0;
        // virtual Iterator* createIterator() = 0;

    private:
        vector<Users> users;
        vector<string> chatHistory;
};

#endif