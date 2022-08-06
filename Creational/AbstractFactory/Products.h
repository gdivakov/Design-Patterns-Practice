#pragma once
class Chair {}; class Bed {}; class Table {};
class VenetianChair : public Chair {}; class VenetianBed : public Bed {}; class VenetianTable : public Table {};
class GothicChair : public Chair {}; class GothicBed : public Bed {}; class GothicTable : public Table {};

class FurnitureFactory
{
public:
	virtual Chair* createChair() = 0;
	virtual Bed* createBed() = 0;
	virtual Table* createTable() = 0;
};

class VenetianFurnitureFactory : public FurnitureFactory
{
public:
	virtual Chair* createChair() { return new VenetianChair(); }
	virtual Bed* createBed() { return new VenetianBed(); }
	virtual Table* createTable() { return new VenetianTable(); }
};

class GothicFurnitureFactory : public FurnitureFactory
{
public:
	virtual Chair* createChair() { return new GothicChair(); }
	virtual Bed* createBed() { return new GothicBed(); }
	virtual Table* createTable() { return new GothicTable(); }
};