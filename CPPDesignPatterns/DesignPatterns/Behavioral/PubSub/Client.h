#include "Publisher.h"

void pubsubClientCode()
{
	std::cout << "Pubsub client code running" << std::endl;
	Publisher publisher;
	auto marketWatchPricerSubsriber = std::make_shared<MarketWatchPriceSubscriber>();
	publisher.addSubscriber(marketWatchPricerSubsriber);
	publisher.publishToSubscribers(102);
	publisher.publishToSubscribers(97);

	{
		auto priceThresholdSubscriber = std::make_shared<PriceThresholdSubscriber>(100, "Karan");
		publisher.addSubscriber(priceThresholdSubscriber);
		publisher.publishToSubscribers(130);
		publisher.publishToSubscribers(101);
	}
	publisher.publishToSubscribers(155);

	auto priceThresholdSubscriber2 = std::make_shared<PriceThresholdSubscriber>(90, "Navjot");
	publisher.addSubscriber(priceThresholdSubscriber2);

	publisher.publishToSubscribers(101);
	publisher.publishToSubscribers(89);

	publisher.removeSubscriber(marketWatchPricerSubsriber);


	publisher.publishToSubscribers(101);
	publisher.publishToSubscribers(89);
	


}

