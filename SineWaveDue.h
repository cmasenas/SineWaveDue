/*
 *	SineWave.h - Arduino library for creating a sine wave on the fly.
 *	Created by C. Masenas, November 8, 2015.  cmasenas@alum.rpi.edu
 *
 *  This is free software. You can redistribute it and/or modify it under
 *  the terms of Creative Commons Attribution 3.0 United States License. 
 *  To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/us/ 
 *  or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 * 
 *	Attribution must be given to the author for use of the sine generation algorithm.
 *	That's all I ask.
 */
 
#ifndef SineWaveDue_h
#define SineWaveDue_h
 
#include <DueTimer.h>
#define OUTPIN 	DAC0

class SineWaveDue{
  private:
	const float pi = 3.14159 ;
    const float A = 490 ;  
    int _pin = OUTPIN ;
    int _T = 50 ;  
    float omega, omega2, c1,  c1b;
    volatile float a[3], b[3] ;

  public:
    void initialize(void);
    void setPeriod(int interval);
    void setPin(int pin);
    void playTone(int freq, int duration);
    void playTone(int freq);
    void playTone2(int freq1, int freq2, int duration);
    void playTone2(int freq1, int freq2);
    void stopTone(void);
    void compute(void);
    void compute2(void);
		
};

extern SineWaveDue sw;
#endif