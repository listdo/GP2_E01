#pragma once

#include "TMFs.h"
#include "Counter.h"
#include "BoundedCounter.h"
#include "VarIncrementCounter.h"

enum BoundFlag { with_bound, no_bound };
enum IncrementFlag { with_increment, no_increment };

template <
	class ValueType_,
	BoundFlag boundFlag = no_bound,
	class Init_ = int,
	class Bound_ = int
>
class COUNTER_GENERATOR {
public:
	typedef COUNTER_GENERATOR<
		ValueType_,
		boundFlag,
		Init_,
		Bound_
	> Generator;

private:
	enum { 
		isBound = boundFlag == with_bound 
	};

	typedef IF<isBound,
		BoundedCounter<Counter<BoundedCounterConfig<ValueType_, Init_, Bound_>>>,
		Counter<CounterConfig<ValueType_, Init_>>
	>::RET Counter;

public:
	typedef Counter_ RET;

	struct Config {
		typedef Counter_ Counter;
		typedef RET ReturnType;
	};
};