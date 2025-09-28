#ifndef SAVEMESSAGECOMMAND_H
#define SAVEMESSAGECOMMAND_H

#include "Command.h"

/**
 * @file SaveMessageCommand.h
 * @brief Concrete command for saving messages to chat history
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class SaveMessageCommand
 * @brief Concrete command that handles saving messages to chat room history
 * 
 * This command encapsulates the action of storing a message in the
 * chat room's message history for later retrieval.
 */
class SaveMessageCommand : public Command
{
public:
    /**
     * @brief Constructor for SaveMessageCommand
     * @param room Pointer to the chat room where message should be saved
     * @param user Pointer to the user who sent the message
     * @param msg The message content to save
     */
    SaveMessageCommand(ChatRoom* room, Users* user, string msg);
    
    /**
     * @brief Execute the save message command
     * 
     * Calls the chatRoom's saveMessage method to store the message
     * in the room's chat history
     */
    virtual void execute();
};

#endif