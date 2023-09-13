#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define NUM_LEDS 450

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);


int valence = 0;
int arousal = 2;
int dominance = 1;

int data;

void setup() {
  strip.begin();
  strip.show();  // Initialize all pixels to off
  strip.setBrightness(250);
  Serial.begin(115200);
  Serial.setTimeout(1);
}

// Rest of the code remains the same

void loop() {
  while (!Serial.available());
  valence = Serial.readString().toInt();
  Serial.print(valence);
  
  while (!Serial.available());
  arousal = Serial.readString().toInt();
  Serial.print(arousal);
  
  while (!Serial.available());
  dominance = Serial.readString().toInt();
  Serial.println(dominance);
  
  if ((arousal == 0) && (dominance == 0) && (valence == 0)) {
    // 1 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }
  else if ((arousal == 0) && (dominance == 0) && (valence == 1)) {
    // 2 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }
  else if ((arousal == 0) && (dominance == 0) && (valence == 2)) {
    // 3 - DESIRE - durazno
    setColor(strip.Color(252, 60, 30));
    delay(1000);
  }
  else if ((arousal == 0) && (dominance == 1) && (valence == 0)) {
    // 4 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }  
  else if ((arousal == 0) && (dominance == 1) && (valence == 1)) {
    // 5 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }  
  else if ((arousal == 0) && (dominance == 1) && (valence == 2)) {
    // 6 - DESIRE - durazno
    setColor(strip.Color(252, 60, 30));
    delay(1000);
  }  
  else if ((arousal == 0) && (dominance == 2) && (valence == 0)) {
    // 7 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }  
  else if ((arousal == 0) && (dominance == 2) && (valence == 1)) {
    // 8 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }  
  else if ((arousal == 0) && (dominance == 2) && (valence == 2)) {
    // 9 - DESIRE - durazno
    setColor(strip.Color(252, 60, 30));
    delay(1000);
  }  
  else if ((arousal == 1) && (dominance == 0) && (valence == 0)) {
    // 10 - HATE - red
    setColor(strip.Color(220, 0, 0));
    delay(1000);
  }  
  else if ((arousal == 1) && (dominance == 0) && (valence == 1)) {
    // 11 - LOVE - verde claro
    setColor(strip.Color(204, 255, 10));
    delay(1000);
  }  
  else if ((arousal == 1) && (dominance == 0) && (valence == 2)) {
    // 12 - LOVE - verde claro
    setColor(strip.Color(204, 255, 10));
    delay(1000);
  } 
  else if ((arousal == 1) && (dominance == 1) && (valence == 0)) {
    // 13 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  }  
  else if ((arousal == 1) && (dominance == 1) && (valence == 1)) {
    // 14 - ADMIRATION - green
    setColor(strip.Color(0, 255, 0));
    delay(1000);
  } 
  else if ((arousal == 1) && (dominance == 1) && (valence == 2)) {
    // 15 - DESIRE - durazno
    setColor(strip.Color(252, 60, 30));
    delay(1000);
  } 
  else if ((arousal == 1) && (dominance == 2) && (valence == 0)) {
    // 16 - SADNESS - blue
    setColor(strip.Color(50, 50, 215));
    delay(1000);
  } 
  else if ((arousal == 1) && (dominance == 2) && (valence == 1)) {
    // 17 - DESIRE - durazno
    setColor(strip.Color(252, 60, 30));
    delay(1000);
  } 
  else if ((arousal == 1) && (dominance == 2) && (valence == 2)) {
    // 18 - DESIRE - durazno
    setColor(strip.Color(252, 60, 30));
  } 
  else if ((arousal == 2) && (dominance == 0) && (valence == 0)) {
    // 19 - HATE - red
    setColor(strip.Color(220, 0, 0));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 0) && (valence == 1)) {
    // 20 - ADMIRATION - green
    setColor(strip.Color(0, 255, 0));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 0) && (valence == 2)) {
    // 21 - LOVE - verde claro
    setColor(strip.Color(204, 255, 10));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 1) && (valence == 0)) {
    // 22 - HATE - red
    setColor(strip.Color(220, 0, 0));
    delay(1000);
  }
  else if ((arousal == 2) && (dominance == 1) && (valence == 1)) {
    // 23 - ADMIRATION - green
    setColor(strip.Color(0, 255, 0));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 1) && (valence == 2)) {
    // 24 - JOY - yellow
    setColor(strip.Color(255, 255, 0));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 2) && (valence == 0)) {
    // 25 - ADMIRATION - green
    setColor(strip.Color(0, 255, 0));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 2) && (valence == 1)) {
    // 26 - ADMIRATION - green
    setColor(strip.Color(0, 255, 0));
    delay(1000);
  } 
  else if ((arousal == 2) && (dominance == 2) && (valence == 2)) {
    // 13 - JOY - yellow
    setColor(strip.Color(255, 255, 0));
    delay(1000);
  } 
}

void setColor(uint32_t color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}