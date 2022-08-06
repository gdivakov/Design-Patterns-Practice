#include "Products.h"

class Logistics
{
public:
	void planDelivery()
	{
		Transport* tr = createTransport();

		// Plan relative to transport
		std::cout << "planDelivery" << std::endl;
	}
private:
	virtual Transport* createTransport() = 0;
};

class SeaLogistics : public Logistics
{
	virtual Transport* createTransport() { return new Ship(); }
};

class AirLogistics : public Logistics
{
	virtual Transport* createTransport() { return new Plane(); }
};

class LandLogistics : public Logistics
{
	virtual Transport* createTransport() { return new Truck(); }
};