#include <map>
#include <string>
#include <variant>
#include <memory>


class LegacyFixMsg
{
protected:
	std::map<int, std::string> fixMap;
public:
	LegacyFixMsg()
	{
		fixMap[35] = "0";
		fixMap[56] = "true";
		fixMap[38] = "100";
		fixMap[44] = "79";
		fixMap[55] = "vod.l";
	}
	std::string toString()
	{
		std::string res;
		for (auto& pair : fixMap)
		{
			res += std::to_string(pair.first) + "=" + pair.second + "; ";
		}
		return res;
	}
	void setPair(int tag, const std::string& value)
	{
		fixMap[tag] = value;
	}
	void getPair(int tag, std::string& value)
	{
		value = fixMap[tag];
	}
};


class ModerFixMsgInterface
{
	virtual std::string to_string() = 0;
	virtual void set_pair(int tag, const std::string&) = 0;
	virtual void set_pair(int tag, int) = 0;
	virtual void set_pair(int tag, bool) = 0;
	virtual std::variant<int, bool, std::string> get_value(int tag) = 0;
};

class ModernFixAdapter : public ModerFixMsgInterface
{
private:
	std::unique_ptr<LegacyFixMsg> _legacyFixMsg;

	bool isInteger(const std::string& s) {
		if (s.empty()) return false;
		try {
			size_t pos;
			std::stoi(s, &pos);
			return pos == s.size();  // make sure all characters were digits
		}
		catch (...) {
			return false;            // failed conversion
		}
	}

public:
	ModernFixAdapter(std::unique_ptr<LegacyFixMsg> legacyFixMsg)
	{
		_legacyFixMsg = std::move(legacyFixMsg);
	}
	std::string to_string() override
	{
		return _legacyFixMsg->toString();
	};

	void set_pair(int tag, const std::string& value) override
	{
		_legacyFixMsg->setPair(tag, value);
	}

	void set_pair(int tag, const char* value)
	{
		_legacyFixMsg->setPair(tag, value);
	}

	void set_pair(int tag, int value) override
	{
		_legacyFixMsg->setPair(tag, std::to_string(value));
	}

	void set_pair(int tag, bool value) override
	{
		_legacyFixMsg->setPair(tag, value?"true":"false");
	}

	std::variant<int, bool, std::string> get_value(int tag) override
	{
		std::string value;
		_legacyFixMsg->getPair(tag, value);
		if (isInteger(value))
		{
			return std::stoi(value);
		}
		else if (value == "false")
			return false;
		else if (value == "true")
			return true;
		return value;
	}
};




