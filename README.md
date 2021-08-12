# Class_Delay

This repo provides classes allowing to apply some delay to the changes of a
boolean data.

## Overview

![classes overview](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/Class_Delay.puml)

## Turn on delay behavior

### Nominal

After a call to _Set()_, the output takes _Delay_Duration_ to be _ON_.  
A call to _Reset()_ immediately set the output to _OFF_.

![Class_Turn_On_Delay nominal behavior](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_On_Delay_Nominal.puml)

### Multiple Set

If _Set()_ command is called several time (without any call to _Reset()_) only
the first has an effect.  
A call to _Set()_ when output is alredy _ON_ has no effect.

![Class_Turn_On_Delay multiple set](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_On_Delay_Multiple_Set.puml)

### Cancel Set

After a call to _Set()_, if _Reset()_ is called before _Delay_Duration_,
the output remains _OFF_.

![Class_Turn_On_Delay cancel set](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_On_Delay_Cancel_Set.puml)


## Turn off delay behavior

### Nominal

A call to _Set()_ immediately set the output to _ON_.  
After a call to _Reset()_, the output takes _Delay_Duration_ to be _OFF_.

![Class_Turn_Off_Delay nominal behavior](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_Off_Delay_Nominal.puml)

### Multiple Reset

If _Reset()_ command is called several time (without any call to _Set()_) only
the first has an effect.  
A call to _Reset()_ when output is alredy _OFF_ has no effect.

![Class_Turn_Off_Delay multiple reset](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_Off_Delay_Multiple_Reset.puml)

### Cancel Reset

After a call to _Reset()_, if _Set()_ is called before _Delay_Duration_, the output remains _ON_.

![Class_Turn_Off_Delay cancel reset](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_Off_Delay_Cancel_Reset.puml)


## Turn on and turn off delay behavior

### Nominal

After a call to _Set()_, the output takes _Delay_Duration_ to be _ON_.  
After a call to _Reset()_, the output takes _Off_Delay_Duration_ to be _OFF_.

![Class_Turn_On_Off_Delay nominal behavior](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Class_Delay/master/doc/TD_Class_Turn_On_Off_Delay_Nominal.puml)

### Multiple call and cancel

The Class_Turn_On_Off_Delay aggregates the behavior of Class_Turn_On_Delay and 
Class_Turn_Off_Delay regarding multiple call and cancel of _Set()_ and
_Reset()_.
