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
        SPI.endTransaction();
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        FileRW(1);
        break;
      case '1':
        SPI.endTransaction();
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE1));
        FileRW(2);
        break;
      case '2':
        SPI.endTransaction();
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE2));
        FileRW(3);
        break;
      case '3':
        SPI.endTransaction();
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE3));
        FileRW(4);
        break;
    }
  }
}

void FileRW(int num){
  testF.open("test.txt", FILE_WRITE);
  testF.println(num);
  testF.close();
  Serial.println("done");
}
