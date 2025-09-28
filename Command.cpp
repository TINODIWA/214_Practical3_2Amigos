#include "Command.h"

/**
 * @file Command.cpp
 * @brief Implementation of Command base class
 * @author 2Amigos
 * @date 2025-09-28
 */

Command::Command(ChatRoom* room, Users* user, string msg) : room(room), fromUser(user), message(msg){}