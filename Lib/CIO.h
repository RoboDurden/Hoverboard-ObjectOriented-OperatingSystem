#ifndef CIO_H
#define CIO_H

extern "C" //  make sure that _every_ c++ source file are guaranteed to see the extern "C" declarations
{
	#include <gd32f1x0_rcu.h>
	#include "../Inc/it.h"
}

#include "gd32f1x0.h"

class CIO
{
	
private:

	uint32_t m_iPort;
	uint32_t m_iPin;
public:
		
	//CIO(uint32_t iPort, uint32_t iPin, uint32_t iMode, uint32_t iPullUpDown, uint8_t otype, uint32_t speed);		
	CIO(uint32_t iPort, uint32_t iPin, uint32_t iMode=GPIO_MODE_OUTPUT, uint32_t iPullUpDown=GPIO_PUPD_NONE
				, uint8_t otype=GPIO_OTYPE_PP, uint32_t speed=GPIO_OTYPE_PP);

	void Set(bool bOn = true);
	bool Get(void);

};

#endif	//  CIO_H