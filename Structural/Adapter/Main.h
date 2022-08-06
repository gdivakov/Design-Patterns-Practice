#pragma once
#include <vector>
#include "Adapter.h"

// When we need to adapt some interface [1]

// When need to use a third party class 
// but its interface does not match the rest of the application code. [2]
//void main()
//{
//	// Source 1
//	JSONDataService* source1 = new JSONDataService();
//	// Source 2
//	XMLToJSONAdapter* source2 = new XMLToJSONAdapter(new XMLDataService());
//
//	std::vector<JSON> data = { source1->getJSONData(), source2->getJSONData() };
//
//	for (auto& el : data)
//	{
//		// Handle json from sources
//	}
//}