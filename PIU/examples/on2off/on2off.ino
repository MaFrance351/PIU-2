#include <PIU.h>

#define CLOCK 5 //SH_CP
#define DATA 6  //DS
#define LATCH 7  //ST_CP
#define STROBE 4 //строб
#define RESET 3 //сброс
#define NODISPLAY 2 //вывод гашения

PIU panel;

void setup() {
  panel.begin(CLOCK, DATA, LATCH, STROBE, RESET, NODISPLAY);
  panel.clear();
  panel.print("123456");
}


void loop() {
  panel.display();
  delay(1000);
  panel.noDisplay();
  delay(1000);
}