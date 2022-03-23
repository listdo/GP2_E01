#pragma once

#include "Counter.h"


template<typename BaseCounter>
class VarIncrementCounter : public BaseCounter {
private:
	typedef typename BaseCounter::Config::ValueType ValueType;

public:
	void increment() override {
		ValueType current = BaseCounter::value_;
		BaseCounter::value_ = current + BaseCounter::Config::StepSize::value;
	}
};

template<typename BaseCounter>
class VarIncrementBoundedCounter : public BaseCounter {
private:
	typedef typename BaseCounter::Config::ValueType ValueType;

public:
	void increment() override {
		ValueType current = BaseCounter::value_;

		if (BaseCounter::value_ < BaseCounter::Config::Bound::value)
			BaseCounter::value_ = current + BaseCounter::Config::StepSize::value;
	}
};