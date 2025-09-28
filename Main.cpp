#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Users.h"
#include "ChatRoom.h"
#include "Nathan.h"
#include "Dominiqu.h"
#include "Luyanda.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "SaveMessageCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void demonstratePermissionSystem();
void demonstrateTemplateMethodPattern();
void demonstrateCommandPattern();
void demonstrateMediatorPattern();

int main()
{
    cout << "🐾 Welcome to PetSpace - Advanced Chat System! 🐾" << endl;
    cout << "===================================================" << endl;
    cout << "Demonstrating Mediator, Template Method, and Command Patterns" << endl;
    cout << "with Advanced Permission System and Enhanced Features" << endl;
    cout << "===================================================" << endl;

    demonstrateMediatorPattern();
    demonstrateTemplateMethodPattern();
    demonstrateCommandPattern();
    demonstratePermissionSystem();

    cout << "\n🎉 All Design Patterns Successfully Demonstrated! 🎉" << endl;
    cout << "====================================================" << endl;
    cout << "• Mediator: Chat rooms mediate all communication between users" << endl;
    cout << "• Template Method: Consistent 8-step message handling workflow" << endl;
    cout << "• Command: Encapsulated message operations with queuing" << endl;
    cout << "• Advanced Permissions: Role-based access control system" << endl;
    cout << "• Enhanced PostProcessing: Rich user engagement features" << endl;

    return 0;
}

void demonstrateMediatorPattern()
{
    cout << "\n🏠 1. MEDIATOR PATTERN DEMONSTRATION" << endl;
    cout << "====================================" << endl;
    
    // Create chat rooms (Concrete Mediators)
    CtrlCat ctrlCat;
    Dogorithm dogorithm;
    
    // Create users (Concrete Colleagues)  
    Nathan nate(&ctrlCat);
    Dominiqu dom(&dogorithm);
    Luyanda luy(&dogorithm);
    
    // Register users with their respective chat rooms
    ctrlCat.registerUser(&nate);
    dogorithm.registerUser(&dom);
    dogorithm.registerUser(&luy);
    
    // ⭐ REQUIREMENT: Register Nathan in BOTH chat rooms
    dogorithm.registerUser(&nate);  // Nathan is now in both CtrlCat AND Dogorithm
    
    cout << "✅ Chat rooms created: CtrlCat (cat-themed), Dogorithm (algorithm-focused)" << endl;
    cout << "✅ Users registered:" << endl;
    cout << "   • Nathan → CtrlCat AND Dogorithm (multi-room user) ⭐" << endl;
    cout << "   • Dominiqu → Dogorithm only" << endl;
    cout << "   • Luyanda → Dogorithm only" << endl;
    cout << "✅ All communication goes through ChatRoom mediators!" << endl;
    
    // Demonstrate mediated communication
    cout << "\n📢 Mediated Communication:" << endl;
    
    cout << "\n--- Nathan posting in CtrlCat ---" << endl;
    nate.send("Hello everyone! I need help with debugging some code", &ctrlCat);
    
    cout << "\n--- Nathan posting in Dogorithm (same user, different room) ---" << endl;
    nate.setPermissionLevel(3); // Promote Nathan to Moderator for Dogorithm access
    nate.send("I also want to discuss algorithm optimization techniques here", &dogorithm);
    
    cout << "\n--- Other users in Dogorithm ---" << endl;
    dom.setPermissionLevel(3); // Promote to Moderator
    dom.send("Let's discuss the optimal search algorithm for this problem", &dogorithm);
    luy.setPermissionLevel(3); // Promote to Moderator
    luy.send("I found an efficient binary tree implementation!", &dogorithm);
}

