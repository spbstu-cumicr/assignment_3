#include "led.h"

static Led led[] = 
{
	{
		.periphPort = RCC_AHB1Periph_GPIOD,
		.gpioPort   = GPIOD,
		.gpioPin    = GPIO_Pin_12,
		.gpioPinSrc = GPIO_PinSource12,
		.state      = false,
		.turnOn     = turnOnLed,
		.turnOff    = turnOffLed,
		.isOn       = isLedOn
	},
	
	{
		.periphPort = RCC_AHB1Periph_GPIOD,
		.gpioPort   = GPIOD,
		.gpioPin    = GPIO_Pin_13,
		.gpioPinSrc = GPIO_PinSource13,
		.state      = false,
		.turnOn     = turnOnLed,
		.turnOff    = turnOffLed,
		.isOn       = isLedOn
	},
	
	{
		.periphPort = RCC_AHB1Periph_GPIOD,
		.gpioPort   = GPIOD,
		.gpioPin    = GPIO_Pin_14,
		.gpioPinSrc = GPIO_PinSource14,
		.state      = false,
		.turnOn     = turnOnLed,
		.turnOff    = turnOffLed,
		.isOn       = isLedOn
	},
	
	{
		.periphPort = RCC_AHB1Periph_GPIOD,
		.gpioPort   = GPIOD,
		.gpioPin    = GPIO_Pin_15,
		.gpioPinSrc = GPIO_PinSource15,
		.state      = false,
		.turnOn     = turnOnLed,
		.turnOff    = turnOffLed,
		.isOn       = isLedOn
	},
};

Led *initLed(void)
{
	for (uint8_t ledNumber = 0; ledNumber < ARRAY_SIZE(led); ledNumber++)
	{
		// Подаём питание на порт светодиода
		RCC_AHB1PeriphClockCmd(led[ledNumber].periphPort, ENABLE);
		
		// Устанавливаем пин светодиода в режим вывода c двухтактным каскадом с низкой частотой
		GPIO_InitTypeDef new_led;
		GPIO_StructInit(&new_led);

		new_led.GPIO_Pin   = led[ledNumber].gpioPin;
		new_led.GPIO_Mode  = GPIO_Mode_OUT;
		new_led.GPIO_Speed = GPIO_Low_Speed;
		new_led.GPIO_OType = GPIO_OType_PP;
		
		GPIO_Init(led[ledNumber].gpioPort, &new_led);
	}
	
	return led;
}

void turnOnLed(Led *led)
{
	GPIO_SetBits(led->gpioPort, led->gpioPin);
	led->state = true;
}

void turnOffLed(Led *led)
{
	GPIO_ResetBits(led->gpioPort, led->gpioPin);
	led->state = false;
}

bool isLedOn(Led *led)
{
	return led->state;
}
