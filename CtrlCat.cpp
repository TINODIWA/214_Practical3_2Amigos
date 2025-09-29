#include "CtrlCat.h"
#include "Users.h"
// #include "CatThemeStrategy.h"

/**
 * @file CtrlCat.cpp
 * @brief Implementation of CtrlCat concrete mediator
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @brief Constructor for CtrlCat chat room
 * 
 * Initializes the CtrlCat concrete mediator with cat-themed messaging capabilities.
 * Sets up the foundation for a positive, friendly chat environment focused on
 * programming community building and collaborative learning.
 * 
 * @note Currently prepared for Strategy pattern integration (commented out)
 * @note Inherits from ChatRoom abstract mediator class
 */
CtrlCat::CtrlCat() 
{
    // Set the cat-themed message processing strategy
    // setMessageProcessingStrategy(new CatThemeStrategy());
}

/**
 * @brief Register a user to the CtrlCat chat room
 * 
 * Adds a user to the CtrlCat community, enabling them to participate in
 * cat-themed programming discussions and access community features.
 * 
 * @param user Pointer to the user to register in the chat room
 * 
 * @note Users can be registered to multiple chat rooms simultaneously
 * @note Uses inherited getUsers() method to access the user vector
 * @see ChatRoom::getUsers() for the underlying storage mechanism
 */
void CtrlCat::registerUser(Users *user)
{
    // register a user to the chat room
    getUsers().push_back(user);
}

/**
 * @brief Get the name of the CtrlCat chat room
 * 
 * Returns the distinctive name identifier for this concrete mediator.
 * Used throughout the system for room identification and display purposes.
 * 
 * @return String containing the room name "CtrlCat"
 * 
 * @note This method implements the pure virtual function from ChatRoom
 * @note Room name is used in logging, user interface, and Template Method operations
 */
string CtrlCat::getRoomName()
{
    return "CtrlCat";
}

/**
 * @brief Validate message content for CtrlCat community standards
 * 
 * Implements the Template Method pattern hook for message validation.
 * CtrlCat enforces community-friendly standards by filtering inappropriate
 * content and ensuring positive communication environment.
 * 
 * @param message The message content to validate
 * @param fromUser Pointer to the user sending the message
 * @return true if message passes validation, false otherwise
 * 
 * @details Validation Rules:
 * - Empty messages are rejected
 * - Inappropriate language is filtered (idiot, stupid, dumb, swearword)
 * - Friendly error messages guide users toward positive communication
 * - Cat emoji (😿) used in feedback to maintain room theme
 * 
 * @note This method is called as part of the Template Method workflow
 * @note Failed validation prevents message from proceeding through the system
 */
bool CtrlCat::validateMessage(string message, Users *fromUser)
{
    if (message.empty()) {
        return false;
    }
    
    // Check for inappropriate content
    if (message.find("idiot") != string::npos || 
        message.find("stupid") != string::npos ||
        message.find("dumb") != string::npos ||
        message.find("swearword") != string::npos) {
        cout << "😿 CtrlCat is a positive space! Please keep messages friendly." << endl;
        return false;
    }
    
    return true;
}

/**
 * @brief Check user permissions for posting in CtrlCat
 * 
 * Implements the Template Method pattern hook for permission validation.
 * CtrlCat enforces a sophisticated permission system with multiple levels
 * of access control and anti-spam measures.
 * 
 * @param fromUser Pointer to the user requesting permission to post
 * @return true if user has permission to post, false otherwise
 * 
 * @details Permission System:
 * - Level 4 (Admin): Full access, no restrictions
 * - Level 3 (Moderator): Full access, no restrictions
 * - Level 2 (Member): Limited to 10 messages when new
 * - Level 1 (Guest): Cannot post in CtrlCat
 * 
 * @details Anti-Spam Features:
 * - Null pointer protection
 * - Mute status checking with friendly notification
 * - New member message limits (10 messages)
 * - Daily message caps (100 messages)
 * - Helpful upgrade suggestions for guests
 * 
 * @note Uses cat-themed emojis and friendly language in all notifications
 * @note Part of the Template Method workflow for message processing
 */
bool CtrlCat::checkPermissions(Users *fromUser)
{
    if (fromUser == nullptr) {
        return false;
    }
    
    // Check if user is muted
    if (fromUser->isMutedUser()) {
        cout << "🔇 " << fromUser->getName() << " is currently muted and cannot send messages." << endl;
        return false;
    }
    
    // Check permission level (CtrlCat requires at least Member level = 2)
    if (fromUser->getPermissionLevel() < 2) {
        cout << "👋 " << fromUser->getName() << ", please upgrade to Member status to post in CtrlCat!" << endl;
        cout << "💡 Tip: Participate in discussions to earn Member status!" << endl;
        return false;
    }
    
    // Spam protection - limit messages for new members
    if (fromUser->getPermissionLevel() == 2 && fromUser->getMessageCount() > 10) {
        cout << "⏳ New members are limited to 10 messages. Please wait or get promoted!" << endl;
        return false;
    }
    
    // Anti-spam for regular users
    if (fromUser->getMessageCount() > 100) {
        cout << "📢 Daily message limit reached! Please wait for reset or contact a moderator." << endl;
        return false;
    }
    
    return true;
}

/**
 * @brief Log user activity in CtrlCat with cat-themed formatting
 * 
 * Implements the Template Method pattern hook for activity logging.
 * Provides cat-themed, friendly logging format that maintains the
 * welcoming atmosphere of the CtrlCat community.
 * 
 * @param originalMessage The original message content before processing
 * @param fromUser Pointer to the user who sent the message
 * 
 * @note This method is called as part of the Template Method workflow
 * @note Uses cat emojis (😸) and friendly language to maintain room theme
 */
