#pragma once

template<bool Condition, typename Then, typename Else>
struct IF {
	typedef Then RET;
};

template<typename Then, typename Else>
struct IF<false, Then, Else> {
	typedef Else RET;
};

struct STOP {
	static void exec() { }
};

template<typename Statement, typename Condition>
struct DO {
	static void exec() {
		Statement::exec();

		IF<Condition::Code<Statement::Next>::RET,
			DO<Statement::Next, 
			Condition>,
			STOP
		>::RET::exec();
	}
};
