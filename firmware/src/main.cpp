#include <Arduino.h>
#define BUTTON_PIN PA0
#define LED_PIN PA1

void update_tick();
bool can_update = false;
void setup() {
   // put your setup code here, to run once:
    Serial.begin(115200);
  /*
  HardwareTimer *tim = new HardwareTimer(TIM2);
  tim -> setOverflow(5,HERTZ_FORMAT);
  tim -> attachInterrupt(update_tick);
  tim-> resume();
  */
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  attachInterrupt(BUTTON_PIN,update_tick,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (can_update){
    Serial.print("ticked");
    can_update = false;
    digitalToggle(LED_PIN);
  }
  
}
void update_tick(){
  can_update = true;
}

