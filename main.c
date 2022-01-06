// Adding Libraries
#include <IRremote.h>
#include <Servo.h>

// Declaring Pins
struct sensor {
  const int TRIG = 1;
  const int ECHO = 2;
}

struct motors {
  struct leftM {
    const int lfm = 3;
    const int lbm = 4; 
    }
    struct rightM {
    const int rfm = 5;
    const int rbm = 6;
    }
}
