#pragma once

#include "Counter.h"
#include "VarIncrementCounter.h"
#include "BoundedCounter.h"

template<int n>
struct IntValue {
	static const int value = n;
};

struct DoubleValue_0_5 {
	static const double value;
};
const double DoubleValue_0_5::value(0.5);

template<typename ValueType_, typename Init_>
struct CounterConfig {	
	typedef ValueType_ ValueType;
	typedef Init_ Init;

	typedef Counter<CounterConfig> Counter;
};

template<typename ValueType_, typename Init_, typename Bound_>
struct BoundedCounterConfig {
	typedef ValueType_ ValueType;
	typedef Init_ Init;
	typedef Bound_ Bound;

	typedef BoundedCounter<Counter<BoundedCounterConfig>> Counter;
};

template<typename ValueType_, typename Init_, typename StepSize_>
struct VarIncrementCounterConfig {
	typedef ValueType_ ValueType;
	typedef Init_ Init;
	typedef StepSize_ StepSize;

	typedef VarIncrementCounter<Counter<VarIncrementCounterConfig>> Counter;
};

template<typename ValueType_, typename Init_, typename Bound_, typename StepSize_>
struct VarIncrementBoundedCounterConfig {
	typedef ValueType_ ValueType;
	typedef Init_ Init;
	typedef Bound_ Bound;
	typedef StepSize_ StepSize;

	typedef VarIncrementBoundedCounter<Counter<VarIncrementBoundedCounterConfig>> Counter;
};
