#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include <iostream>
// #include <algorithm>

/**
 * @file Users.cpp
 * @brief Implementation of Users base class
 * @author 2Amigos
 * @date 2025-09-28
 */

Users::Users(ChatRoom *room, string name) : chatRooms(room), name(name), permissionLevel(2), isMuted(false), messageCount(0) {}

Users::~Users() 
{
    // Clean up commands
    for (Command* cmd : commandQueue)
    {
        delete cmd;
    }
}

void Users::send(string message, ChatRoom *room)
{
    // Create commands for sending and saving the message
    SendMessageCommand* sendCmd = new SendMessageCommand(room, this, message);
    SaveMessageCommand* saveCmd = new SaveMessageCommand(room, this, message);
    
    // Add commands to queue
    addCommand(sendCmd);
    addCommand(saveCmd);
    
    // Execute all commands
    executeAll();
}

void Users::receive(string message, Users *fromUser, ChatRoom *room)
{
    // Legacy method for compatibility - just save the message
    room->saveMessage(fromUser->name + ": " + message, fromUser);
}

void Users::addCommand(Command* command)
{
    if (command != nullptr)
    {
        commandQueue.push_back(command);
    }
}

void Users::executeAll()
{
    // Execute all commands in the queue
    for (Command* cmd : commandQueue)
    {
        if (cmd != nullptr)
        {
            cmd->execute();
            delete cmd; // Clean up after execution
        }
    }
    commandQueue.clear(); // Clear the queue
}

string Users::getName()
{
    return name;
}

int Users::getPermissionLevel()
{
    return permissionLevel;
}

void Users::setPermissionLevel(int level)
{
    if (level >= 1 && level <= 4) {
        permissionLevel = level;
    }
}

bool Users::isMutedUser()
{
    return isMuted;
}

void Users::setMuted(bool muted)
{
    isMuted = muted;
}

int Users::getMessageCount()
{
    return messageCount;
}

void Users::incrementMessageCount()
{
    messageCount++;
}

