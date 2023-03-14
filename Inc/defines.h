#ifndef DEFINES_H
#define DEFINES_H

#include "gd32f1x0.h"
#include "../Inc/config.h"


#ifdef LAYOUT_2_0
	#include "defines_2-0.h"		// https://github.com/flo199213/Hoverboard-Firmware-Hack-Gen2
	// hall input pins A,B,C = B11,F1,C14 , etc.
#endif

#ifdef LAYOUT_2_1
	#include "defines_2-1.h"		// https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1
	// hall input pins A,B,C = A0,A1,B11 , etc.
#endif

// ADC value conversion defines
#define MOTOR_AMP_CONV_DC_AMP 0.201465201465  // 3,3V * 1/3 - 0,004Ohm * IL(ampere) = (ADC-Data/4095) *3,3V
#define ADC_BATTERY_VOLT      0.024169921875 	// V_Batt to V_BattMeasure = factor 30: ( (ADC-Data/4095) *3,3V *30 )

// Useful math function defines
#define ABS(a) (((a) < 0.0) ? -(a) : (a))
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define MAX(x, high) (((x) > (high)) ? (high) : (x))
#define MAP(x, xMin, xMax, yMin, yMax) ((x - xMin) * (yMax - yMin) / (xMax - xMin) + yMin)


// ADC buffer struct
typedef struct
{
  uint16_t v_batt;
	uint16_t current_dc;
} adc_buf_t;

//#pragma pack(1)
typedef struct
{
  uint8_t wState;
	float currentDC; 									// global variable for current dc
	float realSpeed; 									// global variable for real Speed
} DataSlave;



#endif		// DEFINES_H
