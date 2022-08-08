#include "Composite.h"

// Need to present tree object structure [1]
// Need to have one interface for compound and simple objects [2]
//void main()
//{
//	std::list<Graphic*> graphics;
//
//	// Create circle
//	Graphic* circle = new Circle(23, 20, 10);
//	graphics.push_back(circle);
//
//	// Create dot
//	Graphic* dot = new Dot(1, 33);
//	graphics.push_back(dot);
//
//	// Create compound graphic component
//	CompoundGraphic* comp = new CompoundGraphic();
//	Graphic* circle2 = new Circle(13, 11, 5);
//	Graphic* dot2 = new Dot(11, 43);
//	comp->add(circle2);
//	comp->add(dot2);
//
//	graphics.push_back(comp);
//
//	// Render all
//	for (auto& el : graphics)
//	{
//		el->draw();
//	}
//}