#include "CtrlCat.h"

CtrlCat::CtrlCat(){}

CtrlCat::CtrlCat(const std::string &name, ChatRoom *room)
{
}

void CtrlCat::registerUser(Users* user)
{
    getUsers().push_back(user);
}

void CtrlCat::sendMessage(string message, Users *fromUser)
{
    saveMessage(message, fromUser);
    cout << "[CtrlCat]" << fromUser->getName() << ": " << message << endl;
}

void CtrlCat::saveMessage(string message, Users *fromUser)
{
    getChatHistory().push_back(message);
}

void CtrlCat::removeUser(Users* user)
{
    for(vector<Users*>::iterator us = getUsers().begin(); us != getUsers().end(); us++)
    {
        if(*us == user)
        {
            getUsers().erase(us);
            return;
        }
    }
}
