#include "T1.h"

void tache1()
{
        ////////////////////////////
        
    unsigned char i;

    di();
    initialisation_des_ports();
    initialisation_afficheur();
    clear_text();
    clear_graphics();
    init_rxtx();
    Init(SEM_RXTX);
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;

    vitesse=0;
    batterie=120;
    n_octet_badge=0;

    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');

    TP_appui=0;
    
 
    while (PIR1bits.TX1IF==0);   TXREG1=' ';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='1';while (TXSTA1bits.TRMT==0);
    
    
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
        while (PIR1bits.TX1IF==0);   TXREG1='1';while (TXSTA1bits.TRMT==0);
        
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
        
        //goto_lico(0,0);
        //draw_string("Marche:");
        
        //if (MARCHE_AVANT==0) 
            //draw_string("AV");
        //else
            //if (MARCHE_ARRIERE==0)
                //draw_string("AR");
            //else
                //draw_string("N ");

        goto_lico(1,0);
        draw_string("Siege:");
        if (SIEGE==1) //S'il n'y a personne
        {
            draw_char('0');          
            if(vitesse == 0)//Si le véhicule est à l'arrêt
            {
                goto_lico(7,0);
                draw_string("((!))"); 
            }
            else
            {
                while (vitesse !=0) 
                {
                    vitesse--;
                    goto_lico(5,0);
                    draw_string("VitesseVal:");
                    draw_hex8(vitesse);
                    unsigned int temp = 0;
                    while(temp<50)
                    {
                        temp++;
                    }
                //goto_lico(7,0);
                //draw_string("((!))"); // IL MANQUE UN DELAY ET UN FREINAGE
                }  
            }
            
            if (MARCHE_AVANT==0) 
            {
                goto_lico(0,0);
                draw_string("Marche:");
                draw_string("_N_"); //on affiche rien car il y'a un frein de prévu
            }
            else if (MARCHE_ARRIERE==0)
            {    
                goto_lico(0,0);
                draw_string("Marche:");
                draw_string("_N_");//on affiche rien car il y'a un frein de prévu
            }
            else
            {
                goto_lico(0,0);
                draw_string("Marche:");
                draw_string("_N_");
            }
        }
        else //S'il y'a quelque'un
        {
            draw_char('1');
            if(FREIN_A_MAIN==0) //Si le frein à main est désactivé
            {
                
                 if (MARCHE_AVANT==0) 
                {
                    goto_lico(0,0);
                    draw_string("Marche:");
                    draw_string("AV"); //on affiche rien car il y'a un frein de prévu
                }
                else if (MARCHE_ARRIERE==0)
                {    
                    goto_lico(0,0);
                    draw_string("Marche:");
                    draw_string("AR");//on affiche rien car il y'a un frein de prévu
                }
                else
                {
                   goto_lico(0,0);
                   draw_string("Marche:");
                   draw_string("N_");
                } 
                goto_lico(7,0);
                draw_string("     ");  
            }
            else
            {
              goto_lico(7,0);
              draw_string("((!))");  
            }
            
             if (MARCHE_AVANT==0) 
            {
                goto_lico(0,0);
                draw_string("Marche:");
                draw_string("AV"); //on affiche rien car il y'a un frein de prévu
            }
            else if (MARCHE_ARRIERE==0)
            {    
                goto_lico(0,0);
                draw_string("Marche:");
                draw_string("AR");//on affiche rien car il y'a un frein de prévu
            }
            else
            {
                goto_lico(0,0);
                draw_string("Marche:");
                draw_string("N_");
            }
            
            if(FREIN_A_MAIN==0)
            {
             while (vitesse !=0) 
             {
                    goto_lico(7,0);
                    draw_string("((!))");
                    vitesse--;
                    goto_lico(5,0);
                    draw_string("VitesseVal:");
                    draw_hex8(vitesse);
                    unsigned int duree = 0;
                    while(duree<50)
                    {
                        duree++;
                    }
                }        
            }
            else
            {
                goto_lico(7,0);
                draw_string("     ");
            }
        }

        goto_lico(2,0);
        draw_string("Temp. Eau:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_EAU));

        goto_lico(3,0);
        draw_string("Temp. Huile:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_HUILE));

        goto_lico(4,0);
        draw_string("Choc:");
        if (CHOC==0)
            draw_char('1');
        else
            draw_char('0');

        goto_lico(5,0);
        draw_string("VitesseVal:");
        if (VITESSE_PLUS==0)
            vitesse++;
        if (VITESSE_MOINS==0)
            vitesse--;
        draw_hex8(vitesse);

        goto_lico(6,0);
        draw_string("Batterie:");
        if (BATTERIE_PLUS==0)
            batterie++;
        if (BATTERIE_MOINS==0)
            batterie--;
        draw_hex8(batterie);

        //goto_lico(7,0);
        //if (FREIN_A_MAIN==0)
            //draw_string("((!))");
        //else
            //draw_string("     ");

        goto_lico(8,0);
        draw_string("Badge:");
        if (n_octet_badge==0) //if (n_octet_badge==0)
            draw_string(" AUCUN              ");
        if (n_octet_badge !=0) {
            draw_string(" MAUVAIS              ");} //ajout
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
        
        //goto_lico(11,0); //ajout de test clé
        //if (n_octet_badge == 1) draw_string("bon badge"); //ajout de test clé
        //else //ajout de test clé
        //{
            //goto_lico(11,0);
            //draw_string("ARRET : Pas ou mauvais badge");
            
        //}

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
    }
}
