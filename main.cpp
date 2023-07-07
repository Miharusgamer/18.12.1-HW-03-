#include "User.h"
#include "Message.h"

#include <iostream>
#include <string>

int main() {
	User user;
	Message message;

	std::cout << "User info\n";
	std::cout << "Name: " << user.getName() << "\n";
	std::cout << "Login: " << user.getLogin() << "\n";
	std::cout << "Pass: " << user.getPass() << "\n";

        std::cout << "Message info\n";
        std::cout << "Text: " << message.getText() << "\n";
        std::cout << "Sender: " << message.getSender() << "\n";
        std::cout << "Receiver: " << message.getReceiver() << "\n";

	const std::string newName = "Miha";
	user.setName(newName);
	const std::string newLogin = "MihaPRO";
        user.setLogin(newLogin);
	const std::string newPass = "qwerty";
        user.setPass(newPass);

        const std::string newText = "Hello";
        message.setText(newText);
        const std::string newSender = "Boris";
        message.setSender(newSender);
        const std::string newReceiver = "Miha";
        message.setReceiver(newReceiver);

	std::cout << "Current user info\n";
	std::cout << "Name: " << user.getName() << "\n";
        std::cout << "Login: " << user.getLogin() << "\n";
        std::cout << "Pass: " << user.getPass() << "\n";

        std::cout << "Current message info\n";
	std::cout << "Text: " << message.getText() << "\n";
        std::cout << "Sender: " << message.getSender() << "\n";
        std::cout << "Receiver: " << message.getReceiver() << "\n";
}
