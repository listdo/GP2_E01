#pragma once

#include <iostream>

template<int n>
struct Fibonacci {
	enum { RET = Fibonacci<n-1>::RET + Fibonacci<n-2>::RET };
};

template<>
struct Fibonacci<0> {
	enum { RET = 0 };
};

template<>
struct Fibonacci<1> {
	enum { RET = 1 };
};

int fibonacci(int n) {
	return n == 0 ? 0
		 : n == 1 ? 1
		 : fibonacci(n - 1) + fibonacci(n - 2);
}

template<int n>
struct FibonacciStatement {
	typedef FibonacciStatement<n + 1> Next;

	enum { current = n };

	static void exec() {
		std::cout << "Fibonacci<" << n << ">::RET = " << Fibonacci<n>::RET << std::endl;
	}
};

template<int max>
struct FibonacciEndCondition {
	template<typename Statement>
	struct Code {
		enum { RET = Statement::current < max };
	};
};
