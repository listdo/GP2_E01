#include <iostream>

#include "Configurations.h"
#include "Counter.h"
#include "VarIncrementCounter.h"
#include "BoundedCounter.h"
#include "CounterGenerator.h"

using namespace std;

int main(int argc, char ** argv) {
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


	// Task 3. CounterGenerator
	COUNTER_GENERATOR<int, no_bound, no_increment, IntValue<10>, IntValue<0>, IntValue<1>>::RET counter3;

	for (int i = 0; i < 20; i++) {
		counter3.increment();
		cout << counter3.value() << endl;
	}

	cout << counter3.value() << endl;
	counter3.reset();
	cout << counter3.value() << endl;

	// Task 3. CounterGenerator
	COUNTER_GENERATOR<int, with_bound, with_increment, IntValue<0>, IntValue<100>, IntValue<3>>::RET counter4;

	for (int i = 0; i < 50; i++) {
		counter4.increment();
		cout << counter4.value() << endl;
	}

	cout << counter4.value() << endl;
	counter4.reset();
	cout << counter4.value() << endl;

	return 0;
}
