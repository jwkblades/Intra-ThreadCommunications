#include "PostOffice.h"

#include <iostream>
#include <thread>
#include <sstream>

#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
	list<thread> threads;
	std::srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(
			thread([i](void) -> void {
				stringstream nameStream("");
				nameStream << "thread_" << i;
				Address myself(nameStream.str());
				PostOffice* postOffice = PostOffice::instance();
				if (!postOffice->registerAddress(myself))
				{
					cout << "Unable to register address " << myself << endl;
					return;
				}
	
				int myReceivedMessages = 0;
				do
				{
					if (!PostOffice::isValidInstance(postOffice))
					{
						RAIIMutex OutputLock(&cout);
						cout << "Invalid post office instance... returning. (" << myself << ")" << endl;
					}
					if (postOffice->checkMail(myself))
					{
						Message msg = postOffice->getMail(myself);
						RAIIMutex OutputLock(&cout);
						cout << myself << " received message: '" << msg.get<const char*>() << "'." << endl;
						myReceivedMessages++;
					}

					stringstream otherStream("");
					otherStream << "thread_" << (std::rand() % 10);
					Address other(otherStream.str());
					if (postOffice->isValidAddress(other))
					{
						stringstream messageRaw("");
						messageRaw << "I, " << myself << ", have currently received " << myReceivedMessages << " messages.";
						string msgStr = messageRaw.str();

						{
							RAIIMutex OutputLock(&cout);
							cout << "About to send message: " << msgStr << " from " << myself << endl;
						}
						const char* str = msgStr.c_str();
						Message toSend(str, msgStr.size() + 1);
						postOffice->sendMesssage(other, toSend);
					}

				} while (myReceivedMessages < 10);
			})
		);
	}

	for (thread& t : threads)
	{
		t.join();
	}

	return 0;
}
