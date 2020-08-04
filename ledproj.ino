#include <Keyboard.h>

#include <FastLED.h>

#define LED_DT 7

#define COLOR_ORDER GRB
#define LED_TYPE WS2812
#define NUM_LEDs 120

uint8_t max_bright = 50;
int val;
int buttonpin=3;
const int threshold = 200;

int blue = 0;

struct CRGB leds[NUM_LEDs];

unsigned long currentMillis = 0;
unsigned long startMillis = 0;
unsigned long blinkStartMillis;
unsigned long fadeStartMillis;
unsigned long blinkPeriod = 1000;
const unsigned long fadePeriod = 10;
unsigned int brightness = 149;
unsigned int incr = 1;

bool loopy = true;
bool loopy2 = true;

const byte ledPin = 13;

int button = 4;
int buttonState = 0;

// using analog sound sensor
int sensorPin = A2;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDs);
  FastLED.setBrightness(max_bright);
  Serial.begin(9600);
  pinMode(buttonpin,INPUT);
  pinMode(button, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin,INPUT);

  startMillis = millis();

}

void loop() {
  // put your main code here, to run repeatedly:

  
  lightFade();
  Serial.println(sensorValue);


//**** continous loop of two leds moving across path
  /*for(int i = 1;i < NUM_LEDs; i++){
    leds[i-2].setRGB(0,0,0);
    leds[i] = CRGB::YellowGreen;
    FastLED.show();
    delay(30);
  }
  FastLED.clear();

//**** fills entire rgb strip one color ****
  fill_solid(leds, NUM_LEDs, CRGB(50, 0, 200));
  delay(1000);
  FastLED.clear();

//**** makes rgb strip rainbow slowly ****
  for (int i = 0;i<NUM_LEDs;i++){
    fill_rainbow(leds, i, 0, 5);
  
    FastLED.show();
    delay(50);
  }

//**** with analog output sound module, 
//**** if sound more than threshold
//**** change color to green, else make red ****
/*
  int soundsens = digitalRead(soundpin);
  if (soundsens >= threshold) {
    fill_solid(leds, NUM_LEDs, CRGB::Green);
    FastLED.show();
    delay(1000);
  }
  else {
    fill_solid(leds, NUM_LEDs, CRGB::Red);
    FastLED.show();
  }

  Serial.println(analogRead(A2));
  

  */
  


  //lightFade();

//**** loop of code changing color of rgb strip
//**** then erasing colors on the way back
//**** when sound introduced on first loop it will turn off an led****
  /*int j = 0;
  for(int i = 0; i < NUM_LEDs; i++){
    leds[i] = CHSV(j, 255, 100);
    FastLED.show();
    delay(100);
    j = j+20;
    val = digitalRead(buttonpin);
    if (val ==HIGH)
    {
      //fill_solid(leds,NUM_LEDs, CRGB::Green);
      //FastLED.show();
      //delay(2000);
      leds[i] = CHSV(j, 255, 0);
      FastLED.show();
    }
  
  }
  for(int k=NUM_LEDs; k >= 0; k--){
    leds[k] = CHSV(0, 255, 0);
    FastLED.show();
    delay(100);
    
  }*/



  currentMillis = millis();
  //blinky();
  //fade();

//  buttonState = digitalRead(button);
//
//  if (buttonState == HIGH) {
//    leds[5] = CRGB(0, 255, 0);
//    FastLED.show();
//  }
//  else {
//    leds[5] = CRGB(0,0,0);
//    FastLED.show();
//    //FastLED.clear();
//  }


  
}

void blinky() {
  if (currentMillis - blinkStartMillis >= blinkPeriod)
  {
    //digitalWrite(ledPin, !digitalRead(ledPin));
    //fill_solid(leds,NUM_LEDs,CRGB(255,0,0));
    leds[5] = CRGB(255,0,0);
    if (loopy){
      loopy = false;
      FastLED.show();
    }
    else{
      //fill_solid(leds, NUM_LEDs, CRGB(0,0,0));
      leds[5] = CRGB(0,0,0);
      FastLED.show();
      loopy = true;
    }
    blinkStartMillis = currentMillis;
  }
}

void fade() {
  if (currentMillis - fadeStartMillis >= fadePeriod){
    if (brightness >= 255){
      loopy2 = false;
    }
    else if (brightness == 50) {
      loopy2 = true;
    }
    if (loopy2) {
      brightness += incr;
    }
    else {
      brightness -= incr;
    }
    //fill_solid(leds,NUM_LEDs,CHSV(0,255,brightness));
    leds[3] = CHSV(0,255,brightness);
    FastLED.show();
    fadeStartMillis = currentMillis;
  }
}

void lightFade(){
  //**** fade colors in and out ****

  int i = 0;
  for (i = 0; i < 255;i++){

    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    if (sensorValue <= 122) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,75));
      FastLED.show();
    }
    else if (sensorValue > 122 && sensorValue <= 123) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,100));
      FastLED.show();
    }
    else if (sensorValue > 123 && sensorValue <= 126) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,125));
      FastLED.show();
    }
    else if (sensorValue > 126 && sensorValue <= 129) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,150));
      FastLED.show();
    }
    else if (sensorValue > 129 && sensorValue <= 132) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,175));
      FastLED.show();
    }
    else if (sensorValue > 132 && sensorValue <= 134) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,200));
      FastLED.show();
    }
    else if (sensorValue > 134 && sensorValue <= 137) {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,225));
      FastLED.show();
    }
    else {
      fill_solid(leds,NUM_LEDs, CHSV(i,255,255));
      FastLED.show();
    }
    
    delay(50);

  }
  

}

void soundDetection(){
  //**** if sound hear, increase brigtness ****

  sensorValue = analogRead(sensorPin);
  if (sensorValue <= 121) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,75));
    FastLED.show();
    delay(80);
  }
  else if (sensorValue > 121 && sensorValue <= 123) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,100));
    FastLED.show();
    delay(80);
  }
  else if (sensorValue > 123 && sensorValue <= 126) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,125));
    FastLED.show();
    delay(80);
  }
  else if (sensorValue > 126 && sensorValue <= 129) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,150));
    FastLED.show();
    delay(80);
  }
  else if (sensorValue > 129 && sensorValue <= 132) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,175));
    FastLED.show();
    delay(80);
  }
  else if (sensorValue > 132 && sensorValue <= 134) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,200));
    FastLED.show();
    delay(80);
  }
  else if (sensorValue > 134 && sensorValue <= 137) {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,225));
    FastLED.show();
    delay(80);
  }
  else {
    fill_solid(leds,NUM_LEDs, CHSV(0,255,255));
    FastLED.show();
    delay(80);
  }

//  val = digitalRead(buttonpin);
//  if (val == HIGH)
//  {
//    for(brightness=50;brightness<255;brightness++){
//      fill_solid(leds,NUM_LEDs, CHSV(0,255,brightness));
//      FastLED.show();
//    }
//    for(int i=0;i<255;i++){
//      leds[i].fadeToBlackBy(192);
//      delay(50);
//      FastLED.show();
//    }
//  }
//  else {
//    for (brightness; brightness>=50;brightness--){
//      fill_solid(leds,NUM_LEDs, CHSV(0,255,brightness));
//      FastLED.show();
//    }
//  }
}
