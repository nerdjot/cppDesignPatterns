#include <iostream>
class Subscriber
{
	friend class Publisher;
/*protected:*/
	virtual void update(int price)
	{
		std::cout << "Empty update" << std::endl;
	}
};

class MarketWatchPriceSubscriber : public Subscriber
{
	void update(int price) override
	{
		std::cout << "**MarketWatch** Latest price of vod.l is: $" << price << std::endl;
	}
};

class PriceThresholdSubscriber : public Subscriber
{
	int _threshold;
	std::string _name;
	void update(int price) override
	{
		if (price > 100)
		{
			std::cout << "**PriceThreshold "<<_name<<"** Price is GREATER EQUAL than "<<_threshold<<"!Price: " << price << std::endl;
		}
		else
		{
			std::cout << "**PriceThreshold " << _name << "** Price is LESS than " << _threshold << "! Price: " << price << std::endl;
		}
	}
public:
	PriceThresholdSubscriber(int threshold, std::string name)
	{
		_threshold = threshold;
		_name = name;
	}
};