void CtrlCat::logActivity(string originalMessage, Users *fromUser)
{
    // Cat-themed activity logging
    cout << "📝 😸 [LOG] " << fromUser->getName() << " shared something in CtrlCat" << endl;
}

/**
 * @brief Perform post-processing actions with advanced user engagement features
 * 
 * Implements the Template Method pattern hook for post-processing actions.
 * CtrlCat provides comprehensive user engagement through achievement systems,
 * reward mechanisms, and community building features. This method analyzes
 * message content to provide contextual feedback and rewards.
 * 
 * @param originalMessage The original message content before any processing
 * @param fromUser Pointer to the user who sent the message
 * 
 * @details Engagement Features:
 * - 🏆 Bug Hunter System: Rewards for debugging discussions (bug, mouse, debug)
 * - 🎯 CtrlCat Coin Economy: Virtual currency for active participation
 * - ❤️ Community Helper Recognition: Bonuses for helpful behavior (help, assist, support)
 * - ✨ Code Quality Champions: Recognition for clean code advocacy (refactor, clean, optimize)
 * - 📚 Learning Resource System: Automatic suggestions for educational content (learn, tutorial)
 * - 💻 Code Sharing Appreciation: Recognition for sharing code snippets
 * - 😻 Cat Pun Engagement: Fun interaction rewards for cat-themed content (paw, purr, meow)
 * 
 * @note This method is called as the final step in the Template Method workflow
 * @note All rewards and recognition are displayed immediately to provide instant feedback
 */
void CtrlCat::postProcessActions(string originalMessage, Users *fromUser)
{    
    // Bug hunting achievements
    if (originalMessage.find("bug") != string::npos || 
        originalMessage.find("mouse") != string::npos ||
        originalMessage.find("debug") != string::npos) {
        cout << "🏆 " << fromUser->getName() << " earned 'Mouse Hunter' points for bug reporting!" << endl;
        cout << "🎯 Bug bounty: +5 CtrlCat coins added to your account!" << endl;
    }
    
    // Help and collaboration rewards
    if (originalMessage.find("help") != string::npos || 
        originalMessage.find("assist") != string::npos ||
        originalMessage.find("support") != string::npos) {
        cout << "🐾 CtrlCat community tip: Remember to purr-fect your code with proper testing!" << endl;
        cout << "❤️ Community helper bonus: Your helpfulness rating increased!" << endl;
    }
    
    // Code quality detection
    if (originalMessage.find("refactor") != string::npos ||
        originalMessage.find("clean") != string::npos ||
        originalMessage.find("optimize") != string::npos) {
        cout << "✨ Code quality champion! " << fromUser->getName() << " is making the codebase purr-fect!" << endl;
    }
    
    // Learning and growth tracking
    if (originalMessage.find("learn") != string::npos ||
        originalMessage.find("tutorial") != string::npos ||
        originalMessage.find("how to") != string::npos) {
        cout << "📚 Curious cat alert! Learning resources have been whisker-ed your way!" << endl;
        cout << "🎓 Growth mindset bonus: +3 learning points!" << endl;
    }
    
    // Positive reinforcement for sharing code
    if (originalMessage.find("code") != string::npos ||
        originalMessage.find("function") != string::npos ||
        originalMessage.find("snippet") != string::npos) {
        cout << "💻 Code sharing detected! The cat community appreciates your contribution!" << endl;
    }
    
    // Fun cat puns and engagement
    if (originalMessage.find("paw") != string::npos ||
        originalMessage.find("purr") != string::npos ||
        originalMessage.find("meow") != string::npos) {
        cout << "😻 Paw-some cat puns! You're the cat's pajamas in this community!" << endl;
    }
}

/**
 * @brief Save message to CtrlCat's chat history
 * 
 * Implements the Template Method pattern hook for message persistence.
 * CtrlCat uses a simple approach to store validated messages directly
 * into the chat history for later retrieval.
 * 
 * @param message The processed message content to save
 * @param fromUser Pointer to the user who sent the message (currently unused in implementation)
 * 
 * @note This method is called after all validation and permission checks pass
 * @note Uses the inherited getChatHistory() method to access the message storage vector
 * @see ChatRoom::getChatHistory() for the underlying storage mechanism
 */
void CtrlCat::saveMessage(string message, Users *fromUser)
{
    // add message to chat history
    getChatHistory().push_back(message);
}

/**
 * @brief Remove a user from the CtrlCat chat room
 * 
 * Safely removes a user from the chat room's user list using iterator-based
 * search and erase. This method ensures proper cleanup when users leave
 * the CtrlCat community.
 * 
 * @param user Pointer to the user to be removed from the chat room
 * 
 * @details Implementation Features:
 * - Iterator-based search for safe pointer comparison
 * - Single removal (returns after first match found)
 * - Uses inherited getUsers() method for access to user vector
 * - Maintains vector integrity during removal operation
 * 
 * @note Uses vector::erase() which invalidates iterators after the erased element
 * @note Returns immediately after removal to avoid iterator invalidation issues
 * @see ChatRoom::getUsers() for the underlying user storage mechanism
 */
void CtrlCat::removeUser(Users *user)
{
    // deregister a user from the chat room
    for (vector<Users *>::iterator us = getUsers().begin(); us != getUsers().end(); us++)
    {
        if (*us == user)
        {
            getUsers().erase(us);
            return;
        }
    }
}
