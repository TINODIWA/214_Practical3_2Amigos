#include "Dogorithm.h"

Dogorithm::Dogorithm()
{
}

Dogorithm::Dogorithm(const std::string &name, ChatRoom *room)
{
}

void Dogorithm::registerUser(Users* user)
{
    getUsers().push_back(user);
}

void Dogorithm::sendMessage(string message, Users *fromUser)
{
    saveMessage(message, fromUser);
    cout << "[Dogorithm]" << fromUser->getName() << ": " << message << endl;
}

void Dogorithm::saveMessage(string message, Users *fromUser)
{
    getChatHistory().push_back(message);
}

void Dogorithm::removeUser(Users* user)
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
