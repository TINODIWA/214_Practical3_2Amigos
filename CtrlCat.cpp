#include "CtrlCat.h"
#include "Users.h"
// #include "CatThemeStrategy.h"

/**
 * @file CtrlCat.cpp
 * @brief Implementation of CtrlCat concrete mediator
 * @author 2Amigos
 * @date 2025-09-28
 */

CtrlCat::CtrlCat() 
{
    // Set the cat-themed message processing strategy
    // setMessageProcessingStrategy(new CatThemeStrategy());
}

void CtrlCat::registerUser(Users *user)
{
    // register a user to the chat room
    getUsers().push_back(user);
}

string CtrlCat::getRoomName()
{
    return "CtrlCat";
}

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

void CtrlCat::logActivity(string originalMessage, Users *fromUser)
{
    // Cat-themed activity logging
    cout << "📝 😸 [LOG] " << fromUser->getName() << " shared something in CtrlCat" << endl;
}

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

void CtrlCat::saveMessage(string message, Users *fromUser)
{
    // add message to chat history
    getChatHistory().push_back(message);
}

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
