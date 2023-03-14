# Hoverboard-ObjectOriented-OperatingSystem
 
If you have the Keil IDE installed and a Gen 2.x hoverboard,
please help me to get this code running.

I can not debug it :-/

There is already a primitve class CIO for digital input/output in ib/CIO.cpp

https://github.com/RoboDurden/Hoverboard-ObjectOriented-OperatingSystem/blob/421a4c0b85978cf0a50b7e7a7e332c850e2bcbe5/Lib/CIO.cpp#L3
```
 class CIO
 {
 private:
  uint32_t m_iPort;
  uint32_t m_iPin;
 public:

  CIO(uint32_t iPort, uint32_t iPin, uint32_t iMode=GPIO_MODE_OUTPUT, uint32_t iPullUpDown=GPIO_PUPD_NONE
     , uint8_t otype=GPIO_OTYPE_PP, uint32_t speed=GPIO_OTYPE_PP);

  void Set(bool bOn = true);
  bool Get(void);
 };
```

But the new main() in Lib/main.cpp does not seem to be called :-(

```
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
```
Please help :-) 
