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

const int ROUNDS = 20;
int sequence[ROUNDS];
int n = 0;
bool ok = true;

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for(int i=0; i<SIZE; i++){
    pinMode(LEDS[i], OUTPUT);
    pinMode(BUTTONS[i], INPUT);
  } 
}

void printLed(int led){
  digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
}

void randomSequence(){
  for (int i=0; i<ROUNDS; i++){
    sequence[i] = random(0,SIZE);
  }
  n = 1;  
}

void printSequence(){
  delay(1000);
  for(int i=0; i<n; i++){
    printLed(LEDS[sequence[i]]);
    Serial.println(sequence[i]);
    delay(1000);
  }
}

bool readButtons(){
  for (int j=0; j<n && ok; j++){
    int input[]={0,0,0,0};
    while(!input[GREEN] 
          && !input[RED] 
          && !input[BLUE] 
          && !input[YELLOW]){
      for(int i=0; i<SIZE; i++){
        input[i] = digitalRead(BUTTONS[i]);
        if(input[i]){
          printLed(LEDS[i]);
        } 
      }
    }
    
    if(!input[sequence[j]]){
      ok=false;
    }
  }
  return ok;
}

void loop(){
  Serial.println("**********");
  ok = true;
  randomSequence();
  while(ok && n<=ROUNDS){
    Serial.print("ronda ");
    Serial.println(n);
    printSequence();
    if(readButtons()){
      Serial.println("btn ok");
      n++;
    }else{
      ok=false;
    }
  }
  if(ok){
    Serial.println("WIN!!!!!");
  }else{
    Serial.println("FAIL!!!!!");
  }
  delay(2000);
}
