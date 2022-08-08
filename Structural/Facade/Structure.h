#pragma once

class AdditionalFacade
{
private:
	// links to other subsystem objects
public:
	void methodC() { /* use subsystem functionality */ };
	void methodD() { /* use subsystem functionality */ };
};

class Facade
{
private:
	// links to subsystem objects
	AdditionalFacade* addFacade; // Optional
public:
	void methodA() { /* use subsystem functionality */ };
	void methodB() { /* use subsystem functionality */ };
};