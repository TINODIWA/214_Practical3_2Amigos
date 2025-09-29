#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"
#include <iostream>
// #in
/**
 * @brief Execute all queued commands
 * 
 * Implements the command execution mechanism for the Command pattern.
 * Processes all commands in the queue sequentially, ensuring proper
 * resource management and queue cleanup after execution.
 * 
 * @details Execution Process:
 * 1. Iterates through all commands in the queue (FIFO order)
 * 2. Validates each command before execution (null pointer check)
 * 3. Executes each command through its execute() method
 * 4. Immediately deletes each command after execution (memory cleanup)
 * 5. Clears the entire queue after all executions complete
 * 
 * @note Critical part of the Invoker role in the Command pattern
 * @note Immediate memory cleanup prevents memory leaks
 * @note Queue is cleared after execution to prevent re-execution
 * @note Null commands are safely skipped without errors
 * @note Uses range-based for loop for efficient iteration
 * 
 * @see addCommand() for command queueing mechanism
 */

/**
 * @file Users.cpp
 * @brief Implementation of Users colleague class for Mediator pattern
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @brief Constructor for Users (Colleague in Mediator pattern)
 * 
 * Initializes a user with default settings and associates them with a chat room.
 * Sets up the foundation for Command pattern integration and permission system.
 * 
 * @param room Pointer to the ChatRoom (Mediator) this user will communicate through
 * @param name The display name for this user
 * 
 * @details Default Initialization:
 * - Permission Level: 2 (Member level)
 * - Muted Status: false (not muted)
 * - Message Count: 0 (no messages sent yet)
 * - Command Queue: empty (ready for Command pattern usage)
 * 
 * @note This constructor sets up the Colleague side of the Mediator pattern
 * @note Default permission level allows basic participation in most rooms
 * @note Command queue is initialized empty and ready for command queueing
 */
Users::Users(ChatRoom *room, string name) : chatRooms(room), name(name), permissionLevel(2), isMuted(false), messageCount(0) {}

/**
 * @brief Destructor for Users
 * 
 * Properly cleans up all resources associated with the user, particularly
 * any queued commands in the Command pattern implementation. Ensures no
 * memory leaks when user objects are destroyed.
 * 
 * @details Cleanup Process:
 * - Iterates through all commands in the command queue
 * - Deletes each command object to prevent memory leaks
 * - Ensures proper resource management for Command pattern
 * 
 * @note Critical for preventing memory leaks in Command pattern usage
 * @note Called automatically when user objects go out of scope
 * @note Uses range-based for loop for efficient iteration
 */
Users::~Users() 
{
    // Clean up commands
    for (Command* cmd : commandQueue)
    {
        delete cmd;
    }
}

/**
 * @brief Send a message through the Command pattern
 * 
 * Implements the Command pattern by creating command objects for message
 * operations and executing them through the command queue. This method
 * serves as the primary interface for users to send messages through
 * the Mediator pattern.
 * 
 * @param message The message content to send
 * @param room Pointer to the ChatRoom (Mediator) to send the message through
 * 
 * @details Command Pattern Implementation:
 * 1. Creates SendMessageCommand for actual message transmission
 * 2. Creates SaveMessageCommand for message persistence
 * 3. Adds both commands to the command queue
 * 4. Executes all queued commands in sequence
 * 
 * @note This method implements the Invoker role in the Command pattern
 * @note Commands are executed immediately after queueing (synchronous execution)
 * @note Both sending and saving are treated as separate command operations
 * @note Integrates Command pattern with Mediator pattern seamlessly
 * 
 * @see SendMessageCommand for message transmission implementation
 * @see SaveMessageCommand for message persistence implementation
 * @see addCommand() for command queueing mechanism
 * @see executeAll() for command execution process
 */
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

/**
 * @brief Legacy method for receiving messages
 * 
 * Provides backward compatibility for direct message reception.
 * This method bypasses the Command pattern and directly interacts
 * with the Mediator for simple message saving operations.
 * 
 * @param message The message content received
 * @param fromUser Pointer to the user who sent the message
 * @param room Pointer to the ChatRoom where the message was sent
 * 
 * @note This is a legacy method maintained for compatibility
 * @note Direct interaction with Mediator, bypassing Command pattern
 * @note Primarily used for simple message persistence operations
 * @note Consider using Command pattern for new implementations
 */
void Users::receive(string message, Users *fromUser, ChatRoom *room)
{
    // Legacy method for compatibility - just save the message
    room->saveMessage(fromUser->name + ": " + message, fromUser);
}

