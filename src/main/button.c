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
	GPIO_InitTypeDef newButton;
	GPIO_StructInit(&newButton);

	newButton.GPIO_Pin   = button.gpioPin;
	newButton.GPIO_Mode  = GPIO_Mode_IN;
	newButton.GPIO_Speed = GPIO_Low_Speed;
	newButton.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_Init(button.gpioPort, &newButton);
	
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
