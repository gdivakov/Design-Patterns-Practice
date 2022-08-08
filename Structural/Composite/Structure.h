#pragma once
#include <list>

class Component
{
public:
	virtual void execute() = 0;
};

class Leaf : public Component
{
public:
	virtual void execute() { /* some work */ };
};

class Composite : public Component
{
private:
	std::list<Component*> children;
public:
	virtual void execute() { /* execute for all child */ };

	void add(Component* nextChild) { children.push_back(nextChild); };
	void remove(Component* childToRemove) { children.remove(childToRemove); };
	std::list<Component*> getChildren() { return children; };
};