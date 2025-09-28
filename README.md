# 🐾 PetSpace - Advanced Chat System Implementation

## 214 Practical 3 - 2 Amigos

A comprehensive chat system demonstrating multiple design patterns with advanced features including role-based permissions, multi-room user support, and rich user engagement systems.

## 🎯 System Overview

PetSpace is a themed chat system with two distinct chat rooms:

- **CtrlCat**: Cat-themed, friendly community focused on helpful discussions
- **Dogorithm**: Dog-themed, technical community focused on algorithm and programming discussions

### Key Features

- ✅ **Multi-room users**: Users can be registered in multiple chat rooms simultaneously
- ✅ **Role-based permissions**: 4-level permission system (Guest → Member → Moderator → Admin)
- ✅ **Advanced user engagement**: Reward systems, badges, and community features
- ✅ **Content validation**: Room-specific message validation and filtering
- ✅ **Anti-spam protection**: Message count tracking and rate limiting
- ✅ **Mute functionality**: Temporary user restrictions

## 🏗️ Design Patterns Implementation

### 1. Mediator Pattern

**Purpose**: Centralise complex communications and control logic between related objects

**Components:**

- **Mediator Interface**: `ChatRoom` (abstract base class)
- **Concrete Mediators**: `CtrlCat`, `Dogorithm`
- **Colleague Interface**: `Users` (abstract base class)
- **Concrete Colleagues**: `Nathan`, `Dominiqu`, `Luyanda`
- **Communication Flow**: All user-to-user communication goes through ChatRoom mediators

**Send/Receive Functions Decision:**

- Implemented in the `Users` base class rather than derived classes
- **Rationale**: Identical implementation across all user types avoids code duplication
- **Extensibility**: System design is complete at user level - no need for further specialisation beyond individual persons as that would not make sense. Each user sends and receives a message the same way.

### 2. Template Method Pattern

**Purpose**: Define skeleton of message handling algorithm while allowing room-specific customisations

**Implementation**: 8-step message handling workflow in `ChatRoom::sendMessage()`

**Workflow Steps:**

1. **Message validation** (room-specific rules)
2. **Permission checking** (role-based access control)
3. **Message preprocessing** (default formatting, extensible)
4. **Broadcasting** (common implementation)
5. **Save to history** (default implementation, overridable)
6. **Activity logging** (room-specific formats)
7. **Post-processing actions** (room-specific engagement features)
8. **Update statistics** (common implementation)

### 3. Command Pattern

**Purpose**: Encapsulate message operations as objects for queuing, logging, and potential undo functionality

**Components:**

- **Command Interface**: `Command` (abstract base class with `execute()` method)
- **Concrete Commands**:
  - `SendMessageCommand`: Handles message sending operations
  - `SaveMessageCommand`: Handles message persistence operations
- **Invoker**: `Users` class (manages command queue and execution)
- **Receiver**: `ChatRoom` (processes the actual operations)

**Benefits:**

- Operation encapsulation as objects
- Command queuing and batching support
- Undo potential (extensible)
- Macro command capabilities

## 🔐 Advanced Permission System

### Permission Levels

1. **Guest (Level 1)**: Limited access, cannot post in most rooms
2. **Member (Level 2)**: Standard access, can post in CtrlCat, message limits apply
3. **Moderator (Level 3)**: Enhanced access, can post in Dogorithm, higher limits
4. **Admin (Level 4)**: Full access, unlimited posting, all features available

### Room-Specific Requirements

- **CtrlCat**: Requires Member level (2+), focuses on positive community
- **Dogorithm**: Requires Moderator level (3+), focuses on technical credibility

### Security Features

- **Spam Protection**: Message count tracking with daily limits
- **Mute System**: Temporary restrictions for policy violations
- **Content Filtering**: Automatic detection and blocking of inappropriate content
- **Role-based Validation**: Different access levels per room type

## 🎨 User Engagement System

### CtrlCat Room Features

- 🏆 **Bug Hunter Rewards**: Points for debugging discussions
- 🎯 **CtrlCat Coin System**: Virtual currency for engagement
- ❤️ **Community Helper Bonuses**: Recognition for helpful behavior
- ✨ **Code Quality Champions**: Recognition for clean code advocacy
- 📚 **Learning Resource Recommendations**: Automatic resource suggestions
- 😻 **Cat Pun Engagement**: Fun community interaction rewards

### Dogorithm Room Features

- 🧠 **Complexity Analysis Detection**: Auto-tagging for algorithm discussions
- 🔄 **Control Structure Recognition**: Smart discussion categorisation
- ⚡ **Performance Optimisation Badges**: Recognition for efficiency discussions
- 📊 **Technical Discussion Logging**: Specialised logging for algorithm content

## 🚀 Multi-Room User Support

Nathan is registered in both CtrlCat and Dogorithm rooms, demonstrating:

- Single user can participate in multiple communities
- Different behavior and engagement per room
- Consistent identity across different contexts
- Room-specific permission validation

## 📊 System Architecture Benefits

### Separation of Concerns

- Each pattern handles specific responsibilities
- Clean interfaces between components
- Independent modification capabilities

### Extensibility

- Easy addition of new chat rooms with different themes
- Simple integration of new user types
- Straightforward implementation of new commands
- Expandable permission system

### Maintainability

- Consistent code structure across rooms
- Template Method ensures uniform message handling
- Command pattern enables operation traceability
- Clear business logic separation

### Testability

- Independent testing of pattern components
- Command pattern enables operation testing
- Permission system has clear, testable rules
- Template Method steps are individually verifiable

## 🔧 Usage Instructions

### Compilation

```bash
make clean
make Main
```

### Execution

```bash
./Main
```

### Memory Testing

```bash
make mem
```

## 📈 Demonstration Results

The system successfully demonstrates:

- ✅ **Mediator Pattern**: All communication mediated through chat rooms
- ✅ **Template Method Pattern**: Consistent 8-step message handling workflow
- ✅ **Command Pattern**: Encapsulated operations with queuing support
- ✅ **Multi-room Users**: Nathan participates in both CtrlCat and Dogorithm
- ✅ **Permission System**: Role-based access control across all operations
- ✅ **User Engagement**: Rich interaction features and community building tools
