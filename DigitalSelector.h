// vim:ft=arduino
#ifndef DIGITAL_SELECTOR_H
#define DIGITAL_SELECTOR_H

#include "WM8805.h"


namespace arduino{
  namespace libraries{
    class DigitalSelector {
      public:
        DigitalSelector(uint8_t dac_pin = 0): dac_enable_pin(dac_pin){};
        void setup();
        void select(uint8_t input_number);
        uint8_t active_input();
        String get_info();
        void set_power(bool new_state);
      private:
        uint8_t dac_enable_pin;
        WM8805 wm;
    };
  }
}

#endif
