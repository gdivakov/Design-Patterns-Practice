#pragma once

class Singleton
{
private:
	static Singleton* instance;
public:
	Singleton() { /* Initialization */ };
	~Singleton() { delete instance; instance = nullptr; };

	static Singleton* getInstance() { if (instance) { return instance; } return instance = new Singleton(); }
	void SomeBusinessLogic() { /* Business logic */ }
};

Singleton* Singleton::instance = nullptr;