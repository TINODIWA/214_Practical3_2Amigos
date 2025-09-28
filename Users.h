#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>

using namespace std;

// Forward declarations
class ChatRoom;
class Command;

/**
 * @file Users.h
 * @brief Abstract Users class implementing Observer pattern and Command invoker
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class Users
 * @brief Abstract base class for users in the chat system
 * 
 * This class serves as the Colleague in the Mediator pattern, Observer in the Observer pattern,
 * and Invoker in the Command pattern. It manages user interactions with chat rooms
 * and handles command execution for messaging operations.
 */
class Users
{
public:
    /**
     * @brief Constructor for Users
     * @param room Pointer to the primary chat room for this user
     * @param name The user's name
     */
    Users(ChatRoom *room, string name);
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~Users();

    /**
     * @brief Send a message to a chat room using Command pattern
     * @param message The message content to send
     * @param room Pointer to the chat room to send the message to
     */
    virtual void send(string message, ChatRoom *room);
    
    /**
     * @brief Receive and display a message (for compatibility)
     * @param message The message content
     * @param fromUser Pointer to the user who sent the message
     * @param room Pointer to the chat room where the message was sent
     */
    virtual void receive(string message, Users *fromUser, ChatRoom *room);
    
    /**
     * @brief Add a command to the command queue
     * @param command Pointer to the command to add
     */
    virtual void addCommand(Command* command);
    
    /**
     * @brief Execute all queued commands in sequence
     */
    virtual void executeAll();
    
    /**
     * @brief Get the user's name
     * @return The user's name as a string
     */
    virtual string getName();
    
    /**
     * @brief Get the user's permission level
     * @return Permission level (1=Guest, 2=Member, 3=Moderator, 4=Admin)
     */
    virtual int getPermissionLevel();
    
    /**
     * @brief Set the user's permission level
     * @param level New permission level
     */
    virtual void setPermissionLevel(int level);
    
    /**
     * @brief Check if user is muted
     * @return True if user is muted
     */
    virtual bool isMutedUser();
    
    /**
     * @brief Mute or unmute the user
     * @param muted True to mute, false to unmute
     */
    virtual void setMuted(bool muted);
    
    /**
     * @brief Get the user's message count
     * @return Number of messages sent
     */
    virtual int getMessageCount();
    
    /**
     * @brief Increment message count (called when user sends message)
     */
    virtual void incrementMessageCount();
    


protected:
    ChatRoom *chatRooms;              // Primary chat room for this user
    string name;                      // User's name
    vector<Command*> commandQueue;    // Queue of commands to execute
    int permissionLevel;              // Permission level: 1=Guest, 2=Member, 3=Moderator, 4=Admin
    bool isMuted;                     // Whether user is temporarily muted
    int messageCount;                 // Number of messages sent (for spam detection)
};

#endif
