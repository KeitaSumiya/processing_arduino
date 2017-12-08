const int pinLED = 3;
int readByte = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop(){
  if (Serial.available() > 0) {
    readByte = Serial.read();
    Serial.println(readByte, DEC);
    if(readByte == 1){
      digitalWrite(pinLED,HIGH);
    }else{
      digitalWrite(pinLED,LOW);
    }

  }
}
