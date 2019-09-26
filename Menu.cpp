/* FILE:    SingleStepper.h
   DATE:    09/07/15
   VERSION: 0.1
   AUTHOR:  Andrew Davies

11/03/15 version 0.1: Original version  
   
Library header for driving DC and stepper motors.

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
 */

#include "Menu.h"

Menu::Menu(byte topic_count) {
    // We allocate memory for storing 
    // array of pointers to LCD_zone objects
    topics = new MenuTopic*[topic_count];
        
    // We assign the objects for each pointer
//    for (int i = 0; i < zone_cnt; i++) {                
//        topics[i] = new MenuChoice(&display);
//    }
}

void Menu::createTopic(byte id, byte choices) {
    topics[id] = new MenuTopic;    
    topics[id]->choices = new MenuChoice*[choices];
    
    for (byte i = 0; i < choices; i++) {
        topics[id]->choices[i] = new MenuChoice(); 
    }
    
    topic_cnt++;
}

//void Menu::addChoice(byte topic_id, byte choice_id, long value, char* label) {
//    topics[topic_id]->choices[choice_id]->label = label;
//    topics[topic_id]->choices[choice_id]->value = value;    
//}