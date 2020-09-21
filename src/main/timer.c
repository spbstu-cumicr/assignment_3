#include "timer.h"

void initTimer(const uint32_t timeout_ms)
{
	// Вычисляем предделитель и период таймера в тактах
	uint16_t prescaler = SystemCoreClock / REFERENCE_FREQUENCY_HZ - 1;
	uint32_t period = REFERENCE_FREQUENCY_HZ * timeout_ms / 1000 - 1;
	
	// Подаём питание на порт таймера общего назначения TIM3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// Настраиваем таймер общего назначения TIM3
	TIM_TimeBaseInitTypeDef led_timer;
	TIM_TimeBaseStructInit(&led_timer);
	
	led_timer.TIM_Prescaler = prescaler;
	led_timer.TIM_CounterMode = TIM_CounterMode_Up;
	led_timer.TIM_Period = period;
	
	TIM_TimeBaseInit(TIM3, &led_timer);		
	
	// Включаем таймер общего назначения TIM3
	TIM_Cmd(TIM3, ENABLE);
}
