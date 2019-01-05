
#include <project.h>
#include <stdbool.h>

void send();
void update();

    uint8 ch;
    char8 testString;

    int16 Pot_1_Val;
    int16 Pot_2_Val;
    int16 Pot_3_Val;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //multiplexer for the three potentiometers. not enough ADC ports so using three ports and multiplexer
    Pot_Values_Start();
    ADC_SAR_1_Start();

    /* Start SCB UART TX+RX operation */
    UART_Start();
    
    //this will begin the process of checking to see if you move the arm 
    update();
}


void send(int16 valueArray[])
{
    //this will send the values everytime they change and then it'll send you back to checking
    uint8 sendArray[3];
    
    for(int i = 0; i<3;i++)
    {
        sendArray[i] = valueArray[i];
    }
    
    
    
    /* Transmit array of numbers through UART TX Line */
    //UART_PutArray(sendArray, 3);
    UART_PutString("123");
    //might wanna change this for loop into one that goes through only all of the bytes being sent
    for(;;)
    {
        ch = UART_GetChar();
        //update();
        if(0u != ch)
        {
           UART_PutChar(ch); 
        
          //go back to updating after this i guess? this might cut the connection short tho idk
            
        }
    }

}

void update()
{
    //this will always be updating and when you change the values it'll send them
    int16 valueArray[3];

    int16 temp2 = Pot_2_Val;
    int16 temp3 = Pot_3_Val;
    
    for(;;)
    {
    int16 temp1 = Pot_1_Val;
        
    Pot_Values_Select(0);
    CyDelay(25);
    ADC_SAR_1_StartConvert();
    ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
    Pot_1_Val = ADC_SAR_1_GetResult16();
    valueArray[0] = Pot_1_Val;
   /* 
    Pot_Values_Select(1);
    CyDelay(25);
    ADC_SAR_1_StartConvert();
    ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
    Pot_2_Val = ADC_SAR_1_GetResult16();
    valueArray[1] = Pot_2_Val;
    
    
    Pot_Values_Select(2);
    CyDelay(25);
    ADC_SAR_1_StartConvert();
    ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
    Pot_3_Val = ADC_SAR_1_GetResult16(); 
    valueArray[2] = Pot_3_Val;
    */
    //if(temp1 != Pot_1_Val || temp2 != Pot_2_Val || temp3 != Pot_3_Val)
    //{
        //check if any of the values have changed then send if yes
    int16 upperTolerance = 10;
    int16 lowerTolerance = -10;
    
    //if(Pot_1_Val != 0 && (Pot_1_Val < (temp1 + upperTolerance) && Pot_1_Val > (temp1 + lowerTolerance)))
    //{  
        send(valueArray);
    //}  
    
    //update all temps last
    temp1 = Pot_1_Val;
    temp2 = Pot_2_Val;
    temp3 = Pot_3_Val;
    
    }
    
}

/* [] END OF FILE */
