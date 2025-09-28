#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

/**
 * @file Dogorithm.h
 * @brief Dogorithm concrete mediator for dog-themed chat room
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class Dogorithm
 * @brief Concrete mediator implementation for the dog-themed chat room
 * 
 * This class implements the ChatRoom interface and provides specific
 * functionality for the Dogorithm chat room, including user management
 * and message handling with dog-themed branding.
 */
class Dogorithm : public ChatRoom
{
public:
    /**
     * @brief Default constructor
     */
    Dogorithm();
    
    /**
     * @brief Register a user to the Dogorithm chat room
     * @param user Pointer to the user to register
     */
    virtual void registerUser(Users *user);
    
    /**
     * @brief Get the name of this chat room
     * @return String "Dogorithm"
     */
    virtual string getRoomName();

protected:
    // Template Method customizations for Dogorithm room
    
    /**
     * @brief Validate message for algorithm-focused room
     * @param message The message content to validate
     * @param fromUser The user sending the message
     * @return True if message passes algorithm room validation
     */
    virtual bool validateMessage(string message, Users *fromUser);
    
    /**
     * @brief Check permissions for Dogorithm room (technical verification)
     * @param fromUser The user attempting to send the message
     * @return True if user can send messages
     */
    virtual bool checkPermissions(Users *fromUser);
    
    /**
     * @brief Log activity with algorithm-focused format
     * @param originalMessage The original message before processing
     * @param fromUser The user who sent the message
     */
    virtual void logActivity(string originalMessage, Users *fromUser);
    
    /**
     * @brief Algorithm-focused post-processing actions
     * @param originalMessage The original message
     * @param fromUser The user who sent the message
     */
    virtual void postProcessActions(string originalMessage, Users *fromUser);
    
    /**
     * @brief Save a message to Dogorithm's chat history
     * @param message The message content to save
     * @param fromUser Pointer to the user who sent the message
     */
    virtual void saveMessage(string message, Users *fromUser);
    
    /**
     * @brief Remove a user from Dogorithm
     * @param user Pointer to the user to remove
     */
    virtual void removeUser(Users *user);
};

#endif