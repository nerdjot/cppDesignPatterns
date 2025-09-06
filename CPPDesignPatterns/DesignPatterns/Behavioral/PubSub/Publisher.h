#include "Subscriber.h"
#include <memory>
#include <vector>

class Publisher
{
private:
	std::vector<std::weak_ptr<Subscriber>> subscribers;
public:
	void addSubscriber(std::shared_ptr<Subscriber> subscriber)
	{
		std::cout << "adding subscriber" << std::endl;
		subscribers.push_back(subscriber);
	}
	void removeSubscriber(std::shared_ptr<Subscriber> subscriber)
	{
		std::cout << "removing subscriber" << std::endl;
		auto it = subscribers.begin();
		while (it != subscribers.end())
		{
			auto locked_it = it->lock();//converting to shared_ptr, this is compulsory //so that it is guaranteed that the object is actually alive
			if (!locked_it || locked_it == subscriber)
			{
				it = subscribers.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	void publishToSubscribers(int price)
	{

		auto it = subscribers.begin();
		while (it != subscribers.end())
		{
			auto subscriber = it->lock();
			if (!subscriber) //subscriber is dead
			{
				it = subscribers.erase(it);
			}
			else
			{
				subscriber->update(price);
				it++;
			}
		}
	}
};