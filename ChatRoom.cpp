#include "ChatRoom.h"
#include "Users.h"

/**
 * @file ChatRoom.cpp
 * @brief Implementation of ChatRoom abstract mediator base class
 * @author 2Amigos
 * @date 2025-09-28
 */

/**
 * @brief Default constructor for ChatRoom
 * 
 * Initializes the abstract mediator base class. Creates empty vectors
 * for users and chat history that will be managed by concrete mediator
 * implementations.
 * 
 * @note This constructor is called by derived concrete mediators
 * @note Sets up the foundation for Template Method pattern implementation
 */
ChatRoom::ChatRoom(){}

// ChatRoom::ChatRoom(MessageProcessingStrategy* strategy) : messageStrategy(strategy) {}

/**
 * @brief Virtual destructor for ChatRoom
 * 
 * Provides proper cleanup for the abstract base class. Ensures that
 * derived class destructors are called correctly when objects are
 * destroyed through base class pointers.
 * 
 * @note Virtual destructor is essential for proper polymorphic destruction
 * @note Allows safe destruction of concrete mediator implementations
 */
ChatRoom::~ChatRoom(){}

// ChatRoomIterator* ChatRoom::createIterator()
// {
//     return new ChatRoomIterator(&users, &chatHistory);
// }

/**
 * @brief Get reference to the users vector
 * 
 * Provides protected access to the users vector for derived classes.
 * Returns a reference to allow direct modification of the user list
 * by concrete mediator implementations.
 * 
 * @return Reference to the users vector containing all registered users
 * 
 * @note Returns reference to allow efficient manipulation by derived classes
 * @note Used by registerUser() and removeUser() implementations
 * @note Part of the Mediator pattern colleague management system
 */
vector<Users *> &ChatRoom::getUsers()
{
    // returns reference to users vector to allow modification of users in derived classes
    return users;
}

/**
 * @brief Get reference to the chat history vector
 * 
 * Provides protected access to the chat history vector for derived classes.
 * Returns a reference to allow direct modification of the message history
 * by concrete mediator implementations.
 * 
 * @return Reference to the chatHistory vector containing all saved messages
 * 
 * @note Returns reference to allow efficient manipulation by derived classes
 * @note Used by saveMessage() implementations in concrete mediators
 * @note Part of the message persistence system in the Template Method pattern
 */
vector<string> &ChatRoom::getChatHistory()
{
    // returns reference to chatHistory vector to allow modification of chat history in derived classes
    return chatHistory;
}

// void ChatRoom::setMessageProcessingStrategy(MessageProcessingStrategy* strategy)
// {
//     messageStrategy = strategy;
// }

// MessageProcessingStrategy* ChatRoom::getMessageProcessingStrategy()
// {
//     return messageStrategy;
// }

/**
 * @brief Template Method for message processing workflow
 * 
 * Implements the Template Method design pattern by defining the skeleton
 * of the message processing algorithm. This method orchestrates the entire
 * message handling workflow with 8 well-defined steps, allowing derived
 * classes to customize specific steps while maintaining the overall structure.
 * 
 * @param message The message content to process and send
 * @param fromUser Pointer to the user sending the message
 * 
 * @details Template Method Algorithm (8 Steps):
 * 1. **validateMessage()** - Content and sender validation (hook method)
 * 2. **checkPermissions()** - User authorization verification (hook method)
 * 3. **preprocessMessage()** - Message formatting and preprocessing (concrete method)
 * 4. **broadcastMessage()** - Message distribution to users (concrete method)
 * 5. **saveMessage()** - Message persistence to history (hook method)
 * 6. **logActivity()** - Activity logging for audit trail (hook method)
 * 7. **postProcessActions()** - Room-specific post-processing (hook method)
 * 8. **incrementMessageCount()** - User statistics update (concrete method)
 * 
 * @note This is the core of the Template Method pattern implementation
 * @note Hook methods are implemented by concrete mediator subclasses
 * @note Concrete methods provide default behavior that can be used by all subclasses
 * @note Early termination occurs if validation or permission checks fail
 * 
 * @see CtrlCat::validateMessage() for cat-themed validation
 * @see Dogorithm::validateMessage() for algorithm-focused validation
 * @see CtrlCat::postProcessActions() for community engagement features
 * @see Dogorithm::postProcessActions() for technical recognition system
 */
