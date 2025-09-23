#include "Users.h"

Users::Users(ChatRoom *room, string name) : chatRooms(room), name(name) {}

Users::~Users() {}

void Users::send(string message, ChatRoom *room)
{
    // send message to chat room to deal with
    room->sendMessage(message, this);
}

void Users::receive(string message, Users *fromUser, ChatRoom *room)
{
    // receive message from chat room
    room->saveMessage(fromUser->name + ": " + message, fromUser);
}

void Users::executeAll()
{
    // need to implement
}

string Users::getName()
{
    // get the name of the user to be accessed by ChatRoom's derived classes
    return name;
}