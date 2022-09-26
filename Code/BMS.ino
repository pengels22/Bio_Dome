#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads1;
Adafruit_ADS1115 ads2;

int adc0 = 0;
int adc1 = 0;
int adc2 = 0;
int adc3 = 0;

int adc4 = 0;
int adc5 = 0;
int adc6 = 0;
int adc7 = 0;
int volt8 = 0;

int Cell1 = 2;
int Cell2 = 3;
int Cell3 = 4;
int Cell4 = 5;
int Cell5 = 6;
int Cell6 = 7;
int Cell7 = 8;
int Cell8 = 9;
float volts0, volts1, volts2, volts3, volts4, volts5, volts6, volts7;

void setup() {
  // put your setup code here, to run once:
  ads1.begin(0x48);
  ads2.begin(0x49);
  pinMode(Cell1, OUTPUT);
  pinMode(Cell2, OUTPUT);
  pinMode(Cell3, OUTPUT);
  pinMode(Cell4, OUTPUT);
  pinMode(Cell5, OUTPUT);
  pinMode(Cell6, OUTPUT);
  pinMode(Cell7, OUTPUT);
  pinMode(Cell8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  volt8 = analogRead(A0);
  volt8 = map(volt8, 0, 1023, 0, 5) * 5;
  if (volt8 > 10) {
    adc0 = ads1.readADC_SingleEnded(0);
    adc1 = ads1.readADC_SingleEnded(1);
    adc2 = ads1.readADC_SingleEnded(2);
    adc3 = ads1.readADC_SingleEnded(3);
    volts0 = ads1.computeVolts(adc0);
    volts1 = ads1.computeVolts(adc1);
    volts2 = ads1.computeVolts(adc2);
    volts3 = ads1.computeVolts(adc3);

    adc4 = ads2.readADC_SingleEnded(0);
    adc5 = ads2.readADC_SingleEnded(1);
    adc6 = ads2.readADC_SingleEnded(2);
    adc7 = ads2.readADC_SingleEnded(3);
    volts4 = ads2.computeVolts(adc4);
    volts5 = ads2.computeVolts(adc5);
    volts6 = ads2.computeVolts(adc6);
    volts7 = ads2.computeVolts(adc7);
    volts0 = volts0 * 5;
    volts1 = volts1 * 5;
    volts2 = volts2 * 5;
    volts3 = volts3 * 5;
    volts4 = volts4 * 5;
    volts5 = volts5 * 5;
    volts6 = volts6 * 5;
    volts7 = volts7 * 5;
    if (volts0 < 10) {
      digitalWrite(Cell1, HIGH);
    }
    else {
      digitalWrite(Cell1, LOW);
    }

    if (volts1 < 10) {
      digitalWrite(Cell2, HIGH);
    }
    else {
      digitalWrite(Cell2, LOW);
    }
    if (volts2 < 10) {
      digitalWrite(Cell3, HIGH);
    }
    else {
      digitalWrite(Cell3, LOW);
    }
    if (volts3 < 10) {
      digitalWrite(Cell4, HIGH);
    }
    else {
      digitalWrite(Cell4, LOW);
    }

    if (volts4 < 10) {
      digitalWrite(Cell5, HIGH);
    }
    else {
      digitalWrite(Cell5, LOW);
    }
    if (volts5 < 10) {
      digitalWrite(Cell6, HIGH);
    }
    else {
      digitalWrite(Cell6, LOW);
    }

    if (volts6 < 10) {
      digitalWrite(Cell7, HIGH);
    }
    else {
      digitalWrite(Cell7, LOW);
    }
    if (volts7 < 10) {
      digitalWrite(Cell8, HIGH);
    }
    else {
      digitalWrite(Cell8, LOW);
    }


    if (volts0 > 12) {
      digitalWrite(Cell1, LOW);
    }
    else {
      digitalWrite(Cell1, HIGH);
    }

    if (volts1 > 12) {
      digitalWrite(Cell2, LOW);
    }
    else {
      digitalWrite(Cell2, HIGH);
    }

    if (volts2 > 12) {
      digitalWrite(Cell3, LOW);
    }
    else {
      digitalWrite(Cell3, HIGH);
    }

    if (volts3 > 12) {
      digitalWrite(Cell4, LOW);
    }
    else {
      digitalWrite(Cell4, HIGH);
    }

    if (volts4 > 12) {
      digitalWrite(Cell5, LOW);
    }
    else {
      digitalWrite(Cell5, HIGH);
    }

    if (volts5 > 12) {
      digitalWrite(Cell6, LOW);
    }
    else {
      digitalWrite(Cell6, HIGH);
    }

    if (volts6 > 12) {
      digitalWrite(Cell7, LOW);
    }
    else {
      digitalWrite(Cell7, HIGH);
    }
    if (volts7 > 12) {
      digitalWrite(Cell8, LOW);
    }
    else {
      digitalWrite(Cell8, HIGH);
    }


  }
  adc0 = ads1.readADC_SingleEnded(0);
  adc1 = ads1.readADC_SingleEnded(1);
  adc2 = ads1.readADC_SingleEnded(2);
  adc3 = ads1.readADC_SingleEnded(3);
  volts0 = ads1.computeVolts(adc0);
  volts1 = ads1.computeVolts(adc1);
  volts2 = ads1.computeVolts(adc2);
  volts3 = ads1.computeVolts(adc3);

  adc4 = ads2.readADC_SingleEnded(0);
  adc5 = ads2.readADC_SingleEnded(1);
  adc6 = ads2.readADC_SingleEnded(2);
  adc7 = ads2.readADC_SingleEnded(3);
  volts4 = ads2.computeVolts(adc4);
  volts5 = ads2.computeVolts(adc5);
  volts6 = ads2.computeVolts(adc6);
  volts7 = ads2.computeVolts(adc7);
  volts0 = volts0 * 5;
  volts1 = volts1 * 5;
  volts2 = volts2 * 5;
  volts3 = volts3 * 5;
  volts4 = volts4 * 5;
  volts5 = volts5 * 5;
  volts6 = volts6 * 5;
  volts7 = volts7 * 5;
  Serial.println(volts0);
  Serial.println(volts1);
  Serial.println(volts2);
  Serial.println(volts3);
  Serial.println(volts4);
  Serial.println(volts5);
  Serial.println(volts6);
  Serial.println(volts7);
}
