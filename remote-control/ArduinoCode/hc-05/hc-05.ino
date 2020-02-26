#include <SoftwareSerial.h>
SoftwareSerial BTserial(8, 9); // RX | TX

char c = ' ';
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino with HC-05 is ready");
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 
void loop()
{
    //hc-06 > arduino
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c); //recv commands echo
    }
    //arduino > hc-06
    if (Serial.available())
    {
        c =  Serial.read();
        //Serial.write(c);//echo commands made   
        BTserial.write(c);  
    }
}
