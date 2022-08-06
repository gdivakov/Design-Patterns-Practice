#pragma once

class ExistingClass
{
public:
	void method() {};
};

class Service
{
public:
	void serviceMethod() {};
};

class Adapter
{
private:
	Service* service;
public:
	Adapter(Service* p_service) : service(p_service) {};
	void method() 
	{
		//specialData = convertToServiceFormat();
		//return service->serviceMethod(specialData);
	}
};