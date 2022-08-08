#pragma once
#include <map>
#include <string>

class Flyweight
{
private:
	int repeatState;
public:
	Flyweight(int p_repeatState) : repeatState(p_repeatState) {};

	void operation(int uniqState) { /* doOperation(uniqState, repeatState) */ }
};

// Flyweight factory (Could also be implemented as a base class)
class FlyweightFactory
{
public:
	typedef std::map<std::string, Flyweight*> Flyweights;

	static Flyweight* getFlyweight(int repeatState)
	{
		std::string key = std::to_string(repeatState);

		if (!cache[key])
		{
			cache[key] = new Flyweight(repeatState);
		}

		return cache[key];
	};

	static void free() { /* Free cache */ };
private:
	static Flyweights cache;
};

FlyweightFactory::Flyweights FlyweightFactory::cache = {};

class Context
{
private:
	Flyweight* flyweight;
	int uniqState;
public:
	Context(int p_uniqState, int repeatState) : uniqState(p_uniqState)
	{
		flyweight = FlyweightFactory::getFlyweight(repeatState);
	};

	void operation() { flyweight->operation(uniqState); };
};