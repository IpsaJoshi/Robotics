int x,y,z;

void setup() {
 // pinMode(A0,INPUT);pinMode(A1,INPUT);pinMode(A2,INPUT);
  Serial.begin(19200);
}

void loop() {
 x=analogRead(A0);
 y=analogRead(A1);
 z=analogRead(A2);
  
 Serial.print(" x= ");
 Serial.print(x);
 Serial.print(" y= ");
 Serial.print(y);
 Serial.print(" z= ");
 Serial.println(z);

 delay(100);
}
