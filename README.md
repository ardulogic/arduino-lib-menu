# Menu

## An Arduino library for displaying Menus

Easy integration with LCD library

### v1.0

Added examples

```c++
#include "Menu.h"
#include "LCD.h"

Menu myMenu(3);
LCD lcd(2);

const char P_LABEL_SPEED_STOP[] PROGMEM = "Lapse";
const char P_LABEL_SPEED_SLOW[] PROGMEM = "Slow";
const char P_LABEL_SPEED_SLOW_P[] PROGMEM = "Slow+";

void setup() {
  
    Serial.begin(9600);
    lcd.init();
    lcd.zones[0]->set(0, 0, 30, 8);
    lcd.zones[1]->set(0, 8, 30, 8);
    
	//                 Topic ID, Num Choices
    myMenu.createTopic(       0,             3);
    myMenu.topics[0]->addChoice(0, 100, P_LABEL_SPEED_STOP);
    myMenu.topics[0]->addChoice(1, 250, P_LABEL_SPEED_SLOW);
    myMenu.topics[0]->addChoice(2, 300, P_LABEL_SPEED_SLOW_P);  
    myMenu.topics[0]->setActiveChoice(1);

	//                 Topic ID, Num Choices
    myMenu.createTopic(       0,             3);
    myMenu.topics[1]->addChoice(0, 600, P_LABEL_SPEED_STOP);
    myMenu.topics[1]->addChoice(1, 750, P_LABEL_SPEED_SLOW);
    myMenu.topics[1]->addChoice(2, 900, P_LABEL_SPEED_SLOW_P);  
    myMenu.topics[1]->setValue(1000);
   
}

void loop() {
  myMenu.nextTopic();
  //myMenu.nextChoice();  
  delay(1000);

  ui_draw();
}

void ui_draw() {
  if (myMenu.topics[0]->hasPgmLabel()) {
    lcd.zones[0]->pText(myMenu.topics[0]->pgm_label,  myMenu.topicIs(0));
  }

  if (myMenu.topics[1]->hasPgmLabel()) {
    lcd.zones[1]->pText(myMenu.topics[1]->pgm_label,  myMenu.topicIs(1));
  } else {
    lcd.zones[1]->text(myMenu.topics[1]->val_label,  myMenu.topicIs(1), 1);    
  }
  
  lcd.update();
}


```
