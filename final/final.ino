#include <Keypad.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#include <stdlib.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void clock(int hr,int mn,int sc);
void alarm(int h,int m);
int led = 13;
int time[12];
int i=0,temp,AP,hr,mn,sc,alarmhr,alarmmn,s,milisec=0,a=0,b=0,c=0,am,APM=0;
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
// Define the Keymap
char keys[ROWS][COLS] = {
{'D','C','B','A'},
{'#','9','6','3'},
{'0','8','5','2'},
{'*','7','4','1'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };

boolean blink = false;

enum state {WAITING, LOOPING, HOLDING} current_state=HOLDING;

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void alarm(int h,int m,int s,int apm)
{
  if((alarmhr==h) && (alarmmn==m) && (s==0) && (APM==apm))
  {
      lcd.setCursor(7,0);
      lcd.print(" ");
      lcd.setCursor(9,0);
      if(apm=1)
      {
        lcd.print("AM");  
      }  
      else if(apm=2)
      {
        lcd.print("PM");  
      }  
      for(i=1;i<=5;i++)
      {
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);               // wait for a second
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);               // wait for a second
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);               // wait for a second
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);               // wait for a second
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);               // wait for a second
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
        lcd.setCursor(7,0);
        lcd.print(i);  
      }
      sc=5;
  }
}
void setup()
{
      pinMode(led, OUTPUT);    
      Serial.begin(9600);
      lcd.begin(16, 2);
      keypad.addEventListener(keypadEvent);
      lcd.setCursor(0,0);
      lcd.print("A for Settings");      
      lcd.setCursor(0,1);
      lcd.print("# for Timer");
      //lcd.setCursor(0,0);
}


