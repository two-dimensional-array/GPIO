#include "gpio.hpp"

const bool SGPIO::Read()
{
	return GPIORead(this);
}

const void SGPIO::Write(bool state)
{
	GPIOWrite(this, state);
}

bool GPIORead(SGPIO* pGPIO)
{
	return GPIO_READ(pGPIO);
}

void GPIOWrite(SGPIO* pGPIO, bool state)
{
	GPIO_WRITE(pGPIO, state);
}

gpio_pin_t GPIOReadArray(SGPIO* pGPIOArray, size_t size)
{
	gpio_pin_t value;

	for (size_t i = 0; i < size; i++)
	{
		value |= (GPIORead(&pGPIOArray[i]) << i);
	}

	return value;
}

void GPIOWriteArray(SGPIO* pGPIOArray, size_t size, gpio_pin_t value)
{
	for (size_t i = 0; i < size; i++)
	{
		GPIOWrite(&pGPIOArray[i], (value & 1));
		value >>= 1;
	}
}
