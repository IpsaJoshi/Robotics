const int enco_i1 = 2, enco_d1 = 17;
int enc1=0,f=0,dir; 

#define encd1 digitalRead(enco_d1)
#define enci1 digitalRead(enco_i1)
void setup() {
  
  pinMode(enco_d1,INPUT); pinMode(enco_i1,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),encoder1,CHANGE);
  Serial.begin(115200);
}

void loop() {
  if(enci1==0 && f==0)f=1;
   else if(enci1==1 && f==1)
  {
    if(encd1==0)dir=1;
    else dir=-1;
    f=0; 
  }
  Serial.print("  dir=");
  Serial.print(dir);
  
  Serial.print("  enc1=");
  Serial.println(enc1);
}
