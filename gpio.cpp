#include "gpio.hpp"

#ifdef GPIO_USE_CPP_STYLE
const bool SGPIO::Read()
{
	return GPIORead(this);
}

const void SGPIO::Write(bool state)
{
	GPIOWrite(this, state);
}
#endif

bool GPIORead(gpio_t* pGPIO)
{
	return GPIO_READ(pGPIO);
}

void GPIOWrite(gpio_t* pGPIO, bool state)
{
	GPIO_WRITE(pGPIO, state);
}

gpio_pin_t GPIOReadArray(gpio_t* pGPIOArray, size_t size)
{
	gpio_pin_t value;

	for (size_t i = 0; i < size; i++)
	{
		value |= (GPIORead(&pGPIOArray[i]) << i);
	}

	return value;
}

void GPIOWriteArray(gpio_t* pGPIOArray, size_t size, gpio_pin_t value)
{
	for (size_t i = 0; i < size; i++)
	{
		GPIOWrite(&pGPIOArray[i], (value & 1));
		value >>= 1;
	}
}
