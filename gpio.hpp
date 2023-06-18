#pragma once

#include "gpio_config.hpp"

typedef GPIO_PORT_TYPE gpio_port_t;
typedef GPIO_PIN_TYPE gpio_pin_t;

struct SGPIO
{
	gpio_port_t* port;
	gpio_pin_t pin;
#ifdef __cplusplus
	const bool Read();
	const void Write(bool state);
#endif
};

#ifndef __cplusplus
typedef struct SGPIO SGPIO;
#endif

bool GPIORead(SGPIO* pGPIO);
void GPIOWrite(SGPIO* pGPIO, bool state);
gpio_pin_t GPIOReadArray(SGPIO* pGPIOArray, size_t size);
void GPIOWriteArray(SGPIO* pGPIOArray, size_t size, gpio_pin_t value);
