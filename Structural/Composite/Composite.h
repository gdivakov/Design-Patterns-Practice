#pragma once
#include <list>

class Graphic
{
public:
	virtual void move(int x, int y) = 0;
	virtual void draw() = 0;
};

class Dot : public Graphic
{
private:
	int x, y;
public:
	Dot(int p_x, int p_y) : x(p_x), y(p_y) {};

	virtual void move(int x, int y) { /* move leaf */ };
	virtual void draw() { /* draw leaf */ };
};

class Circle : public Dot
{
private:
	int radius;
public:
	Circle(int x, int y, int r) : Dot(x, y), radius(r) {};

	virtual void draw() { /* draw circle */ };
};

class CompoundGraphic : public Graphic
{
private:
	typedef std::list<Graphic*> Children;
	Children children;
public:
	void add(Graphic* nextChild) { children.push_back(nextChild); };
	void remove(Graphic* childToRemove) { children.remove(childToRemove); };
	Children getChildren() { return children; };

	virtual void move(int x, int y) { /* move each child */ };
	virtual void draw() { /* draw each child */ };
};