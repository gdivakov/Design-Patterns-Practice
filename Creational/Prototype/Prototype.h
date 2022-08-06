#pragma once

class Shape
{
public:
	Shape() {};
	Shape(Shape& source) {};
	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
private:
	int w;
	int h;
public:
	Rect(int w, int h) : Shape() { this->w = w; this->h = h; };
	//Rect(Rect& source) : Shape(source), w(source.w), h(source.h) {}; // Implemented by default copy constructor
	virtual Shape* clone() { return new Rect(*this); };
};

class Circle : public Shape
{
private:
	int r;
public:
	Circle(int r) : Shape() { this->r = r; };
	//Circle(Circle& source) : Shape(source), r(source.r) {}; // Implemented by default copy constructor
	virtual Shape* clone() { return new Circle(*this); };
};