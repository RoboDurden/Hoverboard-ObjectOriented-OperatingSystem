#include "CIO.h"

#include "../Inc/config.h"
#include "../Inc/defines.h"


extern "C" //  make sure that _every_ c++ source file are guaranteed to see the extern "C" declarations
{
	#include "../Inc/it.h"
	#include "../Inc/setup.h"
}



int main(void)
{
	//SystemClock_Config();
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock / 100);
	
	// Init watchdog
	if (Watchdog_init() == ERROR)
	{
		// If an error accours with watchdog initialization do not start device
		while(1);
	}

	// Init Interrupts
	Interrupt_init();
	
	// Init timeout timer
	TimeoutTimer_init();
	

	CIO oIO_Blink(LED_ORANGE_PORT,LED_ORANGE);
	
	CIO oIO_Button(BUTTON_PORT,BUTTON_PIN,GPIO_MODE_INPUT);
	
	CIO oIO_HoldOn(SELF_HOLD_PORT,SELF_HOLD_PIN);
	oIO_HoldOn.Set(true);	// Activate self hold direct after GPIO-init
	
	// Device has 1,6 seconds to do all the initialization
	// afterwards watchdog will be fired
	fwdgt_counter_reload();
	
	while (oIO_Button.Get())	// Wait until button is pressed
		fwdgt_counter_reload();	// Reload watchdog while button is pressed

	bool bOn = true;
	while(1)
	{
		oIO_Blink.Set(bOn);
		bOn = !bOn;
		Delay(100);
		
		fwdgt_counter_reload();		// Reload watchdog (watchdog fires after 1,6 seconds)
	}
}