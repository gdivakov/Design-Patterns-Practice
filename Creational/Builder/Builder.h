#pragma once

// Products
class Ship { public: int color; int collider; int weapon; };
class AIShip : public Ship { public: int ai; };
class ShipManual {};

// Base builder
class SpaceShipBuilder
{
public:
	virtual void reset() = 0;
	virtual void setShipColor(int color) = 0;
	virtual void setColliders(int collider) = 0;
	virtual void setWeapon(int weapon) = 0;
	virtual void setAI(int ai) = 0;
};

// Concrete builders
class PlayerSpaceShipBuilder : public SpaceShipBuilder
{
private:
	Ship* ship;
public:
	virtual void reset() { if (ship) { delete ship; } ship = new Ship(); };
	Ship* getResult() { return ship; };

	virtual void setShipColor(int color) { ship->color = color; };
	virtual void setColliders(int collider) { ship->collider = collider; };
	virtual void setWeapon(int weapon) { ship->weapon = weapon; };
	virtual void setAI(int ai) {};
};

class AISpaceShipBuilder : public SpaceShipBuilder
{
private:
	AIShip* ship;
public:
	virtual void reset() { if (ship) { delete ship; } ship = new AIShip(); };
	AIShip* getResult() { return ship; };

	virtual void setShipColor(int color) { ship->color = color; };
	virtual void setColliders(int collider) { ship->collider = collider; };
	virtual void setWeapon(int weapon) { ship->weapon = weapon; };
	virtual void setAI(int ai) { ship->ai = ai; };
};

class ShipManualBuilder : public SpaceShipBuilder
{
private:
	ShipManual* manual;
public:
	virtual void reset() { if (manual) { delete manual; } manual = new ShipManual(); };
	ShipManual* getResult() { return manual; };

	virtual void setShipColor(int color) { /* Set manual for color */ };
	virtual void setColliders(int collider) { /* Set manual for collider */ };
	virtual void setWeapon(int weapon) { /* Set manual for weapon */ };
	virtual void setAI(int ai) { /* Set manual for ai */ };
};

// Director 
class SpaceShipDirector
{
private:
	SpaceShipBuilder* builder;
public:
	SpaceShipDirector(SpaceShipBuilder* builder) { this->builder = builder; };

	void changeBuilder(SpaceShipBuilder* nextBuilder) { if (builder) { delete builder; } builder = nextBuilder; };

	void makePlayerShip() { builder->reset(); builder->setAI(331); builder->setColliders(111); /* Setting other props */ };
	void makeSuperShip() { builder->reset(); builder->setAI(141); builder->setWeapon(0); /* Setting other props */ };
	void makeAIShip() { builder->reset(); builder->setAI(331); builder->setColliders(111); /* Setting other props */ };
	void makeManual() { builder->reset(); builder->setShipColor(2); builder->setColliders(231); /* Setting other props */ };
};