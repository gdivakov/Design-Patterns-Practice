#include <iostream>

class Transport // Base
{
public:
	virtual void deliver() = 0;
};

class Truck : public Transport
{
public:
	virtual void deliver() { std::cout << "Deliver by land\n"; }
};

class Ship : public Transport
{
public:
	virtual void deliver() { std::cout << "Deliver by sea\n"; }
};

class Plane : public Transport
{
public:
	virtual void deliver() { std::cout << "Deliver by air\n"; }
};
