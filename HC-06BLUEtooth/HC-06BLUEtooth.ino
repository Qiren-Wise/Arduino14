char  serialData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available()>0)
     {
        serialData = Serial.read();

        if (serialData == '1')  //接收到点亮LED指令

         {
          Serial.print("Got command");Serial.println(serialData);
          Serial.println("LED-ON");

          digitalWrite(11,HIGH);
          }  else             //接收到熄灭LED指令
              {
                Serial.print("Got Command");
                Serial.println(serialData);
                Serial.println("LED-OFF");

                 digitalWrite(11,LOW);
                }
        
      }
    
}
