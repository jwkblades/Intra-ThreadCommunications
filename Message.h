#ifndef __MESSAGE_H
#define __MESSAGE_H

#include <cstdlib>

class Message
{
public:
	Message(void);
	Message(const void* rawBuffer, std::size_t bufferSize);
	Message(const Message& src);
	~Message(void);

	std::size_t size(void) const;
	template<typename T> T get(void) const;
private:
	char* mBuffer;
	std::size_t mSize;
};

#include "Message.ipp"

#endif
