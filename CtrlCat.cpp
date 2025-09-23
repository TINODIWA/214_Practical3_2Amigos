#include "CtrlCat.h"
#include "Users.h"

CtrlCat::CtrlCat() {}

void CtrlCat::registerUser(Users *user)
{
    // register a user to the chat room
    getUsers().push_back(user);
}

void CtrlCat::sendMessage(string message, Users *fromUser)
{
    // broadcast message to all users in the chat room
    // saveMessage(message, fromUser);
    cout << "[CtrlCat]" << fromUser->getName() << ": " << message << endl;
}

void CtrlCat::saveMessage(string message, Users *fromUser)
{
    // add message to chat history
    getChatHistory().push_back(message);
}

void CtrlCat::removeUser(Users *user)
{
    // deregister a user from the chat room
    for (vector<Users *>::iterator us = getUsers().begin(); us != getUsers().end(); us++)
    {
        if (*us == user)
        {
            getUsers().erase(us);
            return;
        }
    }
}
