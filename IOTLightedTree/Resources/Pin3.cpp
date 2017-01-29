// Copyrights - Sameer Khandekar
// MIT License
// 

#include "Pin3.h"
// constructor
Pin3::Pin3()
{
}
// destructor
Pin3::~Pin3()
{
}
// name of the resource
String Pin3::getName()
{
	return "Pin3";
}
// POST is used for initiation
// i.e. set the pinMode
void Pin3::processPost(String params, String * body)
{
	// if it is already initiated, it is a conflict
	if (_isInitiated)
	{
		setResponseHeader(HTTP_409_STATUS);
	}
	else
	{
		// set the pin mode and http status
		pinMode(PinNumber, OUTPUT);
		setResponseHeader(HTTP_201_STATUS);
		_isInitiated = true;
	}
	setResponseBody("");
}
// put turns LED on/off based on the value
void Pin3::processPut(String params, String * body)
{
	setResponseHeader(HTTP_200_STATUS);
	setResponseBody("");

	if (params.equalsIgnoreCase("on"))
	{
		digitalWrite(PinNumber, HIGH);   // turn the relay on (HIGH is the voltage level)
	}
	else
	{
		digitalWrite(PinNumber, LOW);   // turn the relay off (HIGH is the voltage level)
	}
}
