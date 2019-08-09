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

class OperatorContext {
public:
	OperatorContext() {};
	OperatorContext(string op) {
		this->setOp(op);
	}
	void setOp(string op) {
		pOpe = OperatorFactory::createOperator(op);
	}
	double GetResult(double a, double b) {
		if (this->pOpe == nullptr)
			throw "«ü°w¬°ªÅ";
		this->pOpe->a = a;
		this->pOpe->b = b;
		return this->pOpe->GetResult();
	}
private:
	pOperator pOpe{ nullptr };
};

int main()
{
	OperatorContext c;
	try {
		c.setOp("+");
		cout << c.GetResult(3, 1) << endl;
		c.setOp("-");
		cout << c.GetResult(3, 1) << endl;
	}
	catch (string err) {
		cout << err << endl;
	}
	return 0;
}