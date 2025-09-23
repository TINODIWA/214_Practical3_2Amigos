#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

class Dogorithm : public ChatRoom
{
    public:
        Dogorithm();
        Dogorithm(const std::string &name, ChatRoom *room = nullptr);

        virtual void registerUser(Users* user);
        virtual void sendMessage(string message, Users* fromUser);
        virtual void saveMessage(string message, Users* fromUser);
        virtual void removeUser(Users* user);
        // virtual Iterator* createIterator();
};

#endif