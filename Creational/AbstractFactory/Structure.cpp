class ProductA {}; class ProductB {}; class ProductC {};
class ConcreteProductA1 : public ProductA {}; class ConcreteProductB1 : public ProductB {}; class ConcreteProductC1 : public ProductC {};
class ConcreteProductA2 : public ProductA {}; class ConcreteProductB2 : public ProductB {}; class ConcreteProductC2 : public ProductC {};

class AbstactFactory
{
public:
	virtual ProductA* createProductA() = 0;
	virtual ProductB* createProductB() = 0;
	virtual ProductC* createProductC() = 0;
};

class ConcreteFactory1
{
public:
	virtual ProductA* createProductA()
	{
		return new ConcreteProductA1();
	}
	virtual ProductB* createProductB()
	{
		return new ConcreteProductB1();
	}
	virtual ProductC* createProductC()
	{
		return new ConcreteProductC1();
	}
};

class ConcreteFactory2
{
public:
	virtual ProductA* createProductA()
	{
		return new ConcreteProductA2();
	}
	virtual ProductB* createProductB()
	{
		return new ConcreteProductB2();
	}
	virtual ProductC* createProductC()
	{
		return new ConcreteProductC2();
	}
};