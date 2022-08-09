#pragma once

class ServiceInterface
{
public:
	virtual void operation() = 0;
};

class Service : public ServiceInterface
{
public:
	virtual void operation() { /* Original functionality */ };
};

class Proxy : public ServiceInterface
{
private:
	Service* service;
public:
	Proxy(Service* p_service) : service(p_service) {};
	virtual void operation() { /* Additional functionality */; service->operation(); };
};