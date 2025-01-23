#include <SPI.h>

void setup() {
  SPI.begin();
  Serial.begin(9600);
  pinMode(SS,OUTPUT);
  digitalWrite(SS, HIGH); //슬레이브 선택 해제

}

void loop() {
  if(Serial.available()){
    char modeNum = Serial.read(); //윈폼에서 버튼을 클릭하여 전달된 문자
    Serial.print("윈폼에서 입력받은 데이터 : ");
    Serial.println(modeNum);
    switch(modeNum){
      case '0' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        //슬레이브에 데이터 수신
        SPITransferData();
        SPI.endTransaction();
        break;
      case '1' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        SPITransferData();
        SPI.endTransaction();
      case '2' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        SPITransferData();
        SPI.endTransaction();
      case '3' :
        SPI.beginTransaction(SPISettings(250000, MSBFIRST, SPI_MODE0));
        SPITransferData();
        SPI.endTransaction();
    }
  }

}

void SPITransferData(){
  digitalWrite(SS,LOW); //슬레이브 선택 핀을 LOW로 바꾸어 SPI 통신 선언
  char received = SPI.transfer(0);
  Serial.print("데이터는 : ");
  Serial.println(received);
  digitalWrite(SS,HIGH); //슬레이브 선택 핀을 HIGH로 바꾸어 통신 종료
}
