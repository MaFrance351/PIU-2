#include <PIU.h>

#define CLOCK 5 //SH_CP
#define DATA 6  //DS
#define LATCH 7  //ST_CP
#define STROBE 4
#define RESET 3

PIU panel;

void setup() {
  panel.begin(CLOCK, DATA, LATCH, STROBE, RESET);
  panel.clear();
  panel.print("takie dela.");
}


void loop() {
}