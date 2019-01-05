int potentiometer1pin = 0;
int potentiometer2pin = 1;
int potentiometer3pin = 2;


int potVal1 = 0;
int potVal2 = 0;
int potVal3 = 0;

int potVals[3];

/* Serial port in LABVIEW is MXP TTL */

void setup()
{
                    /* The baud rate of our serial port is 9600, parity should be one and data bits is 8 */
                    Serial.begin(9600);
}


void loop()
{
                    
                    
                    /* Basically we're just gonna receive the potentiometer information and then send it to the serial port so we can use it in labview 
                   might have to turn this into one array that sends with headers inside of it also the for(;;) means for..EVER ;D*/
                   for(;;)
                   {
                                     
                    potVal1 = analogRead(potentiometer1pin);
                    potVal2 = analogRead(potentiometer2pin);
                    potVal3 = analogRead(potentiometer3pin);
                   
                   potVals[0] = ((potVal1-360)/2);
                   potVals[1] = ((potVal2-360)/2);
                   potVals[2] = ((potVal3-360)/2);

     
                    /* the serial write will send bytes of data to the serial port and our serial print will just print it out for us so we can see */
                    for(int i =0; i<4;i++)
                    {
                                        if(i==3){
                                        Serial.println(500);
                                        } else {
                                        Serial.println(potVals[i]); 
                                        }
                    }
                    

                    /* rip it goes way too fast so we need delays */
                    delay(300);
                           
                    }
}

