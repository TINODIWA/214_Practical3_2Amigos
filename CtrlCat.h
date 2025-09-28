#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

/**
 * @file CtrlCat.h
 * @brief CtrlCat concrete mediator for cat-themed chat room
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @class CtrlCat
 * @brief Concrete mediator implementation for the cat-themed chat room
 * 
 * This class implements the ChatRoom interface and provides specific
 * functionality for the CtrlCat chat room, including user management
 * and message handling with cat-themed branding.
 */
class CtrlCat : public ChatRoom
{
public:
    /**
     * @brief Default constructor
     */
    CtrlCat();
    
    /**
     * @brief Register a user to the CtrlCat chat room
     * @param user Pointer to the user to register
     */
    virtual void registerUser(Users *user);
    
    /**
     * @brief Get the name of this chat room
     * @return String "CtrlCat"
     */
    virtual string getRoomName();

protected:
    // Template Method customizations for CtrlCat room
    
    /**
     * @brief Validate message for cat-themed room
     * @param message The message content to validate
     * @param fromUser The user sending the message
     * @return True if message passes cat room validation
     */
    virtual bool validateMessage(string message, Users *fromUser);
    
    /**
     * @brief Check permissions for CtrlCat room (friendly, open policy)
     * @param fromUser The user attempting to send the message
     * @return True if user can send messages
     */
    virtual bool checkPermissions(Users *fromUser);
    
    /**
     * @brief Log activity with cat-themed format
     * @param originalMessage The original message before processing
     * @param fromUser The user who sent the message
     */
    virtual void logActivity(string originalMessage, Users *fromUser);
    
    /**
     * @brief Cat-themed post-processing actions
     * @param originalMessage The original message
     * @param fromUser The user who sent the message
     */
    virtual void postProcessActions(string originalMessage, Users *fromUser);
    
    /**
     * @brief Save a message to CtrlCat's chat history
     * @param message The message content to save
     * @param fromUser Pointer to the user who sent the message
     */
    virtual void saveMessage(string message, Users *fromUser);
    
    /**
     * @brief Remove a user from CtrlCat
     * @param user Pointer to the user to remove
     */
    virtual void removeUser(Users *user);
};

#endif