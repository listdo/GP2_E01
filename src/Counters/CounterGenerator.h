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
	IncrementFlag incrementFlag = no_increment,
	class Init_ = int,
	class Bound_ = int,
	class Step_ = int
>
class COUNTER_GENERATOR {
public:
	typedef COUNTER_GENERATOR<
		ValueType_,
		boundFlag,
		incrementFlag,
		Init_,
		Bound_,
		Step_
	> Generator;

private:
	enum { 
		isBound = boundFlag == with_bound,
		isStepSized = incrementFlag == with_increment,
	};

	typedef typename 
	IF<isBound,
		IF<
			isStepSized,	
			VarIncrementBoundedCounter<Counter<VarIncrementBoundedCounterConfig<ValueType_, Init_, Bound_, Step_>>>,
			BoundedCounter<Counter<BoundedCounterConfig<ValueType_, Init_, Bound_>>>
		>,
		IF<
			isBound,
			BoundedCounter<Counter<VarIncrementBoundedCounterConfig<ValueType_, Init_, Bound_, Step_>>>,
			Counter<CounterConfig<ValueType_, Init_>>
		>
	>::RET::RET Counter_with_bounds;

public:
	typedef Counter_with_bounds RET;

	struct Config {
		typedef RET Counter;
	};
};