#pragma once
#include <iostream>

class Notifier
{
public:
	virtual void notify() = 0;
};

// Basic functionality (e.g. could be 3rd party lib)
class EmailNotifier : public Notifier
{
public:
	virtual void notify() { /* Notify by email */ };
};

class NotifierDecorator : public Notifier
{
protected:
	Notifier* wrappee;
public:
	NotifierDecorator(Notifier* p_wrappee) : wrappee(p_wrappee) {};
	virtual void notify() { wrappee->notify(); };
};

class SlackNotifier : public NotifierDecorator
{
public:
	SlackNotifier(Notifier* p_wrappee) : NotifierDecorator(p_wrappee) {};

	virtual void notify() { wrappee->notify(); /* Notify by slack */ };
};

class FacebookNotifier : public NotifierDecorator
{
public:
	FacebookNotifier(Notifier* p_wrappee) : NotifierDecorator(p_wrappee) {};

	virtual void notify() { wrappee->notify(); /* Notify by facebook */ };
};