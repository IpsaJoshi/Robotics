int x,y,z;
const int offset=396;   //Change this value accordingly
void setup() {
 // pinMode(A0,INPUT);pinMode(A1,INPUT);pinMode(A2,INPUT);
  Serial.begin(19200);
}

void loop() {

 z=analogRead(A2);
 z=z-offset;
 //Serial.println(z);
 switch(z)
 {
  case -2 ... 2: Serial.println(" No Vibration");break;
  default:Serial.println(" Vibration Detected");
 }
 delay(100);
}
