# Delays

This repository defines a package gathering software elements allowing to apply some delay to the
changes of a boolean data.

The package is designed following
[this meta-model](https://github.com/HomeMadeBots/Embedded_Software_Meta_Model) and implemented
according to [these C language
patterns](https://github.com/HomeMadeBots/C-language-patterns-for-Embedded-Software-Meta-Model).

## Content

The Delays package gathers :
* Events :
  * Delay_Is_Up 
* Internal_Design_Class :
  * Delay
  * Turn_On_Delay
  * Turn_Off_Delay
  * Turn_On_Off_Delay
  
## Overview

![classes overview](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/overview.puml)

## Dependencies

![Packages dependencies](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/dependencies.puml)

The following repository shall be retrieved :
* [Timers](https://github.com/HomeMadeBots/Timers)

## Use

### With the Arduino IDE

This repository shall be clone within the _libraries_ folder of the _Arduino sketchbook folder_.


## Turn on delay behavior

### Nominal

After a call to _Set()_, the output takes _Delay_Duration_ to be _ON_.  
A call to _Reset()_ immediately set the output to _OFF_.

![Turn_On_Delay nominal behavior](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_On_Delay_Nominal.puml)

### Multiple Set

If _Set()_ command is called several time (without any call to _Reset()_) only
the first has an effect.  
A call to _Set()_ when output is alredy _ON_ has no effect.

![Turn_On_Delay multiple set](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_On_Delay_Multiple_Set.puml)

### Cancel Set

After a call to _Set()_, if _Reset()_ is called before _Delay_Duration_,
the output remains _OFF_.

![Turn_On_Delay cancel set](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_On_Delay_Cancel_Set.puml)

## Turn off delay behavior

### Nominal

A call to _Set()_ immediately set the output to _ON_.  
After a call to _Reset()_, the output takes _Delay_Duration_ to be _OFF_.

![Turn_Off_Delay nominal behavior](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_Off_Delay_Nominal.puml)

### Multiple Reset

If _Reset()_ command is called several time (without any call to _Set()_) only
the first has an effect.  
A call to _Reset()_ when output is alredy _OFF_ has no effect.

![Turn_Off_Delay multiple reset](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_Off_Delay_Multiple_Reset.puml)

### Cancel Reset

After a call to _Reset()_, if _Set()_ is called before _Delay_Duration_, the output remains _ON_.

![Turn_Off_Delay cancel reset](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_Off_Delay_Cancel_Reset.puml)

## Turn on and turn off delay behavior

### Nominal

After a call to _Set()_, the output takes _Delay_Duration_ to be _ON_.  
After a call to _Reset()_, the output takes _Off_Delay_Duration_ to be _OFF_.

![Turn_On_Off_Delay nominal behavior](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Delays/master/doc/TD_Turn_On_Off_Delay_Nominal.puml)

### Multiple call and cancel

The class Turn_On_Off_Delay aggregates the behavior of Turn_On_Delay and Turn_Off_Delay classes
regarding multiple call and cancel of _Set()_ and _Reset()_.
