https://qiita.com/keitasumiya/items/f70ff0b51a86555e21c0

## arduino > processing
https://youtu.be/FydeVeVlqkw

## processing > arduino
https://youtu.be/ty6ImOZLEP4


# 1 byte
## settings
```
pin 2 : SW (release:OFF / push:ON)
pin 3 : LED
```

![setting.png](https://qiita-image-store.s3.amazonaws.com/0/102253/2b6b3c16-abdb-fea3-1d54-39232039c372.png)

![setting-photo.jpg](https://qiita-image-store.s3.amazonaws.com/0/102253/48aa86b3-0e50-5e5f-c249-325c8d8797f4.jpeg)


## arduino > processing
https://youtu.be/FydeVeVlqkw

```serial_write_1byte_with_sw.ino
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
```

```serial_read_1byte.pde
import processing.serial.*;

Serial myPort;       

//user definitions
String COM_PORT="/dev/tty.usbmodem1421"; //change this!
int myByte = 0;

void setup(){
  size(400,400);
  //printArray(Serial.list());
  //myPort = new Serial(this, Serial.list()[2], 9600);
  myPort = new Serial(this, COM_PORT, 9600);

}

void draw(){
  background(255);
  while (myPort.available() > 0) {
    myByte = myPort.read();
    println(myByte);
    
    if(myByte == 1){
      background(0);
      fill(255);
      ellipse(200, 200, 100, 100);
    }
  }
}
```

## processing > arduino
https://youtu.be/ty6ImOZLEP4

```serial_read_1byte_led.ino
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
```

```serial_write_1byte.pde
import processing.serial.*;

Serial myPort;       
String COM_PORT="/dev/tty.usbmodem1421"; //change this!
int value = 0;

void setup(){
  size(400,400);
  //printArray(Serial.list());
  //myPort = new Serial(this, Serial.list()[2], 9600);
  myPort = new Serial(this, COM_PORT, 9600);
}

void draw(){
  background(255);
    
  if (keyPressed) {
    if (key == 'b') {
      value = 1;
      background(0);
      fill(255);
      ellipse(200, 200, 100, 100);
    }
  }else{
    value = 0;
  }
  myPort.write(value);
}

```