#pragma once

#include "mcu_support_package/inc/stm32f4xx.h"

#define REFERENCE_FREQUENCY_HZ 1000000

void initTimer(const uint32_t timeout_ms);
