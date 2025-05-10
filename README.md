# Shiny Potato is the DIY Power Supply for Hobbyists #

Most linear power supplies for electronics hobbyists are either quite expensive or lack many features that would satisfy the requirements of a DIY electronics lab.

## Lnear Regulator Based ##

Most cheap lab bench power supplies are switch mode power supplies. This introduces unwanted switching noise into your project and in some cases can even cause a test to fail or unpredicatable behavior. 
By using a Linear regulator it is both cost effective, stable and beginner freindly.

## Linear Regulator Based ##

Most cheap lab bench power supplies are switch mode power supplies. This introduces unwanted switching noise into your project and in some cases can even cause a test to fail or unpredicatable behavior. 
By using a Linear regulator it is both cost effective, stable and beginner friendly.

## Arduino Control ##

In order to achieve the most stability possible out of a budget DIY project an arduino UNO R3 will be used to give a Voltage readout, voltage regulator temperature monitoring and regulation by controlling a set of 12V fans.


_______________________________________________________________
|LCD Display                   |  TEMP SENSOR                 |
| 1k resistor to ground → VD,  |    Vout → Pin 3              |      
| Pin 7 → RS,                  |                              |            
| Pin 8 → RW,                  |                              |            
| Pin 9 → D4,                  |                              |           
| Pin 10 → D5,                 |______________________________|             
| Pin 11 → D6,                 | Volt SENSOR                  |             
| Pin 12 → D7,                 |   Voltage Divider node A → A0|             
| A → VCC                      |                              |       
| K→GND                        |                              |     
|______________________________|______________________________|


