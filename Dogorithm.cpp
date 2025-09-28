#include "Dogorithm.h"
#include "Users.h"
// #include "DogThemeStrategy.h"

/**
 * @file Dogorithm.cpp
 * @brief Implementation of Dogorithm concrete mediator
 * @author 2Amigos
 * @date 2025-09-28
 */

Dogorithm::Dogorithm() 
{
    // Set the dog-themed algorithmic message processing strategy
    // setMessageProcessingStrategy(new DogThemeStrategy());
}

void Dogorithm::registerUser(Users *user)
{
    // register a user to the chat room
    getUsers().push_back(user);
}

string Dogorithm::getRoomName()
{
    return "Dogorithm";
}

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

void Dogorithm::logActivity(string originalMessage, Users *fromUser)
{
    // Algorithm-focused activity logging
    cout << "📊 🐕 [LOG] Technical discussion by " << fromUser->getName() << " in Dogorithm" << endl;
}

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

void Dogorithm::saveMessage(string message, Users *fromUser)
{
    // add message to chat history
    getChatHistory().push_back(message);
}

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
