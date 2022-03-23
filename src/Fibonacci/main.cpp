#include <iostream>
#include <chrono>

#include "Fibonacci.h"
#include "TMFs.h"

using namespace std;

template<typename Func>
void measure(string s, Func func) {
	auto start = chrono::high_resolution_clock::now();
	auto fib = func();
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double, milli> duration = end - start;
	cout << "[duration: " << duration.count() << " ms]: " << s << " = " << fib << endl;
}

int main() {
	measure("Fibonacci<40>::RET", []() { return Fibonacci<40>::RET; });
	measure("fibonacci(40)", []() { return fibonacci(40); });

	DO<FibonacciStatement<20>, FibonacciEndCondition<40>>::exec();
}
