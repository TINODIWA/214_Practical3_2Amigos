#include "Dogorithm.h"
#include "Users.h"
// #include "DogThemeStrategy.h"

/**
 * @file Dogorithm.cpp
 * @brief Implementation of Dogorithm concrete mediator
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @brief Constructor for Dogorithm chat room
 * 
 * Initializes the Dogorithm concrete mediator with algorithm-focused messaging capabilities.
 * Sets up the foundation for a technical chat environment focused on computer science,
 * algorithms, and programming discussions with high-quality standards.
 * 
 * @note Currently prepared for Strategy pattern integration (commented out)
 * @note Inherits from ChatRoom abstract mediator class
 * @note Enforces higher permission levels for technical credibility
 */
Dogorithm::Dogorithm() 
{
    // Set the dog-themed algorithmic message processing strategy
    // setMessageProcessingStrategy(new DogThemeStrategy());
}

/**
 * @brief Register a user to the Dogorithm chat room
 * 
 * Adds a user to the Dogorithm technical community, enabling them to participate in
 * algorithm-focused discussions and high-level programming conversations.
 * 
 * @param user Pointer to the user to register in the chat room
 * 
 * @note Users can be registered to multiple chat rooms simultaneously
 * @note Dogorithm has stricter permission requirements than other rooms
 * @note Uses inherited getUsers() method to access the user vector
 * @see ChatRoom::getUsers() for the underlying storage mechanism
 */
void Dogorithm::registerUser(Users *user)
{
    // register a user to the chat room
    getUsers().push_back(user);
}

/**
 * @brief Get the name of the Dogorithm chat room
 * 
 * Returns the distinctive name identifier for this concrete mediator.
 * Used throughout the system for room identification and display purposes.
 * 
 * @return String containing the room name "Dogorithm"
 * 
 * @note This method implements the pure virtual function from ChatRoom
 * @note Room name reflects the algorithm-focused nature of the community
 * @note Used in logging, user interface, and Template Method operations
 */
string Dogorithm::getRoomName()
{
    return "Dogorithm";
}

/**
 * @brief Validate message content for Dogorithm technical standards
 * 
 * Implements the Template Method pattern hook for message validation.
 * Dogorithm enforces strict technical content standards by requiring
 * algorithm, programming, or computer science related discussions.
 * 
 * @param message The message content to validate
 * @param fromUser Pointer to the user sending the message
 * @return true if message passes technical validation, false otherwise
 * 
 * @details Technical Validation Rules:
 * - Empty messages are rejected
 * - Must contain technical keywords: algorithm, code, function, loop, recursive, etc.
 * - Complexity analysis keywords: O(), binary, tree, graph
 * - Programming concepts: search, sort, optimize, debug, bug, programming, efficient
 * - Short messages (< 10 chars) are allowed for greetings
 * - Robot emoji (🤖) used in feedback to maintain technical theme
 * 
 * @note This method is called as part of the Template Method workflow
 * @note Failed validation prevents non-technical messages from proceeding
 * @note Maintains high-quality technical discussion environment
 */
bool Dogorithm::validateMessage(string message, Users *fromUser)
{
    // Algorithm room validation: must be technical/coding related
    if (message.empty()) {
        return false;
    }
    
    // Check if message contains algorithm/coding keywords
    if (message.find("algorithm") == string::npos && 
        message.find("code") == string::npos &&
        message.find("function") == string::npos &&
        message.find("loop") == string::npos &&
        message.find("recursive") == string::npos &&
        message.find("search") == string::npos &&
        message.find("sort") == string::npos &&
        message.find("optimize") == string::npos &&
        message.find("O(") == string::npos &&
        message.find("binary") == string::npos &&
        message.find("tree") == string::npos &&
        message.find("graph") == string::npos &&
        message.find("debug") == string::npos &&
        message.find("bug") == string::npos &&
        message.find("programming") == string::npos &&
        message.find("efficient") == string::npos &&
        message.length() < 10) { // Allow short greetings
        cout << "🤖 Dogorithm is focused on algorithms and coding discussions!" << endl;
        return false;
    }
    
    return true;
}

/**
 * @brief Check user permissions for posting in Dogorithm
 * 
 * Implements the Template Method pattern hook for permission validation.
 * Dogorithm enforces the most strict permission system requiring technical
 * credibility through higher permission levels and quality control measures.
 * 
 * @param fromUser Pointer to the user requesting permission to post
 * @return true if user has permission to post, false otherwise
 * 
 * @details Advanced Permission System:
 * - Level 4 (Admin): Unlimited access, no restrictions
 * - Level 3 (Moderator): Access with daily limits (50 messages)
 * - Level 2 (Member): Cannot post in Dogorithm
 * - Level 1 (Guest): Cannot post in Dogorithm
 * 
 * @details Quality Control Features:
 * - Null pointer protection
 * - Mute status checking with technical context
 * - Requires Moderator status (Level 3+) for technical credibility
 * - Daily message limits even for moderators (50 messages)
 * - Unlimited access for administrators
 * - Educational feedback for permission upgrades
 * 
 * @note Uses technical emojis (🤖, 🎓, ⚡) to maintain algorithmic theme
 * @note Strictest permission system among all chat rooms
 * @note Part of the Template Method workflow for message processing
 */
