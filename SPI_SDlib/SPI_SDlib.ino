#include <SPI.h>
#include <SD.h>
/* 
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** SS - pin 4
 */
File testF;

void setup() {
  Serial.begin(9600);
  if(!SD.begin(4)){
    Serial.println("SD 초기화 실패");
  }
}

void loop() {
  
  if(Serial.available()){
    char modeNum = Serial.read();

  switch(modeNum){
    case '0':
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
      FileRW("test0.txt", modeNum);
      SPI.endTransaction();
      break;
    case '1':
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE1));
      FileRW("test1.txt", modeNum);
      SPI.endTransaction();
      break;
    case '2':
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE2));
      FileRW("test2.txt", modeNum);
      SPI.endTransaction();
      break;
    case '3':
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE3));
      FileRW("test3.txt", modeNum);
      SPI.endTransaction();
      break;
  }
  }
}


void FileRW(const char *file_name, char mode){
  testF = SD.open(file_name, FILE_WRITE);
  if(testF){
    testF.print("현재 모드는 : ");
    testF.println(mode);
    testF.close();
    Serial.println("done.");
  }
  else{
    Serial.println("실패");
  }

}
