#include "Message.h"

#include <filesystem>
#include <fstream>

Message::Message() {
	readMessage();
}

Message::~Message() {
	writeMessage();
}

void Message::setText(const std::string& text){
	_text = text;
}


void Message::setSender(const std::string& sender){
	_sender = sender;
}

void Message::setReceiver(const std::string& receiver){
	_receiver = receiver;
}

const std::string& Message::getText() const{
	return _text;
}

const std::string& Message::getSender() const{
	return _sender;
}

const std::string& Message::getReceiver() const{
	return _receiver;
}

void Message::readMessage() {
	std::fstream file(messageFile, std::ios::in);

	auto permissions =std::filesystem::perms::group_all | 
		std::filesystem::perms::others_all;
	std::filesystem::permissions(messageFile, permissions, std::filesystem::perm_options::remove);

	const std::string delimiter = ":";
	if (file.is_open()) {
		std::string line;
		std::string name;
		std::string value;

		while (std::getline(file, line)) {
	   		size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition + 1);

				if (name == "Text") {
					_text = value;
				}
				else if (name == "Sender") {
					_sender = value;
				}
				else if (name == "Receiver") {
					_receiver = value;
				}
			}
	   	}
	}
	file.close();
}

void Message::writeMessage() const {
	std::fstream file(messageFile, std::ios::out);
	file << "Text:" << _text << "\n";
	file << "Sender:" << _sender << "\n";
	file << "Receiver:" << _receiver << "\n";
	file.close();
}
