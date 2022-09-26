



#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);


int S1 = 2;
int S2 = 3;
int S3 = 4;
int S4 = 5;
int S5 = 6;
int S6 = 7;
int sys_t = 8;
int sys_p = 9;
int d10 = 10;
int d11 = 11;
int d12 = 12;
int d13 = 13;
int var = 0;
int x = 0;


void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(sys_t, OUTPUT);
  pinMode(sys_p, OUTPUT);
  pinMode(d10, INPUT_PULLUP);
  pinMode(d11, INPUT_PULLUP);
  pinMode(d12, INPUT_PULLUP);
  pinMode(d13, INPUT_PULLUP);
  delay(500);
  digitalWrite(sys_p, HIGH);
  lcd.init();
  lcd.init();
  lcd.backlight();

  /* I2C Adress Selection  */
  if (d10 == LOW) {
    x = 2;
  }
  else if (d11 == LOW) {
    x = 3;
  }
  else if (d12 == LOW) {
    x = 4;
  }
  else if (d13 == LOW) {
    x = 5;
  }
  else if (d10 == LOW && d11 == LOW) {
    x = 6;
  }
  else if (d10 == LOW && d12 == LOW) {
    x = 7;
  }
  else if (d10 == LOW && d13 == LOW) {
    x = 8;
  }
  else if (d11 == LOW && d12 == LOW) {
    x = 9;
  }
  else if (d11 == LOW && d13 == LOW) {
    x = 10;
  }
  else if (d12 == LOW && d13 == LOW) {
    x = 11;
  }
  else if (d10 == LOW && d11 == LOW && d12 == LOW && d13 == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid Address");

    while (var < 4) {
      digitalWrite(sys_t, HIGH);
      delay(1000);
      digitalWrite(sys_t, LOW);
      var++;
    }

  }
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

void requestEvent() {
  Wire.begin(x);
  digitalRead(S1);
  digitalRead(S2);
  digitalRead(S3);
  digitalRead(S4);
  digitalRead(S5);
  digitalRead(S6);

  if (S1 == HIGH || S2 == HIGH || S3 == HIGH || S4 == HIGH || S5 == HIGH || S6 == HIGH) {
    Wire.write("FIRE");
    if (S1 == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected");
      lcd.setCursor(7, 1);
      lcd.print("Zone 1");

    }

    if (S2 == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected");
      lcd.setCursor(7, 1);
      lcd.print("Zone 2");
    }

    if (S3 == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected");
      lcd.setCursor(7, 1);
      lcd.print("Zone 3");

    }

    if (S4 == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected");
      lcd.setCursor(7, 1);
      lcd.print("Zone 4");

    }
    if (S5 == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected");
      lcd.setCursor(7, 1);
      lcd.print("Zone 5");

    }

    if (S6 == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire Detected");
      lcd.setCursor(7, 1);
      lcd.print("Zone 6");

    }
  }
  else {
    Wire.write("");
    if (S1 && S2 && S3 && S4 && S5 && S6 == LOW) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No Fire Detected");
      lcd.setCursor(6, 1);
      lcd.print("System OK");
      Wire.write("");
    }
  }
}
