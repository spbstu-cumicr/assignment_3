#include "lab_3_test.h"

static uint32_t checksum = 0;

uint8_t initTest(const char *lastName)
{
    return Lab3_Test_ini((char *)lastName);
}

void getDecision(uint8_t *decision)
{
    checksum = while_Test(decision);
}

uint32_t getChecksum(void)
{
    return checksum;
}
