#ifndef TURN_ON_OFF_DELAY_H
#define TURN_ON_OFF_DELAY_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
#include "Delay.h"


/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct {
    /* Inheritance */
    Delay_Var super;

    bool Is_Input_On;
} Turn_On_Off_Delay_Var;

typedef struct {

    /* Inheritance */
    Delay super;

    /* Configuration_Parameters */
    uint32_t Off_Delay_Duration;
    
} Turn_On_Off_Delay;


/*============================================================================*/
/* Virtual operations realization */
/*============================================================================*/
extern Delay_Virtual_Operations Turn_On_Off_Delay_Operations;


#endif