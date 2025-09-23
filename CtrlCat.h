#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

class CtrlCat : public ChatRoom
{
public:
    CtrlCat();
    
    virtual void registerUser(Users *user);
    virtual void sendMessage(string message, Users *fromUser);
    virtual void saveMessage(string message, Users *fromUser);
    virtual void removeUser(Users *user);
    // virtual Iterator* createIterator();
};

#endif