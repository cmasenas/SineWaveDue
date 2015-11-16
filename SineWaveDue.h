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
 
#include <DueTimer.h>		// use the DueTimer library for timing
#define OUTPIN 	DAC0

class SineWaveDue{
  private:
	const float pi = 3.14159 ;
    const float A = 490 ;  		// amplitude of sine signal
    int _pin = OUTPIN ;			// set default output pin
    float _T = 50/1000000.0 ;  				// set default sampling time in microseconds
    float c1,  c1b, c0;  			// c1 = first filter coefficient, c1b used for second tone
    volatile float a[3], b[3] ;	// filter registers for generating two tones, updated from interrupt so must be volatile

  public:
    void setPeriod(int interval);				// changes sampling time
    void setPin(int pin);						// changes the output to DAC0 or DAC1
    void playTone(float freq, int duration);		// play one tone for a specified time
    void playTone(float freq);					// play one tone
    void playToneDecay(float freq, float tau);		// play a tone with decaying amplitude of time constant tau
    void playTone2(float freq1, float freq2, int duration);		// play two tones, specified time
    void playTone2(float freq1, float freq2);					// play two tones
    void stopTone(void);						// used in conjunction with playTone and playTone2
    void compute(void);							// computes samples for one tone
    void compute2(void);						// computes samples for two tones
    void compute_decay(void);					// computes a decaying sinewave
		
};

extern SineWaveDue sw;			// sw is instantiated in cpp file
#endif