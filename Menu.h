/*
   FILE:    MotorWaypoint.h
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
#ifndef Menu_h
#define Menu_h

#define TYPE_LABEL

// This makes uint8_t work, otherwise its undefined
#include "Arduino.h"

const char MENU_LABEL_EMPTY[] PROGMEM = "---";

typedef struct choice {
    long value;
    const char* pgm_label;
} MenuChoice;

typedef struct topic {
    MenuChoice** choices;
    byte choices_cnt = 0;
    byte choice_idx = 0;
    long value;
    const char* pgm_label = MENU_LABEL_EMPTY;
    char* val_label;

    void addChoice(byte choice_id, long value, const char* pgm_label) {
        choices[choice_id]->pgm_label = pgm_label;
        choices[choice_id]->value = value;
        choices_cnt++;
    }

    void setActiveChoice(byte choice_id) {
        choice_idx = choice_id;
        value = choices[choice_idx]->value;
        pgm_label = choices[choice_idx]->pgm_label;

        Serial.print(choice_id);
        Serial.print(": ");
        Serial.println(value);
    }

    void nextChoice() {
        choice_idx = choice_idx < choices_cnt ? choice_idx : 0;
        if (++choice_idx < choices_cnt) {
        } else {
            choice_idx = 0;
        }
        
        setActiveChoice(choice_idx);
    }

    bool hasPgmLabel() {
        return choices[choice_idx]->value == value;
    }

    void setValue(long target_value) {
        value = target_value;

        for (int i = 0; i < choices_cnt; i++) {
            if (choices[i]->value == target_value) {
                choice_idx = i;
                pgm_label = choices[i]->pgm_label;
                return;
            }
        }

        ltoa(value, val_label, 10);
    } 
} MenuTopic;

class Menu {
public:
    Menu(byte topic_count);

    void createTopic(byte id, byte choices);
    //void addChoice(byte topic_id, long value, char* label);

    MenuTopic** topics;

    byte topic_idx = 0;
    byte topic_cnt = 0;
    
    bool topicIs(byte idx) {
        return topic_idx == idx;
    }
    
    void nextChoice() {
        topics[topic_idx]->nextChoice();
    }

    void nextTopic() {
        topic_idx++;
        topic_idx = topic_idx < topic_cnt ? topic_idx : 0;
    }
};

#endif