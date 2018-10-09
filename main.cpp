#include "mbed.h"

PwmOut red(PB_1);
PwmOut green(PE_8);
PwmOut blue(PE_14);
DigitalOut LED(PC_6);
int main() {
    float Value;
   int mode=0;
    red.period_ms(1); 
    green.period_ms(1); 
     blue.period_ms(1); 
   Value=100;
    blue.write(1);
    green.write(1);
    red.write(0);
    while(1) {
       LED=!LED;
       wait(0.01);
     
            switch (mode)
            {
       case 0:
       {
           red.write(Value/100);//Down
             green.write((100-Value)/100);//Up
             break;
           }
        case 1:   
          
           {
               green.write(Value/100);//Down
             blue.write((100-Value)/100);//Up
             break;
               }
         case 2:  {
               blue.write(Value/100);//down
               red.write((100-Value)/100);//up
             break;
               }
               
               }
            Value=Value-0.4;
        if (Value<0) {
            Value=100;  
            mode++;
            if (mode>2) mode=0;
            wait(1);
            }
        
      
    }
}
