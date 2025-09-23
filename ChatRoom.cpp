#include "ChatRoom.h"

ChatRoom::ChatRoom(){}

ChatRoom::~ChatRoom()
{
    for (Users* user : users) {
        delete user;
    }
}

vector<Users*> ChatRoom::getUsers()
{
    return users;
}

vector<string> ChatRoom::getChatHistory()
{
    return chatHistory;
}
