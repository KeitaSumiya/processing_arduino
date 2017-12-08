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

