#include "Proxy.h"

// Lazy initialization (Virtual Proxy) [1]
// Access protection (Protecting Proxy) [2]
// Local start of the service (Remote Proxy) [3]
// Request Logging (Logging Proxy) [4]
// Object caching (Caching Proxy) [5]

void manager(ThirdPartyYouTubeLib* service)
{
	service->listVideos();
};

//void main()
//{
//	ThirdPartyYouTubeLib* service = new ThirdPartyYouTubeClass();
//	ThirdPartyYouTubeLib* pService = new TrirdPartyYouTubeProxy(service);
//
//	manager(pService);
// 
//	delete service;
//	delete pService;
//}