#include "T3.h"

void tache3()
{

    while (PIR1bits.TX1IF==0);   TXREG1=' ';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='3';while (TXSTA1bits.TRMT==0);
    
    while(1)
    {
        //P(SEM_RXTX);
        //while(RXTX_libre==0);
        //RXTX_libre=0;
        //while (PIR1bits.TX1IF==0);   TXREG1='T';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='A';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='H';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='3';while (TXSTA1bits.TRMT==0);
        
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='N';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='O';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='U';while (TXSTA1bits.TRMT==0);
       // while (PIR1bits.TX1IF==0);   TXREG1='R';while (TXSTA1bits.TRMT==0);
       // while (PIR1bits.TX1IF==0);   TXREG1='S';while (TXSTA1bits.TRMT==0);
        //RXTX_libre=1;
        //V(SEM_RXTX);
        
        
        if (TP_appui==1)
        {
            if ((TP_x>=203))
            {
                if ((TP_y>=203))
                {
                    LED_R=1;
                }
                if ((TP_y<50))
                {
                    LED_R=0;
                }
            }
        }
        if (TP_appui==1)
        {
            if ((TP_x>=110)&&(TP_y<130))
            {
                if ((TP_y>=203))
                {
                    LED_G=1;
                }
                if ((TP_y<50))
                {
                    LED_G=0;
                }
            }
        }
        if (TP_appui==1)
        {
            if ((TP_x<50))
            {
                if ((TP_y>=203))
                {
                    LED_B=1;
                }
                if ((TP_y<50))
                {
                    LED_B=0;
                }
            }
        }
    }
}