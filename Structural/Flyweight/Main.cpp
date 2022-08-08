#include "Flyweight.h"

// When there is not enough RAM to support each needed objects [1]
//void main()
//{
//	Tree* tree = new Tree(23, 20, 111, 222);
//	Tree* secondTree = new Tree(23, 20, 444, 333);
//	Tree* thirdTree = new Tree(23, 20, 111, 222);
//	Tree* fourthTree = new Tree(23, 20, 444, 333);
//
//	tree->placeTree();
//	secondTree->placeTree();
//	thirdTree->placeTree();
//	fourthTree->placeTree();
//
//	TreeFactory::free();
//	delete tree;
//}