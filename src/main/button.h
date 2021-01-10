#pragma once

#include "mcu_support_package/inc/stm32f4xx.h"
#include "stdbool.h"

typedef struct Button 
{
/*
public:
*/
	bool (*isPressed)(struct Button *button);
	void (*setPressed)(struct Button *button, const bool isPressed);
/*
private:
*/
	uint32_t periphPort;
	GPIO_TypeDef *gpioPort;
	uint16_t gpioPin;
	bool state;
} Button;

Button *initButton(void);

bool isButtonPressed(Button *button);
void setButtonPressed(Button *button, const bool isPressed);
