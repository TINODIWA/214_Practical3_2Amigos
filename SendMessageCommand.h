#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

/**
 * @file SendMessageCommand.h
 * @brief Concrete command for sending messages
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class SendMessageCommand
 * @brief Concrete command that handles sending messages to all users in a chat room
 * 
 * This command encapsulates the action of broadcasting a message to all users
 * currently in the specified chat room.
 */
class SendMessageCommand : public Command
{
public:
    /**
     * @brief Constructor for SendMessageCommand
     * @param room Pointer to the chat room where message should be sent
     * @param user Pointer to the user sending the message
     * @param msg The message content to send
     */
    SendMessageCommand(ChatRoom* room, Users* user, string msg);
    
    /**
     * @brief Execute the send message command
     * 
     * Calls the chatRoom's sendMessage method to broadcast the message
     * to all users in the room
     */
    virtual void execute();
};

#endif