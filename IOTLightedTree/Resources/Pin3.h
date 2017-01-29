// Pin3.h

#ifndef _PIN3RESOURCE_h
#define _PIN3RESOURCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MKR1000ServerLib.h"

class Pin3 : public RESTResourceBase
{
public:
	Pin3();
	~Pin3();
	// Inherited via RESTResourceBase
	virtual String getName() override;
protected:
	virtual void processPost(String params, String* body);

	virtual void processPut(String params, String* body);
private:
	bool _isInitiated = false;
	const int PinNumber = 3;
};

#endif