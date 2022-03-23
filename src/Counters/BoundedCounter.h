#pragma once

#include "Counter.h"

template<typename BaseCounter>
class BoundedCounter : public BaseCounter {
private:
	typedef typename BaseCounter::Config::ValueType ValueType;
public:
	void increment() override {
		ValueType current = BaseCounter::value_;
		BaseCounter::increment();
		if (BaseCounter::value_ > BaseCounter::Config::Bound::value)
			BaseCounter::value_ = current;
	}
};
