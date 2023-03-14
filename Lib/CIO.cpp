#include "CIO.h"

CIO::CIO(uint32_t iPort, uint32_t iPin, uint32_t iMode, uint32_t iPullUpDown
				, uint8_t otype, uint32_t speed)
{
	m_iPort = iPort;
	m_iPin = iPin;
	
	// Enable all GPIO clocks
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOB);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_GPIOF);
	
	// Init green LED
	// void gpio_mode_set(uint32_t gpio_periph, uint32_t mode, uint32_t pull_up_down, uint32_t pin)
	gpio_mode_set(iPort ,iMode , iPullUpDown,iPin);	
	//gpio_mode_set(LED_GREEN_PORT , GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,LED_GREEN);	
	
	// void gpio_output_options_set(uint32_t gpio_periph, uint8_t otype, uint32_t speed, uint32_t pin)
	gpio_output_options_set(iPort, otype, speed, iPin);
	// 	gpio_output_options_set(LED_GREEN_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, LED_GREEN);

}

void CIO::Set(bool bOn)
{
	gpio_bit_write(m_iPort, m_iPin, bOn ? SET : RESET);
}	

bool CIO::Get(void)
{
	return gpio_input_bit_get(m_iPort, m_iPin);
}
