#include <iostream>
#include "Prototype.h"

// When your code should not depend on classes of copied objects [1]
// Store of prototypes could be implemented to have convenient way of coping objects
//void main()
//{
//	Shape* circle = new Circle(23);
//	Shape* cCircle = circle->clone();
//
//	Shape* rect = new Rect(23,22);
//	Shape* cRect = rect->clone();
//
//	delete circle;
//	delete cCircle;
//	delete rect;
//	delete cRect;
//}