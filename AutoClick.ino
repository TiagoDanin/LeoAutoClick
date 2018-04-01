#include "Mouse.h"
// Version 1.0.0
// by Tiago Danin

int status = 0;
int bnt = 0;
bool isEnable = false;

void setup() {
	pinMode(3, INPUT);
	pinMode(13, OUTPUT);
	Mouse.begin();
}

void loop() {
	// Ajutes de velocidade
	status = analogRead(A3);
	Serial.print("\n");
	Serial.print(status);
	analogWrite(A3, 0);
	delay(status * 1);

	// Botão
	bnt = analogRead(A0);
	Serial.print("			 ");
	Serial.print(bnt);
	analogWrite(A0, 0);
	if (bnt != 0) {
		delay(250);
		if (isEnable == true) {
			isEnable = false;
		} else {
			isEnable = true;
		}
	}

	// Led
	if (isEnable == true) {
		digitalWrite(13, HIGH);
	} else {
		digitalWrite(13, LOW);
	}

	// Ativar ?
	if (isEnable == true) {
		if (!Mouse.isPressed(MOUSE_LEFT)) {
			Mouse.press(MOUSE_LEFT);
			Mouse.release(MOUSE_LEFT);
		}
	} else {
		if (Mouse.isPressed(MOUSE_LEFT)) {
			Mouse.release(MOUSE_LEFT);
		}
	}
}
