#include "T6.h"

void tache6()
{
    unsigned char n;    
    

    while (PIR1bits.TX1IF==0);   TXREG1=' ';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='6';while (TXSTA1bits.TRMT==0);   
    
    while(1)
    {
        
        while (PIR1bits.TX1IF==0);   TXREG1='f';while (TXSTA1bits.TRMT==0);
        //P(SEM_RXTX);
        //while(RXTX_libre==0);
        //RXTX_libre=0;
       // while (PIR1bits.TX1IF==0);   TXREG1='T';while (TXSTA1bits.TRMT==0);
       // while (PIR1bits.TX1IF==0);   TXREG1='A';while (TXSTA1bits.TRMT==0);
       // while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='H';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);

       // while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='N';while (TXSTA1bits.TRMT==0);
       // while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
       // while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='O';while (TXSTA1bits.TRMT==0);
       //while (PIR1bits.TX1IF==0);   TXREG1='U';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='R';while (TXSTA1bits.TRMT==0);
       //while (PIR1bits.TX1IF==0);   TXREG1='S';while (TXSTA1bits.TRMT==0);
        //RXTX_libre=1;
        //V(SEM_RXTX);
        
        n=lecture_normale(badge);
        if (n>0)
        {
            if(n<10)
            {
                n_octet_badge=n;
            }
            else
            {
                n_octet_badge=0;
            }
        }
        else
        {
            n_octet_badge=0;
        }

    }
}
