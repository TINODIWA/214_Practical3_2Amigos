#include "SendMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

/**
 * @file SendMessageCommand.cpp
 * @brief Implementation of SendMessageCommand class
 * @author 2Amigos
 * @date 2025-09-28
 */

SendMessageCommand::SendMessageCommand(ChatRoom* room, Users* user, string msg) : Command(room, user, msg){}

void SendMessageCommand::execute()
{
    if (room != nullptr && fromUser != nullptr)
    {
        room->sendMessage(message, fromUser);
    }
}