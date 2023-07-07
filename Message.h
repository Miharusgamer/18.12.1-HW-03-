#pragma once

#include <string>

constexpr auto messageFile = "/home/miha/tmp/data/message.data";

class Message final {
public:
	Message();
	~Message();

	void setText(const std::string& text);
	void setSender(const std::string& sender);
	void setReceiver(const std::string& receiver);

	const std::string& getText() const;
	const std::string& getSender() const;
	const std::string& getReceiver() const;

private:
	std::string _text;
	std::string _sender;
	std::string _receiver;

	void readMessage();
	void writeMessage() const;
};
