#include <bits/stdc++.h>

using namespace std;

class Strategy;

typedef shared_ptr<Strategy> PStrategy;

class Strategy {
public:
	virtual void AlgorithmInterface() = 0;
};

class ConcerteStrategyA : public Strategy {
public:
	void AlgorithmInterface() override {
		printf("ºâªkA\n");
	}
};
class ConcerteStrategyB : public Strategy {
public:
	void AlgorithmInterface() override {
		printf("ºâªkB\n");
	}
};

class Context {
private:
	PStrategy p;
public:
	Context(PStrategy ptr) {
		this->p = ptr;
	}
	void ContextInterface() {
		this->p->AlgorithmInterface();
	}
};

int main()
{
	Context A(make_shared<ConcerteStrategyA>());
	Context B(make_shared<ConcerteStrategyB>());
	A.ContextInterface();
	B.ContextInterface();
	return 0;
}