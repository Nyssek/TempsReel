#include "T1.h"

void tache1()
{
         
    unsigned char i;

    di();
    initialisation_des_ports();
    initialisation_afficheur();
    clear_text();
    clear_graphics();
    init_rxtx();
    Init(SEM_RXTX);
    Init(SEM_CAN);
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;

    vitesse=0;
    batterie=50;
    n_octet_badge=0;

    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');

    TP_appui=0;
    
 
    while (PIR1bits.TX1IF==0);   TXREG1=' ';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='1';while (TXSTA1bits.TRMT==0);
    
while(1)
    {

    if (n_octet_badge==0)
        {goto_lico(0,0);draw_string(" ARRET : Pas ou mauvais badge         ");ClearLcd();}
    else 
    {
        //P(SEM_RXTX);
        //while(RXTX_libre==0);
        //RXTX_libre=0;
        //while (PIR1bits.TX1IF==0);   TXREG1='T';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='A';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='H';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='a';while (TXSTA1bits.TRMT==0);
        
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='N';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='O';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='U';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='R';while (TXSTA1bits.TRMT==0);
        //while (PIR1bits.TX1IF==0);   TXREG1='S';while (TXSTA1bits.TRMT==0);
        //RXTX_libre=1;
        //V(SEM_RXTX);

        Temp_Eau = lecture_8bit_analogique(TEMPERATURE_EAU)*130/256;
        Temp_Huile = lecture_8bit_analogique(TEMPERATURE_HUILE)*130/256;
        
        goto_lico(0,0);
        draw_string("Marche:");
        if (MARCHE_AVANT==0)
            draw_string("AV");
        else
            if (MARCHE_ARRIERE==0)
                draw_string("AR");
            else
                draw_string("N                             ");

        goto_lico(1,0);
        draw_string("Siege:");
        if (SIEGE==0)
        {draw_char('1');}
        else
        {draw_char('0');}

        goto_lico(2,0);
        draw_string("Temp. Eau: ");
        if (Temp_Eau>99)
            draw_decimal_100(Temp_Eau);
        else
            {
            if (Temp_Eau>9)
            {draw_string(" ");draw_decimal_10(Temp_Eau);}
            
            else  
            {draw_string("  ");draw_decimal_1(Temp_Eau);}
            }
        draw_string(" Degre ");
        
        
        goto_lico(3,0);
        draw_string("Temp. Huile: ");
                if (Temp_Huile>99)
            draw_decimal_100(Temp_Huile);
        else
            {
            if (Temp_Huile>9)
            {draw_string(" ");draw_decimal_10(Temp_Huile);}
            
            else  
            {draw_string("  ");draw_decimal_1(Temp_Huile);}
            }
        draw_string(" Degre ");

        goto_lico(4,0);
        draw_string("Choc:");
        if (CHOC==0) //Choc
            draw_char('1');
        else // Pas de choc
            draw_char('0');

        goto_lico(5,0);
        draw_string("Vitesse:");
        if (VITESSE_PLUS==0)
            vitesse++;
        if (VITESSE_MOINS==0)
            vitesse--;
        draw_hex8(vitesse);

        goto_lico(6,0);
        
        draw_string("Batterie:");
        
        if ((BATTERIE_PLUS==0)&&(batterie<100))
            batterie++;
        
        if ((BATTERIE_MOINS==0)&&(batterie>0))
            batterie--;
        if (batterie==100)
            draw_string("100% Batterie pleine");
        else
        {
            draw_decimal_10(batterie);
            draw_string("%                   ");
        }

        goto_lico(7,0);
        if (FREIN_A_MAIN==0)
            draw_string("((!))");
        else
            draw_string("     ");

        goto_lico(8,0);
        draw_string("Badge:");
        if (n_octet_badge==0)
            draw_string(" AUCUN              ");
        else
        {
            for (i=0;i<n_octet_badge;i++)
            {
                draw_hex8(badge[i]);
            }
        }

        goto_lico(9,0);
        draw_string("X-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_X));

        goto_lico(10,0);
        draw_string("Y-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_Y));

        if (TP_appui==1)
        {
            goto_lico(0,20);
            draw_string("x=");
            draw_hex8(TP_x);
            draw_string(" y=");
            draw_hex8(TP_y);
            plot1(TP_x,TP_y);
        }
        else
        {
            Nop();
        }
        
    if (CHOC==0) // Choc
    {
        goto_lico(12,0);
        draw_string(" ARRET : CHOC              ");
        goto_lico(14,0);
        draw_string(" Alarm CHOC !            ");
        ChocFlag = 84;
        

    }
                    
    if (ChocFlag==1) //Initialisé à 0
    {
        goto_lico(14,0);
        draw_string("                     ");
        ChocFlag=0;
    }
    if (ChocFlag>1)
        ChocFlag--;
  
    
            goto_lico(12,0);
            if (SIEGE==1)
            {
                if (FREIN_A_MAIN==1)
                {
                    if (CHOC==1) // Pas de Choc
                    {
                        if (Temp_Huile < 80)
                        {
                            if (Temp_Eau < 80)
                            {
                                if (batterie>20)
                                {
                                    
                                        draw_string("                                   ");
                                    
                                }    
                                else if (batterie==0)
                                    draw_string(" Arret : Batterie vide          ");
                                    else
                                    draw_string(" Attention : Batterie faible          ");
                            }
                            else draw_string(" Arret : Temp Eau Trop chaude          ");
                        }
                        else draw_string(" Arret : Temp Huile Trop chaude          "); 
                    }
                }
                else draw_string(" ARRET : Frein a main active         ");
            }
            else draw_string(" ARRET : Restez assis              ");  
        
        
            
            
                
        
        
    }
    
} 
}