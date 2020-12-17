const int enco_i1 = 3, enco_d1 = 16;
int enc1=0; 

#define encd1 digitalRead(enco_d1)
#define enci1 digitalRead(enco_i1)
void setup() {
  
  pinMode(enco_d1,INPUT); pinMode(enco_i1,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3),encoder1,RISING);
  Serial.begin(115200);
}

void loop() {

  Serial.print("  enci1="); Serial.print(enci1);
  Serial.print("  encd1="); Serial.print(encd1);
   
  Serial.print("  enc1=");
  Serial.println(enc1);

}
