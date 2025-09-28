#include "SaveMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

/**
 * @file SaveMessageCommand.cpp
 * @brief Implementation of SaveMessageCommand class
 * @author 2Amigos
 * @date 2025-09-28
 */

SaveMessageCommand::SaveMessageCommand(ChatRoom* room, Users* user, string msg) : Command(room, user, msg){}

void SaveMessageCommand::execute()
{
    if (room != nullptr && fromUser != nullptr)
    {
        string formattedMessage = fromUser->getName() + ": " + message;
        room->saveMessage(formattedMessage, fromUser);
    }
}