void demonstrateTemplateMethodPattern()
{
    cout << "\n🔄 2. TEMPLATE METHOD PATTERN DEMONSTRATION" << endl;
    cout << "============================================" << endl;
    
    CtrlCat ctrlCat;
    Dogorithm dogorithm;
    Nathan nate(&ctrlCat);
    Dominiqu dom(&dogorithm);
    
    ctrlCat.registerUser(&nate);
    dogorithm.registerUser(&dom);
    dogorithm.registerUser(&nate); // Nathan in both rooms for this demo too
    
    cout << "🏗️ Template Method defines 8-step message handling workflow:" << endl;
    cout << "1. Validate message content and sender" << endl;
    cout << "2. Check user permissions" << endl;
    cout << "3. Pre-process message (Strategy pattern integration)" << endl;
    cout << "4. Broadcast message to all users" << endl;
    cout << "5. Save message to history" << endl;
    cout << "6. Log activity for audit trail" << endl;
    cout << "7. Perform post-processing actions" << endl;
    cout << "8. Update user statistics" << endl;
    
    cout << "\n🎯 Each room customizes validation, logging, and post-actions:" << endl;
    
    cout << "\n--- CtrlCat Room (Positive, Welcoming) ---" << endl;
    nate.send("I found a bug in my code! Can someone help debug this function?", &ctrlCat);
    
    cout << "\n--- Dogorithm Room (Technical, Algorithm-focused) ---" << endl;
    dom.setPermissionLevel(3); // Promote to Moderator for Dogorithm access
    dom.send("This recursive search algorithm has O(log n) complexity for binary trees", &dogorithm);
    
    cout << "\n--- Nathan posting in Dogorithm (same user, different room behavior) ---" << endl;
    nate.setPermissionLevel(3); // Promote Nathan to Moderator
    nate.send("I want to contribute to algorithm discussions too!", &dogorithm);
    
    cout << "\n🔍 Testing Template Method Validation:" << endl;
    cout << "--- Testing CtrlCat validation (should reject negative content) ---" << endl;
    nate.send("This code is stupid and dumb!", &ctrlCat);
    
    cout << "\n--- Testing Dogorithm validation (should accept technical content) ---" << endl;
    dom.send("Let's optimize this sorting algorithm for better performance", &dogorithm);
}

void demonstrateCommandPattern()
{
    cout << "\n⚡ 3. COMMAND PATTERN DEMONSTRATION" << endl;
    cout << "===================================" << endl;
    
    CtrlCat ctrlCat;
    Nathan nate(&ctrlCat);
    ctrlCat.registerUser(&nate);
    
    cout << "🏗️ Command Pattern Components:" << endl;
    cout << "• Command Interface: Abstract Command with execute()" << endl;
    cout << "• Concrete Commands: SendMessageCommand, SaveMessageCommand" << endl;
    cout << "• Invoker: Users class (manages command queue)" << endl;
    cout << "• Receiver: ChatRoom (processes operations)" << endl;
    
    cout << "\n📝 Creating individual commands manually:" << endl;
    
    // Demonstrate explicit command creation and execution
    SendMessageCommand* sendCmd = new SendMessageCommand(&ctrlCat, &nate, "This message uses explicit Command pattern!");
    SaveMessageCommand* saveCmd = new SaveMessageCommand(&ctrlCat, &nate, "This is a saved command message!");
    
    cout << "✅ SendMessageCommand created" << endl;
    cout << "✅ SaveMessageCommand created" << endl;
    
    cout << "\n🔄 Adding commands to user's queue:" << endl;
    nate.addCommand(sendCmd);
    nate.addCommand(saveCmd);
    
    cout << "✅ Commands added to Nathan's command queue" << endl;
    
    cout << "\n⚡ Executing all queued commands:" << endl;
    nate.executeAll();
    
    cout << "\n📊 Commands demonstrate:" << endl;
    cout << "• Encapsulation: Operations wrapped as objects" << endl;
    cout << "• Queuing: Commands can be stored and executed later" << endl;
    cout << "• Undo potential: Commands can be reversed (if implemented)" << endl;
    cout << "• Macro commands: Multiple commands can be batched" << endl;
}

