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
  // put your setup code here, to run once:
  pinMode(SS, OUTPUT);
  SPI.begin();  //SPI 통신을 초기화한다.
  Serial.begin(9600);
  SD.begin(SS);
  digitalWrite(SS,LOW);
  SPI.setBitOrder(MSBFIRST); // 최상의 비트부터 전송 (기본값)
  SPI.setClockDivider(SPI_CLOCK_DIV16); // 클럭 속도 설정
}

void loop() {
  
  if(Serial.available()){
    char modeNum = Serial.read();

  switch(modeNum){
    case '1':
      SPI.endTransaction();
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
      FileRW(1);
      break;
    case '2':
      SPI.endTransaction();
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE1));
      FileRW(2);
      break;
    case '3':
      SPI.endTransaction();
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE2));
      FileRW(3);
      break;
    case '4':
      SPI.endTransaction();
      SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE3));
      FileRW(4);
      break;
  }
  }
}


void FileRW(int num){
  testF = SD.open("test.txt", FILE_WRITE);
  testF.println(num);
  testF.close();
  Serial.println("done.");
}