void loop(){
     char key = keypad.getKey();
     if (key != NO_KEY)
     {
        Serial.println(key);
     }
     switch(current_state) 
     {
       case HOLDING:
       break;
        case WAITING:
                      
                      lcd.setCursor(0,1);
                      lcd.print("Timer Started !!");
                      
                      if(hr <=9)
                      {
                       
                        lcd.setCursor(0,0);
                        lcd.print(0);
                        lcd.setCursor(1,0);
                        lcd.print(hr);
                      }
                      else
                      {
                        
                        lcd.setCursor(0,0);
                        lcd.print(hr); 
                      }
                      lcd.setCursor(2,0);
                      lcd.print(":");
                      if (mn <=9)
                      {
                        
                        lcd.setCursor(3,0);
                        lcd.print(0);
                        lcd.setCursor(4,0);
                        lcd.print(mn);
                      }
                      else
                      {
                         
                        lcd.setCursor(3,0);
                        lcd.print(mn);
                      }
                      lcd.setCursor(5,0);
                      lcd.print(":");
                      if (sc <=9)
                      {
                        
                        lcd.setCursor(6,0);
                        lcd.print(0);
                        lcd.setCursor(7,0);
                        lcd.print(sc);
                      }
                      else
                      {
                        
                        lcd.setCursor(6,0);
                        lcd.print(sc);
                      }
                      lcd.setCursor(8,0);
                      lcd.print(":");
                      if(milisec <=9)
                      {
                         
                        lcd.setCursor(9,0);
                        lcd.print(0);
                        lcd.setCursor(10,0);
                        lcd.print(milisec);
                      }
                      else
                      {
                       
                        lcd.setCursor(9,0);
                        lcd.print(milisec);      
                      }
                      
                      ////////////////////////////////////////////////////clock counting code starts
                      delay(86);//////NOT 100....tested with a clock side by side.
                      milisec++;
                      if((sc==59)&&(mn==59)&&(hr==12)&&(milisec==10))
                      {
                        
                        hr=1;
                        mn=0;
                        sc=0;
                        milisec=0;
                        lcd.clear();
                        //delay(1); Dont know why mayor has written this 
                        if(hr <=9)
                        {
                          
                          lcd.setCursor(0,0);
                          lcd.print(0);
                          lcd.setCursor(1,0);
                          lcd.print(hr);
                        }
                        else
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(hr); 
                        }
                        lcd.setCursor(2,0);
                        lcd.print(":");
                        if (mn <=9)
                        {
                           
                          lcd.setCursor(3,0);
                          lcd.print(0);
                          lcd.setCursor(4,0);
                          lcd.print(mn);
                        }
                        else
                        {
                           
                          lcd.setCursor(3,0);
                          lcd.print(mn);
                        }
                        lcd.setCursor(5,0);
                        lcd.print(":");
                        if (sc <=9)
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(0);
                          lcd.setCursor(7,0);
                          lcd.print(sc);
                        }
                        else
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(sc);
                        }
                        lcd.setCursor(8,0);
                        lcd.print(":");
                        if(milisec <=9)
                        {
                          
                          lcd.setCursor(9,0);
                          lcd.print(0);
                          lcd.setCursor(10,0);
                          lcd.print(milisec);
                        }
                        else
                        {
                           
                          lcd.setCursor(9,0);
                          lcd.print(milisec);      
                        }
                      }
                      else if((sc==59)&&(mn==59)&&(milisec==10))
                      {
                         
                        hr++;
                        mn=0;
                        sc=0;
                        milisec=0;
                        lcd.clear();
                        //delay(1);
                        if(hr <=9)
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(0);
                          lcd.setCursor(1,0);
                          lcd.print(hr);
                        }
                        else
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(hr); 
                        }
                        lcd.setCursor(2,0);
                        lcd.print(":");
                        if (mn <=9)
                        {
                           
                          lcd.setCursor(3,0);
                          lcd.print(0);
                          lcd.setCursor(4,0);
                          lcd.print(mn);
                        }
                        else
                        {
                           
                          lcd.setCursor(3,0);
                          lcd.print(mn);
                        }
                        lcd.setCursor(5,0);
                        lcd.print(":");
                        if (sc <=9)
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(0);
                          lcd.setCursor(7,0);
                          lcd.print(sc);
                        }
                        else
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(sc);
                        }
                        lcd.setCursor(8,0);
                        lcd.print(":");
                      if(milisec <=9)
                      {
                        
                        lcd.setCursor(9,0);
                        lcd.print(0);
                        lcd.setCursor(10,0);
                        lcd.print(milisec);
                      }
                        else
                        {
                           
                          lcd.setCursor(9,0);
                          lcd.print(milisec);      
                        }
                      }
                      else if((sc==59)&&(milisec==10))////////////////////////////////////////////////////////////
                      {
                        
                        mn++;
                        sc=0;
                        milisec=0;
                        lcd.clear();
                        // delay(1);
                        if(hr <=9)
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(0);
                          lcd.setCursor(1,0);
                          lcd.print(hr);
                        }
                        else
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(hr); 
                        }
                        lcd.setCursor(2,0);
                        lcd.print(":");
                        if (mn <=9)
                        {
                          
                          lcd.setCursor(3,0);
                          lcd.print(0);
                          lcd.setCursor(4,0);
                          lcd.print(mn);
                        }
                        else
                        {
                         
                          lcd.setCursor(3,0);
                          lcd.print(mn);
                        }
                        lcd.setCursor(5,0);
                        lcd.print(":");
                        if (sc <=9)
                        {
                          
                          lcd.setCursor(6,0);
                          lcd.print(0);
                          lcd.setCursor(7,0);
                          lcd.print(sc);
                        }
                        else
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(sc);
                        }
                        lcd.setCursor(8,0);
                        lcd.print(":");
                      if(milisec <=9)
                      {
                         
                        lcd.setCursor(9,0);
                        lcd.print(0);
                        lcd.setCursor(10,0);
                        lcd.print(milisec);
                      }
                        else
                        {
                           
                          lcd.setCursor(9,0);
                          lcd.print(milisec);      
                        }
                      }
                      else if(milisec==10)////////////////////////////////////////////////////////////
                      {
                        sc++;
                        milisec=0;
                        lcd.clear();
                        // delay(1);
                        if(hr <=9)
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(0);
                          lcd.setCursor(1,0);
                          lcd.print(hr);
                        }
                        else
                        {
                           
                          lcd.setCursor(0,0);
                          lcd.print(hr); 
                        }
                        lcd.setCursor(2,0);
                        lcd.print(":");
                        if (mn <=9)
                        {
                          
                          lcd.setCursor(3,0);
                          lcd.print(0);
                          lcd.setCursor(4,0);
                          lcd.print(mn);
                        }
                        else
                        {
                           
                          lcd.setCursor(3,0);
                          lcd.print(mn);
                        }
                        lcd.setCursor(5,0);
                        lcd.print(":");
                        if (sc <=9)
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(0);
                          lcd.setCursor(7,0);
                          lcd.print(sc);
                        }
                        else
                        {
                           
                          lcd.setCursor(6,0);
                          lcd.print(sc);
                        }
                        lcd.setCursor(8,0);
                        lcd.print(":");
                      if(milisec <=9)
                      {
                         
                        lcd.setCursor(9,0);
                        lcd.print(0);
                        lcd.setCursor(10,0);
                        lcd.print(milisec);
                      }
                      else
                      {
                         
                        lcd.setCursor(9,0);
                        lcd.print(milisec);      
                      }
                  
                      }
        // outside of loop, do nothing
          break;
        case LOOPING:
                   lcd.setCursor(0,1);
                   lcd.print("# for Timer");
                   if(AP==1)
                   {
                     lcd.setCursor(9,0);
                     lcd.print("AM");
                   }
                   else if(AP==2)
                   {
                     lcd.setCursor(9,0);
                     lcd.print("PM");
                   }
                   ////////////////////////////////////////////////////////
                   if(hr <=9)
    {
      lcd.setCursor(0,0);
      lcd.print(0);
      lcd.setCursor(1,0);
      lcd.print(hr);
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print(hr); 
    }
    lcd.setCursor(2,0);
    lcd.print(":");
    if (mn <=9)
    {
      lcd.setCursor(3,0);
      lcd.print(0);
      lcd.setCursor(4,0);
      lcd.print(mn);
    }
    else
    {
      lcd.setCursor(3,0);
      lcd.print(mn);
    }
    lcd.setCursor(5,0);
    lcd.print(":");
    if (sc <=9)
    {
      lcd.setCursor(6,0);
      lcd.print(0);
      lcd.setCursor(7,0);
      lcd.print(sc);
    }
    else
    {
      lcd.setCursor(6,0);
      lcd.print(sc);
    }
    
    delay(1000);
    sc++;
    alarm(hr,mn,sc,AP);
    if((sc==60)&&(mn==59)&&(hr==12))
    {
      hr=1;
      mn=0;
      sc=0;
      lcd.clear();
      //delay(1); Dont know why mayor has written this 
      if(hr <=9)
      {
        lcd.setCursor(0,0);
        lcd.print(0);
        lcd.setCursor(1,0);
        lcd.print(hr);
      }
      else
      {
        lcd.setCursor(0,0);
        lcd.print(hr); 
      }
      lcd.setCursor(2,0);
      lcd.print(":");
      if (mn <=9)
      {
        lcd.setCursor(3,0);
        lcd.print(0);
        lcd.setCursor(4,0);
        lcd.print(mn);
      }
      else
      {
        lcd.setCursor(3,0);
        lcd.print(mn);
      }
      lcd.setCursor(5,0);
      lcd.print(":");
      if (sc <=9)
      {
        lcd.setCursor(6,0);
        lcd.print(0);
        lcd.setCursor(7,0);
        lcd.print(sc);
      }
      else
      {
        lcd.setCursor(6,0);
        lcd.print(sc);
      }
      alarm(hr,mn,sc,AP);
    }
    else if((sc==60)&&(mn==59))
    {
      hr++;
      mn=0;
      sc=0;
      lcd.clear();
      //delay(1);
      if(hr <=9)
      {
        lcd.setCursor(0,0);
        lcd.print(0);
        lcd.setCursor(1,0);
        lcd.print(hr);
      }
      else
      {
        lcd.setCursor(0,0);
        lcd.print(hr); 
      }
      lcd.setCursor(2,0);
      lcd.print(":");
      if (mn <=9)
      {
        lcd.setCursor(3,0);
        lcd.print(0);
        lcd.setCursor(4,0);
        lcd.print(mn);
      }
      else
      {
        lcd.setCursor(3,0);
        lcd.print(mn);
      }
      lcd.setCursor(5,0);
      lcd.print(":");
      if (sc <=9)
      {
        lcd.setCursor(6,0);
        lcd.print(0);
        lcd.setCursor(7,0);
        lcd.print(sc);
      }
      else
      {
        lcd.setCursor(6,0);
        lcd.print(sc);
      }
      alarm(hr,mn,sc,AP);
    }
    else if(sc==60)
    {
      mn++;
      sc=0;
      lcd.clear();
      // delay(1);
      if(hr <=9)
      {
        lcd.setCursor(0,0);
        lcd.print(0);
        lcd.setCursor(1,0);
        lcd.print(hr);
      }
      else
      {
        lcd.setCursor(0,0);
        lcd.print(hr); 
      }
      lcd.setCursor(2,0);
      lcd.print(":");
      if (mn <=9)
      {
        lcd.setCursor(3,0);
        lcd.print(0);
        lcd.setCursor(4,0);
        lcd.print(mn);
      }
      else
      {
        lcd.setCursor(3,0);
        lcd.print(mn);
      }
      lcd.setCursor(5,0);
      lcd.print(":");
      if (sc <=9)
      {
        lcd.setCursor(6,0);
        lcd.print(0);
        lcd.setCursor(7,0);
        lcd.print(sc);
      }
      else
      {
        lcd.setCursor(6,0);
        lcd.print(sc);
      }
      alarm(hr,mn,sc,AP);
    }
                   ///\\\\\\\\\\\\\\\\\\\     
               
        // set some parameters.  this set of code will be processed until no longer
        // LOOPING, as set by the keyPadEvent.
          break;
     }    
}

