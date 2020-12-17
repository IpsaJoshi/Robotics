#define photo 41
#define pleg digitalRead(photo)
void setup() {
  pinMode(photo,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  Serial.print("photo=");
  Serial.println(pleg);
}
