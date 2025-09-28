#ifndef CHATROOM_H
#define CHATROOM_H

// #include "ChatRoomIterator.h"
// #include "MessageProcessingStrategy.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Users;

/**
 * @file ChatRoom.h
 * @brief Abstract ChatRoom class implementing Mediator patterns
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class ChatRoom
 * @brief Abstract base class for chat rooms in the Mediator pattern.
 * 
 * This class serves as the mediator between users.
 */
class ChatRoom
{
public:
    /**
     * @brief Default constructor
     */
    ChatRoom();
    
    /**
     * @brief Constructor with message processing strategy
     * @param strategy Pointer to the message processing strategy to use
     */
    // ChatRoom(MessageProcessingStrategy* strategy);
    
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~ChatRoom();

    /**
     * @brief Register a user to the chat room
     * @param user Pointer to the user to register
     */
    virtual void registerUser(Users *user) = 0;
    
    /**
     * @brief Template Method: Complete message handling workflow
     * 
     * This method defines the complete algorithm for handling messages:
     * 1. Validate message content and sender
     * 2. Check user permissions  
     * 3. Pre-process message (using Strategy pattern)
     * 4. Broadcast to all users in room
     * 5. Save message to history
     * 6. Log activity for audit trail
     * 7. Perform post-processing actions
     * 
     * @param message The message content
     * @param fromUser Pointer to the user sending the message
     */
    virtual void sendMessage(string message, Users *fromUser);

protected:
    // Template Method steps - some implemented, some customizable by subclasses
    
    /**
     * @brief Validate message content and sender (customizable)
     * @param message The message content to validate
     * @param fromUser The user sending the message
     * @return True if message is valid, false otherwise
     */
    virtual bool validateMessage(string message, Users *fromUser) = 0;
    
    /**
     * @brief Check if user has permission to send messages (customizable)
     * @param fromUser The user attempting to send the message
     * @return True if user has permission, false otherwise
     */
    virtual bool checkPermissions(Users *fromUser) = 0;
    
    /**
     * @brief Pre-process message using Strategy pattern (customizable)
     * @param message The original message
     * @param fromUser The user sending the message
     * @return The processed message
     */
    virtual string preprocessMessage(string message, Users *fromUser);
    
    /**
     * @brief Broadcast message to all users (common implementation)
     * @param processedMessage The processed message to broadcast
     * @param fromUser The user who sent the message
     */
    virtual void broadcastMessage(string processedMessage, Users *fromUser);
    
    /**
     * @brief Log activity for audit trail (customizable)
     * @param originalMessage The original message before processing  
     * @param fromUser The user who sent the message
     */
    virtual void logActivity(string originalMessage, Users *fromUser) = 0;
    
    /**
     * @brief Perform post-processing actions (customizable)
     * @param originalMessage The original message
     * @param fromUser The user who sent the message
     */
    virtual void postProcessActions(string originalMessage, Users *fromUser) = 0;

public:
    /**
     * @brief Remove a user from the chat room
     * @param user Pointer to the user to remove
     */
    virtual void removeUser(Users *user) = 0;
    
    /**
     * @brief Create an iterator for the chat history
     * @return Pointer to a ChatRoomIterator for traversing messages
     */
    // virtual ChatRoomIterator* createIterator();
    
    /**
     * @brief Get the name of this chat room
     * @return String containing the room name
     */
    virtual string getRoomName() = 0;
    
    /**
     * @brief Set the message processing strategy
     * @param strategy Pointer to the new strategy to use
     */
    // virtual void setMessageProcessingStrategy(MessageProcessingStrategy* strategy);
    
    /**
     * @brief Get the current message processing strategy
     * @return Pointer to the current strategy
     */
    // virtual MessageProcessingStrategy* getMessageProcessingStrategy();
    
    /**
     * @brief Save a message to the chat room's history (made public for Commands)
     * @param message The message content to save
     * @param fromUser Pointer to the user who sent the message
     */
    virtual void saveMessage(string message, Users *fromUser);
    
    /**
     * @brief Get reference to users vector (for derived classes)
     * @return Reference to the users vector
     */
    vector<Users *> &getUsers();
    
    /**
     * @brief Get reference to chat history vector (for derived classes)
     * @return Reference to the chat history vector
     */
    vector<string> &getChatHistory();

protected:
    // MessageProcessingStrategy* messageStrategy; 
    // Strategy for processing messages

private:
    vector<Users *> users;       // List of users in this chat room
    vector<string> chatHistory;  // History of messages in this chat room
};

#endif