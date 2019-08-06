#include <bits/stdc++.h>

using namespace std;

class Operator;

typedef shared_ptr<Operator> pOperator;

class Operator {
public:
	double a, b;
	virtual double GetResult() {
		return 0;
	}
};

class OperatorAdd : public Operator {
public:
	double GetResult() override {
		return a + b;
	}
};

class OperatorSub : public Operator {
public:
	double GetResult() override {
		return a - b;
	}
};

class OperatorFactory {
public:
	static pOperator createOperator(string op) {
		pOperator result;
		if (op == "+") {
			result = make_shared<OperatorAdd>();
		}
		else if (op == "-") {
			result = make_shared<OperatorSub>();
		}
		return result;
	}
};

int main()
{
	auto opAdd = OperatorFactory::createOperator("+");
	auto opSub = OperatorFactory::createOperator("-");
	opAdd = opSub;
	opAdd->a = 1; opAdd->b = 2;
	cout << opAdd->GetResult() << endl;
	opSub->a = 6; opSub->b = 2;
	cout << opSub->GetResult() << endl;
	return 0;
}