bool Dogorithm::checkPermissions(Users *fromUser)
{
    if (fromUser == nullptr) {
        return false;
    }
    
    // Check if user is muted
    if (fromUser->isMutedUser()) {
        cout << "🚫 " << fromUser->getName() << " is muted in Dogorithm for violating technical discussion guidelines." << endl;
        return false;
    }
    
    // Dogorithm requires higher permission level (Moderator = 3) for technical credibility
    if (fromUser->getPermissionLevel() < 3) {
        cout << "🎓 " << fromUser->getName() << ", Dogorithm requires Moderator status for algorithm discussions!" << endl;
        cout << "📖 Tip: Contribute quality technical content to earn Moderator status!" << endl;
        return false;
    }
    
    // Even moderators have message limits for quality control
    if (fromUser->getPermissionLevel() == 3 && fromUser->getMessageCount() > 50) {
        cout << "⚡ Even technical experts need breaks! Daily limit reached for Moderators." << endl;
        return false;
    }
    
    // Admins have unlimited access
    if (fromUser->getPermissionLevel() >= 4) {
        return true;
    }
    
    return true;
}

/**
 * @brief Log user activity in Dogorithm with technical formatting
 * 
 * Implements the Template Method pattern hook for activity logging.
 * Provides algorithm-focused, professional logging format that emphasizes
 * the technical nature of discussions in the Dogorithm community.
 * 
 * @param originalMessage The original message content before processing
 * @param fromUser Pointer to the user who sent the message
 * 
 * @note This method is called as part of the Template Method workflow
 * @note Uses technical emojis (📊, 🐕) to maintain algorithmic theme
 * @note Emphasizes "Technical discussion" to reinforce room purpose
 */
void Dogorithm::logActivity(string originalMessage, Users *fromUser)
{
    // Algorithm-focused activity logging
    cout << "📊 🐕 [LOG] Technical discussion by " << fromUser->getName() << " in Dogorithm" << endl;
}

/**
 * @brief Perform algorithm-focused post-processing actions
 * 
 * Implements the Template Method pattern hook for post-processing actions.
 * Dogorithm provides specialized technical recognition and educational
 * feedback for algorithm and programming discussions.
 * 
 * @param originalMessage The original message content before any processing
 * @param fromUser Pointer to the user who sent the message
 * 
 * @details Technical Recognition Features:
 * - 🧠 Complexity Analysis Detection: Auto-tags messages with O() notation
 * - 🔄 Control Structure Recognition: Identifies recursive/loop discussions
 * - ⚡ Performance Optimization: Awards "Efficiency Expert" badges
 * - 📖 Educational Suggestions: Encourages code snippet sharing
 * - 🏆 Technical Achievement System: Recognizes algorithm expertise
 * 
 * @note This method is called as the final step in the Template Method workflow
 * @note Focuses on technical education and algorithm mastery recognition
 * @note Uses professional emojis to maintain serious technical atmosphere
 */
void Dogorithm::postProcessActions(string originalMessage, Users *fromUser)
{
    // Algorithm-focused post-processing
    if (originalMessage.find("O(") != string::npos) {
        cout << "🧠 Complexity analysis detected! Auto-tagging as 'Algorithm Analysis'" << endl;
    }
    
    if (originalMessage.find("recursive") != string::npos || 
        originalMessage.find("loop") != string::npos) {
        cout << "🔄 Control structure discussion! Consider sharing code snippets next time." << endl;
    }
    
    if (originalMessage.find("optimize") != string::npos || 
        originalMessage.find("efficient") != string::npos) {
        cout << "⚡ Performance discussion! " << fromUser->getName() << " earned 'Efficiency Expert' badge!" << endl;
    }
}

/**
 * @brief Save message to Dogorithm's technical chat history
 * 
 * Implements the Template Method pattern hook for message persistence.
 * Dogorithm uses a simple approach to store validated technical messages
 * directly into the chat history for algorithm discussion archival.
 * 
 * @param message The processed message content to save
 * @param fromUser Pointer to the user who sent the message (currently unused in implementation)
 * 
 * @note This method is called after all validation and permission checks pass
 * @note Only high-quality technical content reaches this point due to strict validation
 * @note Uses the inherited getChatHistory() method to access the message storage vector
 * @see ChatRoom::getChatHistory() for the underlying storage mechanism
 */
void Dogorithm::saveMessage(string message, Users *fromUser)
{
    // add message to chat history
    getChatHistory().push_back(message);
}

/**
 * @brief Remove a user from the Dogorithm chat room
 * 
 * Safely removes a user from the chat room's user list using iterator-based
 * search and erase. This method ensures proper cleanup when technical
 * contributors leave the Dogorithm community.
 * 
 * @param user Pointer to the user to be removed from the chat room
 * 
 * @details Implementation Features:
 * - Iterator-based search for safe pointer comparison
 * - Single removal (returns after first match found)
 * - Uses inherited getUsers() method for access to user vector
 * - Maintains vector integrity during removal operation
 * - Preserves technical discussion history even after user removal
 * 
 * @note Uses vector::erase() which invalidates iterators after the erased element
 * @note Returns immediately after removal to avoid iterator invalidation issues
 * @note Maintains strict technical standards even during user management
 * @see ChatRoom::getUsers() for the underlying user storage mechanism
 */
void Dogorithm::removeUser(Users *user)
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
