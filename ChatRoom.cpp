#include "ChatRoom.h"
#include "Users.h"

/**
 * @file ChatRoom.cpp
 * @brief Implementation of ChatRoom base class
 * @author 2Amigos
 * @date 2025-09-28
 */

ChatRoom::ChatRoom(){}

// ChatRoom::ChatRoom(MessageProcessingStrategy* strategy) : messageStrategy(strategy) {}

ChatRoom::~ChatRoom(){}

// ChatRoomIterator* ChatRoom::createIterator()
// {
//     return new ChatRoomIterator(&users, &chatHistory);
// }

vector<Users *> &ChatRoom::getUsers()
{
    // returns reference to users vector to allow modification of users in derived classes
    return users;
}

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

string ChatRoom::preprocessMessage(string message, Users *fromUser)
{
    // if (messageStrategy != nullptr) {
    //     return messageStrategy->processMessage(message, fromUser, getRoomName());
    // }
    return "[" + getRoomName() + "] " + fromUser->getName() + ": " + message;
}

void ChatRoom::broadcastMessage(string processedMessage, Users *fromUser)
{
    cout << processedMessage << endl;
}

void ChatRoom::saveMessage(string message, Users *fromUser)
{
    chatHistory.push_back(message);
}
