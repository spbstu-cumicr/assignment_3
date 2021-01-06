#include "timer.h"

void initTimer(const uint32_t timeout_ms)
{
	// Вычисляем предделитель и период таймера в тактах
	uint16_t prescaler = SystemCoreClock / 2 / REFERENCE_FREQUENCY_HZ - 1;
	uint16_t period = REFERENCE_FREQUENCY_HZ * timeout_ms / 1000 - 1;
	
	// Подаём питание на порт таймера общего назначения TIM3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// Настраиваем таймер общего назначения TIM3
	TIM_TimeBaseInitTypeDef ledTimer;
	TIM_TimeBaseStructInit(&ledTimer);
	
	ledTimer.TIM_Prescaler = prescaler;
	ledTimer.TIM_CounterMode = TIM_CounterMode_Up;
	ledTimer.TIM_Period = period;
	
	TIM_TimeBaseInit(TIM3, &ledTimer);		
	
	// Включаем таймер общего назначения TIM3
	TIM_Cmd(TIM3, ENABLE);
}
