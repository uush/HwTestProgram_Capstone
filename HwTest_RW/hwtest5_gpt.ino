#include <SPI.h>
#include <SD.h>
File dataFile;
int Red = 6;
int Green = 5;
int Blue = 3;

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  Serial.begin(9600);
  SD.begin(SS);
  SPI.setClockDivider(SPI_CLOCK_DIV2); // 클럭 속도 설정
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char modeNum = Serial.read();

  switch(modeNum){
    case '1':
      SPI.setDataMode(SPI_MODE0);
      FileRW(); 
      break;
    case '2':
      SPI.setDataMode(SPI_MODE1); // 1번 통신 안됨
      FileRW();
      break;
    case '3':
      SPI.setDataMode(SPI_MODE2); // 2번 통신 안됨
      FileRW();
      break;
    case '4':
      SPI.setDataMode(SPI_MODE3);
      FileRW();
      break;
  }
  }
}

void FileRW(){
  dataFile = SD.open("data.txt", FILE_WRITE); // dataFile 초기화
  if(dataFile){
    dataFile.println("Hello, world!");
    dataFile.close();
    Serial.println("File Writing is complete");

    digitalWrite(Green, HIGH);
    delay(1000);
    digitalWrite(Green, LOW);

    dataFile = SD.open("data.txt"); //읽기모드
    if(dataFile){
      Serial.println("File Reading\n");
      while(dataFile.available()){
          Serial.print(dataFile.read());
      }
      dataFile.close();
    }

    digitalWrite(Red, HIGH);
    delay(1000);
    digitalWrite(Red, LOW);
  }
}
