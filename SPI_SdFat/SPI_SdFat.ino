#include <SdFat.h>
#include <SPI.h>
SdFat sd;
File testF;

/*
 * VCC - pin 3.3V
 * MISO - pin 12
 * MOSI - pin 11
 * SCK - pin 13
 * CS(SS) - pin 10
 * RED - pin 6
 * GREEN - pin 5
 * BLUE - pin 3
 */

void setup() {
  SPI.begin();
  Serial.begin(9600);
  
}

void loop() {
  if(Serial.available()){
    char modeNum = Serial.read();

    switch(modeNum){
      case '0':
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        FileRW(1);
        SPI.endTransaction();
        break;
      case '1':
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE1));
        FileRW(2);
        SPI.endTransaction();
        break;
      case '2':
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE2));
        FileRW(3);
        SPI.endTransaction();
        break;
      case '3':
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE3));
        FileRW(4);
        SPI.endTransaction();
        break;
    }
  }
}

void FileRW(int num){
  testF.open("test.txt", FILE_WRITE);
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  testF.println(num);
  testF.flush();
  testF.close();
  Serial.println("done");
}
