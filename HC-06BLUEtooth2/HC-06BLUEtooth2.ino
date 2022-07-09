#include <SoftwareSerial.h>
SoftwareSerial BTserial(2,3);  // Tx  Rx 接ARDU
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);   //硬件串口波特率
   BTserial.begin(9600); //软件串口波特率

   Serial.print("HC-06 DEMO/TEST"); 

   BTserial.print("AT");        //连接成功发送

   pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
     if (BTserial.available()>0)
     {
        char BTserialData = BTserial.read();
        Serial.print(BTserialData);

        if (BTserialData == '1')
        {
            digitalWrite(11,HIGH);
            } else if(BTserialData == '0')
              {
                digitalWrite(11,LOW);
                }
      }
    if (Serial.available()>0)    //硬件串口中等待传输的数据
      {
        char serialData = Serial.read();
        BTserial.print( serialData);   //将硬件串口中的数据发送给HC-06
        }
     
}
