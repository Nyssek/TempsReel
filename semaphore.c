#include "semaphore.h"


void Init(unsigned char sem)
{
    switch (sem)
    {
        case SEM_CAN:
            Val_sem_cna=1;
            break;
        case SEM_RXTX:
            Val_sem_rxtx=1;
            break;
        default:
            ;
        
    }
}

//reentrant 
void P(unsigned char sem)
{
    switch(sem)
    {
        case SEM_CAN: // SEM_CAN = 1
            while (Val_sem_cna<1)  // Tant que le cna est occup?
                ;                   // On attend
                Val_sem_cna=0; // D?s qu'il est libre, on le r?serve
        case SEM_RXTX: // SEM_RXTX = 2
            while (Val_sem_rxtx<1)  // Tant que la liaison s?rie est occup?
                ;                   // On attend
                Val_sem_cna=0; // D?s qu'elle est libre, on la r?serve
        default:
            ;
    }
}

//reentrant 
void V(unsigned char sem)
{
    switch(sem)
    {
        case SEM_CAN:
            Val_sem_cna=1;
            break;
        case SEM_RXTX:
            Val_sem_rxtx=1;
            break;
        default:
            ;
    }
}