#pragma once

class Implementation // Implementation interface
{
public:
	virtual void method1() = 0;
	virtual void method2() = 0;
	virtual void method3() = 0;
};

class Abstraction
{
protected:
	Implementation* implementator;
public:
	Abstraction(Implementation* p_implementator) : implementator(p_implementator) {};
	~Abstraction() { implementator = nullptr; };

	virtual void featureA() { implementator->method1(); };
	virtual void featureB() { implementator->method2(); implementator->method3(); };
	virtual void featureC() { implementator->method3(); implementator->method1(); };
};

// Extended logic
class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(Implementation* implementator) : Abstraction(implementator) {};
	// Additional features
	void featureD() { implementator->method1(); implementator->method2(); }
};

class ConcreteImplementationA : public Implementation
{
public:
	virtual void method1() { /* Concrete implementation A */ };
	virtual void method2() { /* Concrete implementation A */ };
	virtual void method3() { /* Concrete implementation A */ };
};

class ConcreteImplementationB : public Implementation
{
public:
	virtual void method1() { /* Concrete implementation B */ };
	virtual void method2() { /* Concrete implementation B */ };
	virtual void method3() { /* Concrete implementation B */ };
};