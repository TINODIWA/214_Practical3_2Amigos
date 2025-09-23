#include "ChatRoom.h"
#include "Users.h"

ChatRoom::ChatRoom() {}

ChatRoom::~ChatRoom()
{
    // for (Users *user : users)
    // {
    //     delete user;
    // }
}

vector<Users *> &ChatRoom::getUsers()
{
    // returns reference to users vector to allow modification of users in derived classes
    return users;
}

vector<string> &ChatRoom::getChatHistory()
{
    // returns reference to chatHistory vector to allow modification of chat history in derived classes
    return chatHistory;
}