/**
 * @brief Add a command to the execution queue
 * 
 * Implements the command queueing mechanism for the Command pattern.
 * Safely adds commands to the queue with null pointer protection,
 * enabling batch execution of multiple operations.
 * 
 * @param command Pointer to the Command object to add to the queue
 * 
 * @details Safety Features:
 * - Null pointer validation before queueing
 * - Vector-based queue for efficient storage
 * - Support for multiple command types
 * - Maintains execution order (FIFO)
 * 
 * @note Part of the Invoker role in the Command pattern
 * @note Commands are not executed immediately, only queued
 * @note Null commands are safely ignored without errors
 * @see executeAll() for command execution process
 */
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

/**
 * @brief Get the user's display name
 * 
 * Returns the user's display name that is used throughout the system
 * for identification, logging, and user interface purposes.
 * 
 * @return String containing the user's name
 * 
 * @note Used in message attribution, logging, and permission checking
 * @note Name is set during construction and remains constant
 */
string Users::getName()
{
    return name;
}

/**
 * @brief Get the user's current permission level
 * 
 * Returns the user's permission level which determines their access
 * rights and capabilities within different chat rooms.
 * 
 * @return Integer representing the permission level (1-4)
 * 
 * @details Permission Levels:
 * - Level 1: Guest (limited access)
 * - Level 2: Member (standard access)
 * - Level 3: Moderator (advanced access)
 * - Level 4: Admin (full access)
 * 
 * @note Used by chat rooms to determine message posting permissions
 * @note Higher levels generally have more privileges and fewer restrictions
 */
int Users::getPermissionLevel()
{
    return permissionLevel;
}

/**
 * @brief Set the user's permission level
 * 
 * Updates the user's permission level with input validation to ensure
 * only valid permission levels are assigned. Invalid levels are ignored
 * to maintain system integrity.
 * 
 * @param level The new permission level to assign (must be 1-4)
 * 
 * @details Valid Permission Levels:
 * - Level 1: Guest (basic access, limited posting)
 * - Level 2: Member (standard access, most rooms)
 * - Level 3: Moderator (advanced access, technical rooms)
 * - Level 4: Admin (unlimited access, all privileges)
 * 
 * @note Invalid levels (< 1 or > 4) are silently ignored
 * @note Permission changes take effect immediately
 * @note Used for user promotion/demotion in the system
 */
void Users::setPermissionLevel(int level)
{
    if (level >= 1 && level <= 4) {
        permissionLevel = level;
    }
}

/**
 * @brief Check if the user is currently muted
 * 
 * Returns the user's mute status, which prevents them from sending
 * messages when set to true. Used by chat rooms to enforce
 * moderation policies.
 * 
 * @return true if user is muted, false if user can send messages
 * 
 * @note Muted users are blocked during permission checking in chat rooms
 * @note Mute status can be changed by administrators or moderators
 * @note Part of the moderation and anti-spam system
 */
bool Users::isMutedUser()
{
    return isMuted;
}

/**
 * @brief Set the user's mute status
 * 
 * Updates the user's mute status to enable or disable their ability
 * to send messages. Used by moderators and administrators for
 * community management and moderation purposes.
 * 
 * @param muted true to mute the user, false to unmute
 * 
 * @details Mute Effects:
 * - Muted users cannot send messages in any chat room
 * - Permission checks in all rooms will fail for muted users
 * - Used for temporary punishment or spam prevention
 * - Can be reversed by setting muted to false
 * 
 * @note Changes take effect immediately
 * @note Used by moderation systems for community management
 * @note Part of the anti-spam and behavioral enforcement system
 */
void Users::setMuted(bool muted)
{
    isMuted = muted;
}

/**
 * @brief Get the user's total message count
 * 
 * Returns the total number of messages this user has sent across
 * all chat rooms. Used for spam protection, rate limiting, and
 * user activity tracking.
 * 
 * @return Integer representing the total number of messages sent
 * 
 * @note Used by chat rooms for anti-spam measures and rate limiting
 * @note Incremented automatically when messages are successfully sent
 * @note Part of the user activity tracking and moderation system
 */
int Users::getMessageCount()
{
    return messageCount;
}

/**
 * @brief Increment the user's message count
 * 
 * Increases the user's message count by one. Called automatically
 * by the Template Method workflow when messages are successfully
 * sent and processed.
 * 
 * @details Usage Context:
 * - Called as Step 8 in the Template Method pattern (sendMessage)
 * - Only incremented for successfully sent messages
 * - Used for spam protection and activity tracking
 * - Enables rate limiting based on message volume
 * 
 * @note Automatically called by ChatRoom::sendMessage() Template Method
 * @note Only incremented after all validation and processing succeeds
 * @note Part of the user activity statistics system
 */
void Users::incrementMessageCount()
{
    messageCount++;
}

