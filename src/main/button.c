#include "button.h"

static Button button = 
{
	.periphPort = RCC_AHB1Periph_GPIOA,
	.gpioPort   = GPIOA,
	.gpioPin    = GPIO_Pin_0,
	.gpioPinSrc = GPIO_PinSource0,
	.state      = false,
	.isPressed  = isButtonPressed,
	.setPressed = setButtonPressed
};

Button *initButton(void)
{
	// Подаём питание на порт кнопки
	RCC_AHB1PeriphClockCmd(button.periphPort, ENABLE);
	
	// Устанавливаем пин кнопки в режим ввода с подтяжкой к земле с низкой частотой
	GPIO_InitTypeDef new_button;
	GPIO_StructInit(&new_button);

	new_button.GPIO_Pin   = button.gpioPin;
	new_button.GPIO_Mode  = GPIO_Mode_IN;
	new_button.GPIO_Speed = GPIO_Low_Speed;
	new_button.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_Init(button.gpioPort, &new_button);
	
	return &button;
}

bool isButtonPressed(Button *button)
{
	return button->state;
}

void setButtonPressed(Button *button, const bool isPressed)
{
	button->state = isPressed;
}
