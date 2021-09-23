#ifndef DELAY_H
#define DELAY_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Attributes */
#include <stdint.h>


/* Associated objects */
#include "Triggered_Timer.h"


/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct _Delay Delay;

typedef struct {
    bool Is_Output_On;
} Delay_Var;

typedef struct {
    void (*set) ( const Class_Delay* );
    void (*reset) ( const Class_Delay* );
    void (*timer_is_up) ( const Class_Delay* );
} Delay_Virtual_Operations;

struct _Delay {

    /* Variable attributes */
    Delay_Var* var_attr;
    
    /* Virtual operations */
    const Delay_Virtual_Operations* virt_op;
    
    /* Sent events */
    void (*Delay_Is_Up)( void );
    
    /* Associated objects */
    const Triggered_Timer* My_Timer;
    
    /* Configuration_Parameters */
    uint32_t Delay_Duration;
    
};


/*============================================================================*/
/* Public methods */
/*============================================================================*/
bool Delay__Get( const Delay* Me );


/*============================================================================*/
/* Virtual operations */
/*============================================================================*/
/* Public methods */
void Delay__Set( const Delay* Me );
void Delay__Reset( const Delay* Me );
/* Event reception */
void Delay__Timer_Is_Up( const Delay* Me );


#endif