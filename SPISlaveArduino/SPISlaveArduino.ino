#include <SPI.h>
byte sendData;

void setup() {
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);
  pinMode(MOSI,INPUT);
  pinMode(SCK,INPUT);
  pinMode(SS,INPUT);

  //SPI 통신을 위한 레지스터 설정
  SPCR |= _BV(SPE); // SPI 활성화
  SPCR &= ~_BV(MSTR); // Slave 모드 선택
  SPCR |= _BV(SPIE); // 인터럽트 허용
}

ISR (SPI_STC_vect){
  SPDR = sendData;
}

void loop() {
  if(Serial.available()){
    char modeNum = Serial.read(); // 윈폼에서 버튼을 클릭해서 전달된 문자
    switch(modeNum){
      case '0' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        //마스터에서 데이터 전송하기
        sendData = 0;
        SPI.endTransaction();
      case '1' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        sendData = 1;
        SPI.endTransaction();
      case '2' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        sendData = 2;
        SPI.endTransaction();
      case '3' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        sendData = 3;
        SPI.endTransaction();
    }
  }
}
