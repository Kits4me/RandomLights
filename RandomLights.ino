/*
 Name:		RandomLights.ino
 Created:	4/21/2021 1:08:38 PM
 Author:	amird
*/
#define ledPinBlue      6
#define ledPinGreen     9
#define ledPinYellow    10
#define ledPinRed       11

#define NUM_OF_BTNS 4
int Leds[NUM_OF_BTNS] = { ledPinRed,ledPinGreen,ledPinBlue,ledPinYellow };

#define CODE_LEN 6
int CurrCode[CODE_LEN];

// the setup function runs once when you press reset or power the board
void setup() {
	randomSeed(analogRead(A5));
	for (int k = 0; k < NUM_OF_BTNS; k++) {
		pinMode(Leds[k], OUTPUT);
	}

	for (int k = 0; k < CODE_LEN; k++) {
		CurrCode[k] = random(NUM_OF_BTNS);
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
	delay(8000);
	ShowCode();
}
void ShowCode() {
	for (int k = 0; k < CODE_LEN; k++) {
		digitalWrite(Leds[CurrCode[k]], HIGH);
		delay(300);
		digitalWrite(Leds[CurrCode[k]], LOW);
		delay(300);
	}
}
