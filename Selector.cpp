// vim:ft=arduino

#include "Arduino.h"
#include "AnalogSelector.h"
#include "DigitalSelector.h"
#include "Selector.h"

namespace arduino{
  namespace libraries{
    Selector::Selector(uint8_t act_input, uint8_t act_output, uint8_t dac_pin): active_input(act_input), active_output(act_output), dac_enable_pin(dac_pin){
        DigitalSelector digital_selector(dac_pin);
        AnalogSelector analog_selector;
        Input inputs [] = {
          Input(2, NULL, "AUX"),
          Input(3, NULL, "PHONO"),
          Input(7, 0, "USB"),
          Input(7, 1, "Raspberry Pi"),
          Input(7, 6, "CD Player"),
          Input(7, 6, "TV"),
        };
    };
    void Selector::setup(){
      analog_selector.setup();
      digital_selector.setup();
    };
    uint8_t Selector::select_next_input(){
      active_input++;
      if(active_input >= 6){
        active_input = 0;
      }
      select_input(active_input);
    };
    uint8_t Selector::select_prev_input(){
    };
    void Selector::select_input(uint8_t input_number){
      digital_selector.select(get_active_input()->digital_input);
      analog_selector.select(get_active_input()->analog_input);
    };
    Input * Selector::get_active_input(){
      return & inputs[active_input];
    };
  }
}

