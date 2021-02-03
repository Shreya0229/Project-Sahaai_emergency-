const int buttonPin = 8;  
int buttonState = 0; 
int resval=0;      // the number of the LED pin
  int respin=A5;
String text1;
#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 13, 5, 4, 3, 2);
 int buzzer=11;

void setup() {

   pinMode(buttonPin, INPUT);

  // put your setup code here, to run once:

  Serial.begin(9600);

  analogWrite(6,Contrast);
     lcd.begin(16, 2);
  lcd.setCursor(0, 0);
      lcd.print("Project Sahaai");

     
      delay(200);
      

}

 

void loop() {
  buttonState = digitalRead(buttonPin);

 if (buttonState == HIGH) {
    // turn LED on:
        Serial.write("2\n");
  } 
 

  // put your main code here, to run repeatedly:
 resval=analogRead(respin);
 if (resval>=400)
 {Serial.write("1\n");
respin=0;
int i=0;
  do{
    
    i++;
    tone(buzzer, 450);
    delay(200);
    noTone(buzzer);
    delay(200);

    
  }while(i<3);



delay(2000);

}
  
 

 if (Serial.available())
  {
    text1=Serial.readString();
    Serial.println(text1);
    lcd.setCursor(0, 0);
     lcd.print(text1);
    if(Serial.read() == '\n'){              // if the last byte is 'd' then stop reading and execute command 'd' stands for 'done'
        Serial.flush();                     //clear all other commands piled in the buffer
        Serial.print('d');                   //send completion of the command
      lcd.setCursor(0, 0);
      lcd.print(text1);
      lcd.autoscroll();
     delay(200); 
     lcd.clear();
    }
  }
 
delay(200);

}
