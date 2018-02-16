#ifndef _DISPLAY_7SEG_H
#define _DISPLAY_7SEG_H

#include <stdint.h>
#include "EventListener.h"


/**
 * \brief Listener of events and turning on/off a digital output.
 * \author @caligari
 */
class Display7x4 : public EventListener
{
public:

  SimpleLed(const Config* cfg);

  void init();

  bool getStatus() { return _status; }

  void setStatus(bool value);

  void toggle();

  void flashOne(uint16_t millis);

  typedef struct {
          uint8_t motor_left_in1;
          uint8_t motor_left_in2;
          uint8_t motor_left_in3;
          uint8_t motor_left_in4;
          uint8_t motor_right_in1;
          uint8_t motor_right_in2;
          uint8_t motor_right_in3;
          uint8_t motor_right_in4;
          int16_t steps_per_second;
          int16_t line_steps;
          int16_t turn_steps;

      } Config;

  //////////////////////////////////////////////////////////////////////
  // StatusIndicator interface
  //////////////////////////////////////////////////////////////////////

  // turn on between movement pauses
  virtual void moveExecuted(MOVE move) { setStatus(true); }
  virtual void moveExecuting(MOVE move) { setStatus(false); }
  virtual void programFinished() { setStatus(false); }

  // turn on when button is pressed (200 milliseconds)
  virtual void moveAdded(MOVE move) { flashOne(200); }
  virtual void programReset() { flashOne(200); }
  virtual void programStarted(uint8_t total_moves) { flashOne(200); }



private:

  uint8_t _pin;

  bool _status;

#endif // _DISPLAY_7SEG_H
