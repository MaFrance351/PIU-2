#include <PIU.h>

#define CLOCK 5 //SH_CP
#define DATA 6  //DS
#define LATCH 7  //ST_CP
#define STROBE 4 //строб
#define RESET 3 //сброс

PIU panel;

void setup() {
  panel.begin(CLOCK, DATA, LATCH, STROBE, RESET);
  panel.clear();
}


void loop() {
  for(int i = 0; i < 223; i++) {
    panel.showSymbol(i);
    delay(300);
  }
}