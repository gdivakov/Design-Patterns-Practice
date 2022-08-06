class Product {};
class ConcreateProductA : public Product {};
class ConcreateProductB : public Product {};

class Creator {
	virtual Product* factoryMethod() = 0;
public:
	void someOperation() 
	{
		Product* pr = factoryMethod();
		// ... some actions with Product
	};
};

class ConcreteCreatorA : public Creator
{
	virtual Product* factoryMethod() { return new ConcreateProductA(); }
};

class ConcreteCreatorB : public Creator
{
	virtual Product* factoryMethod() { return new ConcreateProductB(); }
};