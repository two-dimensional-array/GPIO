#ifndef __GPIO_H__
#define __GPIO_H__

#if (defined(__cplusplus) && (!defined(GPIO_USE_CPP_STYLE)))
extern "C" {
#else
#include <stdbool.h>
#endif

#include <gpio_config.hpp>

typedef GPIO_PORT_TYPE gpio_port_t;
typedef GPIO_PIN_TYPE gpio_pin_t;

struct SGPIO
{
	gpio_port_t* port;
	gpio_pin_t pin;
#ifdef GPIO_USE_CPP_STYLE
	const bool Read();
	const void Write(bool state);
#endif
};

typedef struct SGPIO gpio_t;

bool GPIORead(gpio_t* pGPIO);
void GPIOWrite(gpio_t* pGPIO, bool state);
gpio_pin_t GPIOReadArray(gpio_t* pGPIOArray, size_t size);
void GPIOWriteArray(gpio_t* pGPIOArray, size_t size, gpio_pin_t value);

#if (defined(__cplusplus) && (!defined(GPIO_USE_CPP_STYLE)))
}
#endif // extern "C"

#endif // __GPIO_H__
