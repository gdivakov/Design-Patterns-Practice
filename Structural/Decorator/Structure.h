#pragma once

// Functionality interface
class Component
{
public:
	virtual void execute() = 0;
};

// Basic functionality
class ConcreteComponent : public Component
{
public:
	virtual void execute() { /* original component functionality */ };
};

// Additional functionality
class BaseDecorator : public Component
{
protected:
	Component* wrappee;
public:
	BaseDecorator(Component* p_wrappee) : wrappee(p_wrappee) {};
	virtual void execute() { wrappee->execute(); };
};

// Additional functionality
class ConcreteDecorator : public BaseDecorator
{
public:
	ConcreteDecorator(Component* p_wrappee) : BaseDecorator(p_wrappee) {};
	virtual void execute() { wrappee->execute(); extra(); };
	void extra() { /* additional logic */ };
};