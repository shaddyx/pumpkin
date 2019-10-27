#include "Arduino.h"

#include "r.h"
//The setup function is called once at startup of the sketch
#define PIN 0
#define mValue 40
#define mxValue 250

int current = mValue;
int trend = 0;

void setup()
{
	random_init(0xabcd); // initialize 16 bit seed
	pinMode(PIN, OUTPUT);
}

// The loop function is called in an endless loop
void loop()
{
	delay(10);
	current += trend;
	auto r = u_random();

	if (r < 5000){
		trend = - (u_random() & 255);
	} else if (r > 60000){
		trend = u_random() & 255;
	}

	current += trend;

	if (current < mValue) {
		current = mValue;
	}

	if (current > mxValue) {
		current = mxValue;
	}

	analogWrite(PIN, current & 255);
}
