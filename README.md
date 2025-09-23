# 214_Practical3_2Amigos

Mediator Design Pattern

Users register with a chat room and can also deregister from the chatroom

Users send a message to a certain chat room and not directly to other users. The chat room is the mediator that handles which chat room each message has to go to. Messages can be saved to a chat history and accessed later.

Send, Receive function:
Only included in the Users class (Colleague) and not in its derived classes, Nathan, Dominiqu, Luyanda (ConcreteColleague) because the implentation of send() and receive() would be the same in all derived classes so we just implemented those functions in the parent class instead so not repeat code.
