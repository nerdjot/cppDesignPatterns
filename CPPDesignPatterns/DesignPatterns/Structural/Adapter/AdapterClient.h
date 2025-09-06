#include "FixMsgAdapter.h"

void clientCode()
{
	ModernFixAdapter modernFixAdapter(std::make_unique<LegacyFixMsg>());

	std::cout << modernFixAdapter.to_string() << std::endl;

	modernFixAdapter.set_pair(100, false);
	modernFixAdapter.set_pair(101, 154);
	modernFixAdapter.set_pair(102, "abcd");

	std::cout << modernFixAdapter.to_string() << std::endl;




}