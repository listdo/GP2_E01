#pragma once

template<typename Config_>
class Counter {
private:
	typedef typename Config_::ValueType ValueType;
protected:
	ValueType value_;
public:
	typedef Config_ Config;

	Counter() {
		value_ = Config::Init::value;
	}

	const ValueType value() const {
		return value_;
	}

	virtual void increment() {
		++value_;
	}

	void reset() {
		value_ = Config::Init::value;
	}
};