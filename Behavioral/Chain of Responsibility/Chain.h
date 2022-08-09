#pragma once
#include <iostream>

struct Request {};

class AuthHandler
{
public:
	virtual void handle(Request* req) = 0;
	virtual AuthHandler* setNext(AuthHandler* next) = 0;
};

class AuthHandlerBase : public AuthHandler
{
protected:
	AuthHandler* next;
public:
	virtual void handle(Request* req) { if (next) { next->handle(req); } };
	// Return next to have ability to chain
	virtual AuthHandler* setNext(AuthHandler* p_next) { next = p_next; return next; };
};

// Log in
class AuthHandlerLogIn : public AuthHandlerBase
{
private:
	bool isAuthorized = false;
public:
	virtual void handle(Request* req) 
	{
		std::cout << "Log in" << std::endl;
		isAuthorized = true; // Always authorized

		if (isAuthorized)
		{
			AuthHandlerBase::handle(req);
		}
	};
};

// Logging
class AuthHandlerLogging : public AuthHandlerBase
{
public:
	virtual void handle(Request* req) { std::cout << "Do logging" << std::endl; AuthHandlerBase::handle(req); };
};

// Notify by email
class AuthHandlerSendEmail : public AuthHandlerBase
{
public:
	virtual void handle(Request* req) { std::cout << "Send email" << std::endl; AuthHandlerBase::handle(req); };
};