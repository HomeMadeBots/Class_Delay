#include "Turn_Off_Delay.h"

#include <stddef.h>


/*============================================================================*/
/* Elements access */
/*============================================================================*/
#define Me_Is_Output_On (Me->super.var_attr->Is_Output_On)
#define Me_My_Timer (Me->super.My_Timer)
#define Me_Delay_Is_Up (Me->super.Delay_Is_Up)
#define Me_Delay_Duration (Me->super.Delay_Duration)


/*============================================================================*/
/* Public methods */
/*============================================================================*/
static void Turn_Off_Delay__Set( const Turn_Off_Delay* Me )
{
    
    Triggered_Timer__Stop( Me_My_Timer );
    Me_Is_Output_On = true;
}
/*----------------------------------------------------------------------------*/
static void Turn_Off_Delay__Reset( const Turn_Off_Delay* Me )
{
    if( false==Triggered_Timer__Is_Active( Me_My_Timer ) )
    {
        Triggered_Timer__Start(
            Me_My_Timer,
            Me_Delay_Duration );
    }
}


/*============================================================================*/
/* Received events */
/*============================================================================*/
static void Turn_Off_Delay__Timer_Is_Up( const Turn_Off_Delay* Me )
{
    Me_Is_Output_On = false;
    if( Me_Delay_Is_Up != NULL )
    {
        Me_Delay_Is_Up();
    }
}


/*============================================================================*/
/* Virtual operations realization */
/*============================================================================*/
Delay_Virtual_Operations Turn_Off_Delay_Operations = {
    /* set */
    ( void (*) (const Delay*) )Turn_Off_Delay__Set,
    /* reset */
    ( void (*) (const Delay*) )Turn_Off_Delay__Reset,
    /* time_is_up */
    ( void (*) (const Delay*) )Turn_Off_Delay__Timer_Is_Up
};