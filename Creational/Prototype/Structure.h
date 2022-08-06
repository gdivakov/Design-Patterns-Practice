#pragma once

class Prototype // Interface
{
public:
	virtual Prototype* clone() = 0;
};

class ConcretePrototype : public Prototype
{
private:
	int field1;
public:
	ConcretePrototype(ConcretePrototype& source) : Prototype(source) { field1 = source.field1; };
	virtual Prototype* clone() { return new ConcretePrototype(*this); };
};

class SubclassPrototype : public ConcretePrototype
{
private:
	int field2;
public:
	SubclassPrototype(SubclassPrototype& source) : ConcretePrototype(source) { field2 = source.field2; };
	virtual Prototype* clone() { return new SubclassPrototype(*this); };
};