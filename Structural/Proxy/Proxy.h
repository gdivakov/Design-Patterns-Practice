#pragma once
#include <iostream>
#include <map>
#include <vector>

struct Video {};

// Interface
class ThirdPartyYouTubeLib 
{
public:
	virtual Video* downloadVideo(int id) = 0;
	virtual std::vector<int> listVideos() = 0;
};

// Original class
class ThirdPartyYouTubeClass : public ThirdPartyYouTubeLib
{
public:
	virtual Video* downloadVideo(int id) { /* Download from youtube */ }
	virtual std::vector<int> listVideos() { /* Get list of videos */ };
};

// Caching Proxy
class TrirdPartyYouTubeProxy : public ThirdPartyYouTubeLib
{
private:
	ThirdPartyYouTubeLib* service;
	std::vector<int> listCache;
	std::map<int, Video*> downloadedCache;
	bool needsReset;
public:
	TrirdPartyYouTubeProxy(ThirdPartyYouTubeLib* p_service) : service(p_service), needsReset(false) {};

	virtual Video* downloadVideo(int id)
	{
		if (downloadedCache.find(id) == downloadedCache.end() || needsReset)
		{
			Video* video = service->downloadVideo(id);
			downloadedCache[id] = video;
		}

		return downloadedCache[id];
	};

	virtual std::vector<int> listVideos()
	{
		if (listCache.empty() || needsReset)
		{
			listCache = service->listVideos();
		}

		return listCache;
	};
};