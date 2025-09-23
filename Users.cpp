#include "Users.h"
#include "ChatRoom.h"

Users::Users(ChatRoom* room = nullptr, string name = "") : chatRooms(room), name(name){}

Users::~Users()
{
    delete chatRooms;
}

void Users::send(string message, ChatRoom* room)
{
    room->sendMessage(message, this);
}

void Users::receive(string message, Users* fromUser, ChatRoom* room)
{
    room->saveMessage(message, fromUser);
}

void Users::executeAll()
{
    //need to implement
}

string Users::getName()
{
    return name;
}
