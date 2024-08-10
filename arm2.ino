#include <Servo.h>

Servo main1;
Servo boom;
Servo tool;
Servo base;

int bm = A4;
int mn = A5;
int end1 = A0;
int basep = A1;

int pos = 0;
int i = 0;
int j = 0;
int k = 0;
int l = 0;

#define Button1 2
#define Button2 3

void setup() {
  main1.attach(3);
  boom.attach(9);
  tool.attach(6);
  base.attach(11);

  main1.write(0);
  boom.write(0);
  tool.write(90);
  base.write(90);

  Serial.begin(9600);

  pinMode(mn, INPUT);
  pinMode(bm, INPUT);
  pinMode(end1, INPUT);
  pinMode(basep, INPUT);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(2,INPUT);

  main1.write(0);
  boom.write(0);
  tool.write(90);
  base.write(90);
}

void loop() {
  int bmval = analogRead(bm);
  int mnval = analogRead(mn);
  int end1val = analogRead(end1);
  int baseval = analogRead(basep);
  int b1val = digitalRead(Button1);
  int b2val = digitalRead(Button2);

  Serial.print(b1val);
  Serial.print(b2val);
  Serial.print("\t");
  Serial.print(i);
  Serial.print("\t");
  Serial.print(j);
  Serial.print("\t");
  Serial.print(k);
  Serial.print("\t");
  Serial.print(l);
  Serial.print("\t");
  Serial.print(bmval);
  Serial.print("\t");
  Serial.print(mnval);
  Serial.print("\t");
  Serial.print(end1val);
  Serial.print("\t");
  Serial.print(baseval);
  Serial.print("\n");

  //if (mnval < 150 && i < 180) {
  if (2==HIGH){
    i++;
    main1.write(i);
    delay(10);
  } else if (2==LOW) {
    i--;
    main1.write(i);
    delay(10);
  }

  if (bmval < 250 && j < 180) {
    j++;
    boom.write(j);
    delay(10);
  } else if (bmval > 700 && j > 0) {
    j--;
    boom.write(j);
    delay(10);
  }

  if (baseval < 150 && k < 180) {
    k++;
    base.write(k);
    delay(10);
  } else if (baseval > 700 && k > 0) {
    k--;
    base.write(k);
    delay(10);
  }

  if (end1val < 250 && l < 180) {
    l++;
    tool.write(l);
    delay(10);
  } else if (end1val > 700 && l > 0) {
    l--;
    tool.write(l);
    delay(10);
  }
}
