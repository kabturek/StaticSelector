// vim:ft=arduino
#ifndef SELECTOR_H
#define SELECTOR_H

#include "Arduino.h"
#include "AnalogSelector.h"
#include "DigitalSelector.h"

namespace arduino{
  namespace libraries{
    struct Input{
      uint8_t analog_input;
      uint8_t digital_input;
      String name;
      Input(uint8_t analog, uint8_t digital, String n): analog_input(analog), digital_input(digital), name(n) {};
      Input(){};
    };

    class Selector {
      public:
        Selector(Input inputs[], uint8_t active_input = 0, uint8_t active_output = 0, uint8_t dac_pin = 3);
        void setup();
        uint8_t select_next_input();
        uint8_t select_prev_input();
        void select_input(uint8_t input_number);
        void select_output(uint8_t output_number);
        void mute();
        String get_name();
        uint8_t get_number();
        Input * get_active_input();
        uint8_t active_input;
        uint8_t get_analog();
        uint8_t get_digital();
      private:
        Input * inputs;
        uint8_t dac_enable_pin;
        uint8_t active_output;
        AnalogSelector analog_selector;
        DigitalSelector digital_selector;
    };
  }
}

#endif
