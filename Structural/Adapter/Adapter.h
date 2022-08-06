#pragma once

struct JSON {}; struct XML {}; // For example purposes
JSON transformXMLToJson(XML& data) {};

// External service
class XMLDataService 
{
public:
	XML getXMLData() {};
};

// Other service
class JSONDataService
{
public:
	JSON getJSONData() {}
};

// Adapter
class XMLToJSONAdapter
{
private:
	XMLDataService* service;
public:
	XMLToJSONAdapter(XMLDataService* p_service) : service(p_service) {};
	~XMLToJSONAdapter() { delete service; service = nullptr; };

	JSON getJSONData()
	{
		XML rawData = service->getXMLData();

		return transformXMLToJson(rawData);
	}
};