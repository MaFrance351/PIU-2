#include <PIU.h>

void PIU::sendData(uint8_t toLCD) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, toLCD);
  digitalWrite(latch, HIGH);
  delay(10);
  digitalWrite(strobe, HIGH);
  delay(1);
  digitalWrite(strobe, LOW);
}
void PIU::push(String data) {
  for (int i = 0; i < data.length(); i++) {
    sendData(data[i]);
  }
}

void PIU::begin(const uint8_t clockPin, const uint8_t dataPin, const uint8_t latchPin, const uint8_t strobePin, const uint8_t resetPin) {
  clock = clockPin;
  data = dataPin;
  latch = latchPin;
  strobe = strobePin;
  reset = resetPin;
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(strobe, OUTPUT);
  pinMode(reset, OUTPUT);
  digitalWrite(latch, HIGH);
  digitalWrite(strobe, LOW);
}
void PIU::begin(const uint8_t clockPin, const uint8_t dataPin, const uint8_t latchPin, const uint8_t strobePin, const uint8_t resetPin, const uint8_t nodisplayPin) {
  clock = clockPin;
  data = dataPin;
  latch = latchPin;
  strobe = strobePin;
  reset = resetPin;
  nodisplay = nodisplayPin;
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(strobe, OUTPUT);
  pinMode(reset, OUTPUT);
  pinMode(nodisplay, OUTPUT);
  digitalWrite(latch, HIGH);
  digitalWrite(strobe, LOW);
  digitalWrite(nodisplay, LOW);
}
void PIU::clear() {
  digitalWrite(reset, LOW);
  delay(15);
  digitalWrite(reset, HIGH);
}
void PIU::print(String data) {
  push(data);
}
void PIU::println(String data) {
  clear();
  delay(1);
  push(data);
}
void PIU::display() {
  digitalWrite(nodisplay, LOW);
}
void PIU::noDisplay() {
  digitalWrite(nodisplay, HIGH);
}
void PIU::showSymbol(uint8_t symb) {
  if(symb <= B11011111) sendData(symb);
}