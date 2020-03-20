const int GREEN = 0;
const int RED = 1;
const int BLUE = 2;
const int YELLOW = 3;

const int LED_GREEN = 8;
const int LED_RED = 6;
const int LED_BLUE = 4;
const int LED_YELLOW = 2;

const int LEDS[] = {LED_GREEN, LED_RED, LED_BLUE, LED_YELLOW};

const int BTN_GREEN = 9;
const int BTN_RED = 7;
const int BTN_BLUE = 5;
const int BTN_YELLOW = 3;

const int BUTTONS[] = {BTN_GREEN, BTN_RED, BTN_BLUE, BTN_YELLOW};

const int SIZE = 4;

void setup(){
  Serial.begin(9600);

  for(int i=0; i<SIZE; i++){
    pinMode(LEDS[i], OUTPUT);
    pinMode(BUTTONS[i], INPUT);
  } 
}

void loop(){
  
}
