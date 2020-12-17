
const int trig=A3,echo=A4;
int duration,distance;  
void setup() {
  pinMode(trig,OUTPUT);pinMode(echo,INPUT);
  Serial.begin(19200);
  }

void loop() {
  

  digitalWrite(trig,HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);//10000 //timeout is the microsec time for how long echo waits for waves to be pulsedin default is
                                        //1 sec,by reducing it range can be decresed.
  distance = duration * 0.017;
  Serial.println(distance);
  
}
