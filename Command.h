#ifndef COMMAND_H
#define COMMAND_H

#include <string>

using namespace std;

// Forward declarations
class ChatRoom;
class Users;

/**
 * @file Command.h
 * @brief Abstract Command interface for the Command design pattern
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class Command
 * @brief Abstract base class for commands in the Command pattern
 * 
 * Encapsulates a request as an object, allowing for parameterization of clients
 * with different requests, queuing of requests, and logging of requests.
 */
class Command
{
protected:
    ChatRoom* room;   // The chat room where the command will be executed
    Users* fromUser;      // The user who initiated the command
    string message;       // The message associated with the command

public:
    /**
     * @brief Constructor for Command
     * @param room Pointer to the chat room
     * @param user Pointer to the user initiating the command
     * @param msg The message content
     */
    Command(ChatRoom* room, Users* user, string msg);
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Command() = default;
    
    /**
     * @brief Execute the command - pure virtual method
     */
    virtual void execute() = 0;
};

#endif