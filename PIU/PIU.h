#ifndef testLib_h
#define testLib_h
#include <Arduino.h>

class PIU {
  private:
    uint8_t clock, data, latch, strobe, reset, nodisplay;
    void sendData(uint8_t toLCD);
    void push(String data);
  public:
    void begin(const uint8_t clockPin, const uint8_t dataPin, const uint8_t latchPin, const uint8_t strobePin, const uint8_t resetPin);
    void begin(const uint8_t clockPin, const uint8_t dataPin, const uint8_t latchPin, const uint8_t strobePin, const uint8_t resetPin, const uint8_t nodisplayPin);
    void clear();
    void print(String data);
    void println(String data);
    void display();
    void noDisplay();
    void showSymbol(uint8_t symb);
};

#endif