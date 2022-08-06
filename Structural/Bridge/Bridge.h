#pragma once

class Device
{
public:
	virtual bool isEnabled() = 0;
	virtual void enable() = 0;
	virtual void disable() = 0;
	virtual float getVolume() = 0;
	virtual void setVolume(float percent) = 0;
};

class RemoteController
{
protected:
	Device* device;
public:
	RemoteController(Device* p_device) : device(p_device) {};
	~RemoteController() { device = nullptr; };

	virtual void volumeUp() { device->setVolume(device->getVolume() + 10.0f); };
	virtual void volumeDown() { device->setVolume(device->getVolume() - 10.0f); };
	virtual void toggleEnabled() { device->isEnabled() ? device->disable() : device->enable(); };
};

class ModernRemoteController : public RemoteController
{
public:
	ModernRemoteController(Device* device) : RemoteController(device) {};

	void mute() { device->setVolume(0.0f); };
};

class PlayStation : public Device
{
public:
	virtual bool isEnabled() { /* PS implementation */ };
	virtual void enable() { /* PS implementation */ };
	virtual void disable() { /* PS implementation */ };
	virtual float getVolume() { /* PS implementation */ };
	virtual void setVolume(float percent) { /* PS implementation */ };
};

class TV : public Device
{
public:
	virtual bool isEnabled() { /* TV implementation */ };
	virtual void enable() { /* TV implementation */ };
	virtual void disable() { /* TV implementation */ };
	virtual float getVolume() { /* TV implementation */ };
	virtual void setVolume(float percent) { /* TV implementation */ };
};