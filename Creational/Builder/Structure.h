#pragma once

class ProductA {}; class ProductB {};

class Director 
{
private:
	Builder* builder;
public:
	Director(Builder* builder) { this->builder = builder; };
	void changeBuilder(Builder* nextBuilder) { if (builder) { delete builder; } builder = nextBuilder; };
	void makeProduct1() { builder->reset(); builder->step1(); builder->step3(); };
	void makeProduct2() { builder->reset(); builder->step1(); builder->step2(); builder->step3(); }
};

class Builder 
{
public:
	virtual void reset() = 0;
	virtual void step1() = 0;
	virtual void step2() = 0;
	virtual void step3() = 0;
};

class ConcreteBuilderA : public Builder 
{
private:
	ProductA* product;
public:
	virtual void reset() { if (product) { delete product; } product = new ProductA(); };
	virtual void step1() { /* Set feature A */ };
	virtual void step2() { /* Set feature B */ };
	virtual void step3() { /* Set feature C */ };
	virtual ProductA* getResult() { return product; };
};

class ConcreteBuilderB : public Builder
{
private:
	ProductB* product;
public:
	virtual void reset() { if (product) { delete product; } product = new ProductB(); };
	virtual void step1() { /* Set feature A */ };
	virtual void step2() { /* Set feature B */ };
	virtual void step3() { /* Set feature C */ };
	virtual ProductB* getResult() { return product; };
};

class ConcreteBuilder2 : public Builder {};