void demonstratePermissionSystem()
{
    cout << "\n🔐 4. ADVANCED PERMISSION SYSTEM DEMONSTRATION" << endl;
    cout << "===============================================" << endl;
    
    CtrlCat ctrlCat;
    Dogorithm dogorithm;
    Nathan nate(&ctrlCat);
    Dominiqu dom(&dogorithm);
    Luyanda luy(&dogorithm);
    
    ctrlCat.registerUser(&nate);
    dogorithm.registerUser(&dom);
    dogorithm.registerUser(&luy);
    dogorithm.registerUser(&nate); // ⭐ Nathan registered in BOTH rooms
    
    cout << "🏷️ Permission Levels:" << endl;
    cout << "1 = Guest (limited access)" << endl;
    cout << "2 = Member (standard access)" << endl;
    cout << "3 = Moderator (enhanced access)" << endl;
    cout << "4 = Admin (full access)" << endl;
    
    cout << "\n👤 Current user permissions:" << endl;
    cout << "Nathan: Level " << nate.getPermissionLevel() << " (Member)" << endl;
    cout << "Dominiqu: Level " << dom.getPermissionLevel() << " (Member)" << endl;
    cout << "Luyanda: Level " << luy.getPermissionLevel() << " (Member)" << endl;
    
    cout << "\n🔄 Testing permission scenarios:" << endl;
    
    cout << "\n--- Scenario 1: Guest trying to post in CtrlCat ---" << endl;
    nate.setPermissionLevel(1); // Set to Guest
    nate.send("I'm a guest trying to post", &ctrlCat);
    
    cout << "\n--- Scenario 2: Member posting in CtrlCat (should work) ---" << endl;
    nate.setPermissionLevel(2); // Set back to Member
    nate.send("Now I'm a member posting successfully!", &ctrlCat);
    
    cout << "\n--- Scenario 3: Member trying to post in Dogorithm (requires Moderator) ---" << endl;
    dom.setPermissionLevel(2); // Ensure Member level
    dom.send("I'm trying to discuss algorithms as a member", &dogorithm);
    
    cout << "\n--- Scenario 4: Moderator posting in Dogorithm (should work) ---" << endl;
    dom.setPermissionLevel(3); // Promote to Moderator
    dom.send("Now I'm a moderator discussing advanced algorithm optimization techniques", &dogorithm);
    
    cout << "\n--- Scenario 5: Testing mute functionality ---" << endl;
    luy.setMuted(true);
    luy.send("This message should be blocked because I'm muted", &dogorithm);
    
    cout << "\n--- Scenario 6: Admin with full access ---" << endl;
    luy.setMuted(false);
    luy.setPermissionLevel(4); // Promote to Admin
    luy.send("I'm an admin with unlimited access to all features", &dogorithm);
    
    cout << "\n--- Scenario 7: Multi-room user (Nathan in both CtrlCat and Dogorithm) ---" << endl;
    nate.setPermissionLevel(3); // Moderator level for Dogorithm
    cout << "Nathan posting in CtrlCat:" << endl;
    nate.send("Sharing tips in the friendly cat community!", &ctrlCat);
    cout << "Nathan posting in Dogorithm:" << endl;
    nate.send("Contributing to technical algorithm discussions!", &dogorithm);
    
    cout << "\n📊 Permission System Features Demonstrated:" << endl;
    cout << "• Role-based access control" << endl;
    cout << "• Different requirements per room" << endl;
    cout << "• Mute functionality" << endl;
    cout << "• Message count tracking and limits" << endl;
    cout << "• Spam protection mechanisms" << endl;
    cout << "• Dynamic permission level changes" << endl;
    
    cout << "\n📈 Final Statistics:" << endl;
    cout << "Nathan sent " << nate.getMessageCount() << " messages" << endl;
    cout << "Dominiqu sent " << dom.getMessageCount() << " messages" << endl;
    cout << "Luyanda sent " << luy.getMessageCount() << " messages" << endl;
    
    cout << "\n📚 Chat History Summary:" << endl;
    cout << "CtrlCat has " << ctrlCat.getChatHistory().size() << " messages" << endl;
    cout << "Dogorithm has " << dogorithm.getChatHistory().size() << " messages" << endl;
}