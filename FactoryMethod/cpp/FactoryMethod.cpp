#include <iostream>
using namespace std;

class Product {
public:
	Product();
	virtual ~Product();
	virtual void Operation() = 0;
};

class Creator {
public:
	Creator();
	virtual ~Creator();
	virtual Product* FactoryMethod() = 0;
};

class ProductA: public Product {
public:
	ProductA();
	virtual ~ProductA();
	virtual void Operation();
};

class ProductB: public Product {
public:
	ProductB();
	virtual ~ProductB();
	virtual void Operation();
};

class CreatorA: public Creator {
public:
	CreatorA();
	virtual ~CreatorA();
	virtual Product* FactoryMethod();
};

class CreatorB: public Creator {
public:
	CreatorB();
	virtual ~CreatorB();
	virtual Product* FactoryMethod();
};

Product::Product() {}
Product::~Product() {}

ProductA::ProductA() {}
ProductA::~ProductA() {}
void ProductA::Operation() {
	cout << "ProductA" << endl;
}

ProductB::ProductB() {}
ProductB::~ProductB() {}
void ProductB::Operation() {
	cout << "ProductB" << endl;
}

Creator::Creator() {}
Creator::~Creator() {}

CreatorA::CreatorA() {}
CreatorA::~CreatorA() {}
Product* CreatorA::FactoryMethod() {
	return new ProductA();
}

CreatorB::CreatorB() {}
CreatorB::~CreatorB() {}
Product* CreatorB::FactoryMethod() {
	return new ProductB();
}

Creator* Create(char sw) {
	if(sw=='A') {
		return new CreatorA();
	} else if(sw=='B') {
		return new CreatorB();
	}
}


int main(){
	Creator* creator1 = Create('A');
	Creator* creator2 = Create('B');
	
	Product* product1 = creator1->FactoryMethod();
	Product* product2 = creator2->FactoryMethod();

	product1->Operation();
	product2->Operation();

	delete product1;
	delete product2;
	delete creator1;
	delete creator2;

	return 0;
}
