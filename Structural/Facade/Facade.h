#pragma once

struct VideoFile {}; 

class VideoConverter
{
private:
	// links to subsystems here
public:
	VideoConverter() { /* Initialize subsystems */ };
	VideoFile* convertVideo(const char * filename, const char * format)
	{
		VideoFile* file = new VideoFile();

		//subsystem1.doWork(file);
		//subsystem2.doWork(file);
		//subsystem3.doWork(file);
		//subsystem4.doWork(file);

		return file;
	};
};

