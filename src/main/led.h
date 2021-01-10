#pragma once

#include "mcu_support_package/inc/stm32f4xx.h"
#include "stdbool.h"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

enum LED_COLOUR
{
    GREEN   = 0,
    YELLOW  = 1,
    RED     = 2,
    BLUE    = 3,
    COLOURS = 4
};

typedef struct Led
{
/*
public:
*/	
	void (*turnOn)(struct Led *led);
	void (*turnOff)(struct Led *led);
	bool (*isOn)(struct Led *led);
/*
private:
*/
	uint32_t periphPort;
	GPIO_TypeDef *gpioPort;
	uint16_t gpioPin;
	uint16_t gpioPinSrc;
	bool state;
} Led;

Led *initLed(void);

void turnOnLed(Led *led);
void turnOffLed(Led *led);
bool isLedOn(Led *led);
