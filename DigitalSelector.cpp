#include "Arduino.h"
#include <WM8805.h>
#include "DigitalSelector.h"

namespace arduino{
  namespace libraries{
    void DigitalSelector::setup(){
      pinMode(dac_enable_pin, OUTPUT);
      wm.init();
    }
    void DigitalSelector::select(uint8_t input_number){
      if(input_number == NULL){
        set_power(false);
      } else {
        set_power(true);
        wm.select_input(input_number);
      }
    };
    String DigitalSelector::get_info(){
      //TODO: get information from WM (LOCK, FREQ,etc)
    };
    void DigitalSelector::set_power(bool new_state){
      digitalWrite(dac_enable_pin, new_state ? HIGH : LOW);
    };
  }
}
