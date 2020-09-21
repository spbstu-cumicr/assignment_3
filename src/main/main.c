#include "mcu_support_package/inc/stm32f4xx.h"
#include "led.h"
#include "timer.h"
#include "button.h"
#include "main/Lab3_Test.h"

#include <stdint.h>

// Последовательность загорания светодиодов
// Укажите последовательность в соответствии с вариантом
// Используйте макроопределения цветом светодиодов:
// LED_GREEN — зелёный
// LED_YELLOW — жёлтый
// LED_RED — красный
// LED_BLUE — синий
static const uint8_t ledColour[] = {
	LED_BLUE,
	LED_GREEN,
	LED_BLUE,
	LED_YELLOW,
	LED_RED,
	LED_YELLOW,
	LED_BLUE,
	LED_GREEN
};

// Таймаут таймера
const uint32_t timeout_ms = 15;

// Фамилия
const char *lastName = "Pankov";

int main(void)
{
	// Вариант задания
	static uint8_t variant = 0;	
	variant = Lab3_Test_ini((char *)lastName);	

	// Контрольная сумма
	static uint32_t checksum = 0;
	static uint8_t decision[] = {0, 0, 0};
	
	// Инициализируем клавиатуру
	static Led *led = NULL;
	led = initLed();
	
	static Button *button = NULL;
	button = initButton();
	
	// Инициализируем таймер
	initTimer(timeout_ms);

	while(1)
	{
		// Номер светодиода
		static uint8_t ledNumber = 0;
		
		// Пауза между нажатиями
		static bool isPause = false;
		
		if (TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) == RESET)
		{
			continue;
		}
		
		// Определяем, нажата ли кнопка
		bool isButtonPressed = (bool)GPIO_ReadInputDataBit(button->gpioPort, button->gpioPin);
		button->setPressed(button, isButtonPressed);
		
		// Текущий светодиод
		Led *currentLed = &led[ledColour[ledNumber]];
		
		// Если кнопка нажата
		if (button->isPressed(button) == true)
		{
			// Если между нажатиями была пауза
			if (isPause == true)
			{
				// Гасим текущий светодиод
				currentLed->turnOff(currentLed);
				
				// Определяем следующий светодиод
				ledNumber++;
				ledNumber %= ARRAY_SIZE(ledColour);
				currentLed = &led[ledColour[ledNumber]];
				
				isPause = false;
			}
			
			// Если текущий светодиод не зажжён
			if (currentLed->isOn(currentLed) == false)
			{
				// Зажигаем текущий светодиод
				currentLed->turnOn(currentLed);
			}
		}
		else
		{
			// Иначе если текущий светодиод горит, то это пауза между нажатиями
			if (currentLed->isOn(currentLed) == true)
			{
				isPause = true;
			}
		}
		
		// Сбрасываем флаг таймера
		TIM_ClearFlag(TIM3, TIM_FLAG_Update);
		
		// Считаем контрольную сумму
		checksum = while_Test(decision);
	}
	
	return 0;
}

#ifdef USE_FULL_ASSERT

// эта функция вызывается, если assert_param обнаружил ошибку
void assert_failed(uint8_t *file, uint32_t line)
{ 
	/* User can add his own implementation to report the file name and line number,
	ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	
	(void)file;
	(void)line;
	
	__disable_irq();
	while(1)
	{
		// это ассемблерная инструкция "отладчик, стой тут"
		// если вы попали сюда, значит вы ошиблись в параметрах вызова функции из SPL. 
		// Смотрите в call stack, чтобы найти ее
		__BKPT(0xAB);
	}
}

#endif
