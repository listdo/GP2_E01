#include <iostream>

#include "Configurations.h"
#include "Counter.h"
#include "VarIncrementCounter.h"
#include "BoundedCounter.h"
#include "CounterGenerator.h"

using namespace std;

int main(int argc, char ** argv) {
	//CounterConfig<int, IntValue<0>>::Counter counter;
	//CounterConfig<double, DoubleValue_0_5>::Counter counter;
	BoundedCounterConfig<int, IntValue<0>, IntValue<3>>::Counter counter;

	cout << counter.value() << endl;
	for (int i = 0; i < 5; i++)
		counter.increment();
	cout << counter.value() << endl;
	counter.reset();
	cout << counter.value() << endl;

	VarIncrementCounterConfig<int, IntValue<0>, IntValue<7>>::Counter counter2;
	cout << counter.value() << endl;

	for (int i = 0; i < 5; i++)
		counter2.increment();

	cout << counter2.value() << endl;
	counter2.reset();
	cout << counter2.value() << endl;


	//COUNTER_GENERATOR<int, no_bound, IntValue<5>>::Generator generator;
	COUNTER_GENERATOR<int, no_bound, IntValue<10>, IntValue<0>>::Config::Counter counter3;

	for (int i = 0; i < 5; i++)
		counter3.increment();

	//cout << counter3.value() << endl;
	//counter2.reset();
	//cout << counter3.value() << endl;



	return 0;
}
