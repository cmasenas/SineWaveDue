#include <DueTimer.h>
#include <SineWaveDue.h>

void setup()  { 
  analogReadResolution(10);
  analogWriteResolution(10);

} 

void loop()  { 
    sw.playTone(2000);
    delay(1000);
    sw.stopTone();
    sw.playTone2(1000, 1200);
    delay(1000);
    sw.stopTone();
    sw.playTone(3000, 1000);
} 


  


