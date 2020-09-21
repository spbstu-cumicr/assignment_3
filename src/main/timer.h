#ifndef TIMER_H
#define TIMER_H

#include "mcu_support_package/inc/stm32f4xx.h"

#define REFERENCE_FREQUENCY_HZ 1000000

void initTimer(const uint32_t timeout_ms);

#endif //TIMER_H