void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    lcd.setCursor(0,0);
    case PRESSED:
        if(key== '*')
        {
          current_state=LOOPING;
          hr=a+hr;
          mn=b+mn;
          sc=c+sc;
          delay(2000);
          sc=sc+2;
          lcd.clear();
        }
        if(key== '#')
        {
          a=hr;
          b=mn;
          c=sc;
          Serial.println(hr);
          Serial.println(mn);
          Serial.println(sc);
          hr=mn=sc=0;
          current_state=WAITING;
          lcd.clear();
        }
        if(key =='A')
        {
         lcd.clear();
         delay(100);   
         lcd.print("Enter Hour");
        } 
        if(key == '0')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=0;
          i++;
        }
        if(key == '1')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=1;
          i++;
        }
        if(key=='2')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=2;
          i++;
        }
        if(key=='3')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=3;
          i++;
        }
        if(key=='4')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=4;
          i++;
        }
        if(key=='5')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=5;
          i++;
        }
        if(key=='6')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=6;
          i++;
        }
        if(key=='7')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=7;
          i++;
        }
        if(key=='8')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=8;
          i++;
        }
        if(key=='9')
        {
          lcd.clear();
          delay(100); 
          lcd.print(key);
          time[i]=9;
          i++;
        }
        if(key=='B')
        {
            lcd.clear();
            delay(100);
            lcd.print("Enter alarm hr");
        }
        if(key=='C')
        {
            temp=time[0]*10;
            hr=temp+time[1];
        
            temp=time[2]*10;
            mn=temp+time[3];
        
            temp=time[4]*10;
            sc=temp+time[5];
            AP=time[6];
            time[7]=time[8]=time[9]=time[10]=0;
            
            lcd.clear();
            delay(100);
            //clock(hr,mn,sc);
            current_state=LOOPING;
        }
        if(key=='D')
        {
          if(i==1)
          {
            time[i]=time[0];
            time[0]=0;
            i=2;
            lcd.clear();
            delay(100);
            lcd.print("Enter minute");
          }
          else if(i==2)
          {
            lcd.clear();
            delay(100);
            lcd.print("Enter minute");
          }
          else if(i==3)
          {
            time[i]=time[2];
            time[2]=0;
            i=4;
            lcd.clear();
            delay(100);
            lcd.print("Enter second");
          }
          else if(i==4)
          {
            lcd.clear();
            delay(100);
            lcd.print("Enter second");
          }
          else if(i==5)
          {
            time[i]=time[4];
            time[4]=0;
            i=6;
            lcd.clear();
            delay(100);
            lcd.print("AM=1 / PM=2");            
          }
          else if(i==6)
          {
            lcd.clear();
            delay(100);
            lcd.print("AM=1 / PM=2");
          }
          else if(i==7)
          {
            lcd.clear();
            delay(100);
            lcd.setCursor(0,0);
            lcd.print("Alarm? Y/N");
            lcd.setCursor(0,1);
            lcd.print("B=YES / C=NO");
          }
          else if(i==8)
          {
            time[i]=time[7];
            time[7]=0;
            i=9;
            lcd.clear();
            delay(100);
            lcd.print("Enter Mn");            
          }
          else if(i==9)
          {
            lcd.clear();
            delay(100);
            lcd.print("Enter Mn");      
          }
          else if(i==10)
          {
            
            time[i]=time[9];
            time[9]=0;
            i=11;
            lcd.clear();
            delay(100);
            lcd.print("AM=1 / PM=2");           
          }
           else if(i==11)
          {
            lcd.clear();
            delay(100);
            lcd.print("AM=1 / PM=2"); 
          }
          else if(i==12)
          {
            ///Serial.println("i=12");
            temp=time[0]*10;
            hr=temp+time[1];
        
            temp=time[2]*10;
            mn=temp+time[3];
        
            temp=time[4]*10;
            sc=temp+time[5];
            
            AP=time[6];
            temp=time[7]*10;
            alarmhr=temp+time[8];
           
            temp=time[9]*10;
            alarmmn=temp+time[10];
            
            APM=time[11];
            Serial.println("APM");
            Serial.println(APM);
            current_state=LOOPING;          
        }
        
        break;

    case RELEASED:
        
        break;

    case HOLD:
        
        break;
    case IDLE:
      break;
    }
}
}
