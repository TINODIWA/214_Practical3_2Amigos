#include "Dogorithm.h"
#include "Users.h"

Dogorithm::Dogorithm() {}

void Dogorithm::registerUser(Users *user)
{
    // register a user to the chat room
    getUsers().push_back(user);
}

void Dogorithm::sendMessage(string message, Users *fromUser)
{
    // broadcast message to all users in the chat room
    // saveMessage(message, fromUser);
    cout << "[Dogorithm]" << fromUser->getName() << ": " << message << endl;
}

void Dogorithm::saveMessage(string message, Users *fromUser)
{
    // add message to chat history
    getChatHistory().push_back(message);
}

void Dogorithm::removeUser(Users *user)
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
