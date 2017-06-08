////Pin connect to Latch
const int latchPin = 15; //8;
////Pin connected to Clock
const int clockPin = 12; //6;
////Pin connected to Data
const int dataPin = 2; //4;
byte dec_digits[] = { 0b11101110, 0b10000010,0b11011100,0b11010110,0b10110010,0b01110110,0b01111110,0b11000010,0b11111110,0b11110110 };
void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    for (int x=9999; x>1;  x--) {
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[x%10]); // einer 
    if (x < 100) {
      shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[x/10]); // zehner      
    } else {
      shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[x/10%10]); // zehner
    }

    if (x > 1000) {
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[x/100%10]); // hunderter
    } else {
      shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[x/100]); // hunderter
    }
    shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[x/1000]); // tausender 


    //take the latch pin high so the LEDs will light up
    digitalWrite(latchPin, HIGH);
    delay(100);
    }
}
