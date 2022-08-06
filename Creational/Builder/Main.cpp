#include "Builder.h"

// Instead of using huge constructor we delegate work to director [1]
// Director knows how to use builder to construct needed object
// Same builder could be used to create different representation of object (aiShip and superShip in example below) [2]
//void main()
//{
//	PlayerSpaceShipBuilder* plBuilder = new PlayerSpaceShipBuilder();
//	AISpaceShipBuilder* aiBuilder = new AISpaceShipBuilder();
//	ShipManualBuilder* mBuilder = new ShipManualBuilder();
//
//	SpaceShipDirector* director = new SpaceShipDirector(plBuilder);
//
//	// Create player ship
//	director->makePlayerShip();
//	Ship* playerShip = plBuilder->getResult();
//
//	// Create ai ship
//	director->changeBuilder(aiBuilder);
//	director->makeAIShip();
//	AIShip* aiShip = aiBuilder->getResult();
//
//	// Create super ship (using same builder)
//	director->makeSuperShip();
//	Ship* superShip = aiBuilder->getResult();
//
//	// Create ship manual
//	director->changeBuilder(mBuilder);
//	ShipManual* manual = mBuilder->getResult();
//}