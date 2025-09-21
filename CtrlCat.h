#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

class CtrlCat : public ChatRoom
{
    public:
        CtrlCat();
        CtrlCat(const std::string &name, ChatRoom *room = nullptr);

        virtual void registerUser(Users user);
        virtual void removeUser(Users user);
        // virtual Iterator* createIterator();
};

#endif