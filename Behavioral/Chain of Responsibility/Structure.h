#pragma once

struct Request {};

// Interface
class Handler
{
public:
	virtual void handle(Request* req) = 0;
	virtual void setNext(Handler* next) = 0;
};

class BaseHandler : public Handler
{
protected:
	Handler* next;
public:
	virtual void handle(Request* req) { if (next) { next->handle(req); } }
	virtual void setNext(Handler* p_next) { next = p_next; };
};

class ConcreteHandlers : public BaseHandler
{
public:
	// Concrete handler decides to stop or continue processing the chain
	virtual void handle(Request* req) { /* Concrete logic */; BaseHandler::handle(req); };
};