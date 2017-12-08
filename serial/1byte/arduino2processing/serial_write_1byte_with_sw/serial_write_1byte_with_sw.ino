const int pin = 2;
const int pinLED = 3;
int stateSW;

void setup(){
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(pinLED, OUTPUT);
  stateSW = 0;
}

void loop(){
  stateSW = digitalRead(pin);
  //Serial.println(stateSW);
  if(stateSW == 1){
    Serial.write(1);
    digitalWrite(pinLED,HIGH);
  }else{
    Serial.write(0);
    digitalWrite(pinLED,LOW);
  }
}