void ChatRoom::sendMessage(string message, Users *fromUser)
{
    
    // Step 1: Validate message content and sender
    if (!validateMessage(message, fromUser)) {
        cout << "❌ Message validation failed for " << fromUser->getName() << endl;
        return;
    }
    
    // Step 2: Check user permissions
    if (!checkPermissions(fromUser)) {
        cout << "🚫 " << fromUser->getName() << " doesn't have permission to send messages" << endl;
        return;
    }
    
    // Step 3: Pre-process message (using Strategy pattern)
    string processedMessage = preprocessMessage(message, fromUser);
    
    // Step 4: Broadcast message to all users
    broadcastMessage(processedMessage, fromUser);
    
    // Step 5: Save message to history
    saveMessage(fromUser->getName() + ": " + message, fromUser);
    
    // Step 6: Log activity for audit trail
    logActivity(message, fromUser);
    
    // Step 7: Perform post-processing actions
    postProcessActions(message, fromUser);
    
    // Step 8: Update user statistics
    fromUser->incrementMessageCount();
}

/**
 * @brief Preprocess message with standard formatting
 * 
 * Concrete method in the Template Method pattern that provides default
 * message preprocessing. Formats messages with room name and user attribution
 * for consistent display across all chat rooms.
 * 
 * @param message The original message content to preprocess
 * @param fromUser Pointer to the user sending the message
 * @return Formatted message string with room and user context
 * 
 * @details Default Formatting:
 * - Format: "[RoomName] Username: Message"
 * - Uses getRoomName() to get room-specific identifier
 * - Provides consistent message attribution across all rooms
 * - Prepared for Strategy pattern integration (currently commented)
 * 
 * @note This is a concrete method that provides default behavior
 * @note Strategy pattern integration is prepared but currently disabled
 * @note Called as Step 3 in the Template Method workflow
 */
string ChatRoom::preprocessMessage(string message, Users *fromUser)
{
    // if (messageStrategy != nullptr) {
    //     return messageStrategy->processMessage(message, fromUser, getRoomName());
    // }
    return "[" + getRoomName() + "] " + fromUser->getName() + ": " + message;
}

/**
 * @brief Broadcast message to all users in the chat room
 * 
 * Concrete method in the Template Method pattern that handles message
 * distribution. Currently outputs messages to console for demonstration,
 * but can be extended to support real network broadcasting.
 * 
 * @param processedMessage The formatted message ready for broadcast
 * @param fromUser Pointer to the user who sent the message
 * 
 * @details Broadcasting Features:
 * - Console output for demonstration purposes
 * - Receives pre-formatted message from preprocessMessage()
 * - Can be extended for network communication
 * - Consistent across all chat room types
 * 
 * @note This is a concrete method providing default broadcast behavior
 * @note Called as Step 4 in the Template Method workflow
 * @note Ready for extension to support real network broadcasting
 */
void ChatRoom::broadcastMessage(string processedMessage, Users *fromUser)
{
    cout << processedMessage << endl;
}

/**
 * @brief Default implementation for message persistence
 * 
 * Provides default message saving behavior for the Template Method pattern.
 * This method can be overridden by derived classes to implement custom
 * persistence strategies while maintaining the overall workflow structure.
 * 
 * @param message The message content to save to history
 * @param fromUser Pointer to the user who sent the message
 * 
 * @details Default Persistence:
 * - Simple vector-based storage in chatHistory
 * - In-memory persistence for demonstration
 * - Can be overridden for database or file storage
 * - Maintains message order and integrity
 * 
 * @note This is a virtual method that can be overridden by derived classes
 * @note Called as Step 5 in the Template Method workflow
 * @note Provides basic functionality that works for all room types
 * @see CtrlCat::saveMessage() for cat-themed persistence messaging
 * @see Dogorithm::saveMessage() for technical message archival
 */
void ChatRoom::saveMessage(string message, Users *fromUser)
{
    chatHistory.push_back(message);
}
