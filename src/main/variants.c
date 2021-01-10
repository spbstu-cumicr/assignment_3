#include "variants.h"
#include "led.h"

#include <stdio.h>

static const uint8_t ledColour[30][8] = {
    { BLUE   , YELLOW , GREEN  , BLUE   , RED    , BLUE   , RED    , YELLOW }, // №00 B->Y->G->B->R->B->R->Y
    { RED    , GREEN  , RED    , BLUE   , GREEN  , YELLOW , RED    , BLUE   }, // №01 R->G->R->B->G->Y->R->B
    { GREEN  , YELLOW , GREEN  , RED    , GREEN  , RED    , BLUE   , YELLOW }, // №02 G->Y->G->R->G->R->B->Y
    { BLUE   , YELLOW , RED    , BLUE   , RED    , BLUE   , RED    , GREEN  }, // №03 B->Y->R->B->R->B->R->G
    { RED    , GREEN  , BLUE   , YELLOW , BLUE   , RED    , BLUE   , YELLOW }, // №04 R->G->B->Y->B->R->B->Y
    { BLUE   , GREEN  , BLUE   , YELLOW , RED    , YELLOW , BLUE   , GREEN  }, // №05 B->G->B->Y->R->Y->B->G
    { YELLOW , RED    , YELLOW , GREEN  , BLUE   , RED    , YELLOW , GREEN  }, // №06 Y->R->Y->G->B->R->Y->G
    { YELLOW , RED    , YELLOW , BLUE   , GREEN  , YELLOW , RED    , GREEN  }, // №07 Y->R->Y->B->G->Y->R->G
    { YELLOW , GREEN  , BLUE   , GREEN  , RED    , BLUE   , YELLOW , BLUE   }, // №08 Y->G->B->G->R->B->Y->B
    { YELLOW , GREEN  , RED    , BLUE   , GREEN  , RED    , BLUE   , GREEN  }, // №09 Y->G->R->B->G->R->B->G
    { RED    , GREEN  , BLUE   , GREEN  , YELLOW , BLUE   , RED    , YELLOW }, // №10 R->G->B->G->Y->B->R->Y
    { BLUE   , GREEN  , YELLOW , GREEN  , RED    , GREEN  , YELLOW , GREEN  }, // №11 B->G->Y->G->R->G->Y->G
    { RED    , GREEN  , YELLOW , GREEN  , BLUE   , GREEN  , BLUE   , YELLOW }, // №12 R->G->Y->G->B->G->B->Y
    { GREEN  , YELLOW , RED    , BLUE   , YELLOW , GREEN  , BLUE   , YELLOW }, // №13 G->Y->R->B->Y->G->B->Y
    { BLUE   , GREEN  , YELLOW , BLUE   , GREEN  , RED    , BLUE   , GREEN  }, // №14 B->G->Y->B->G->R->B->G
    { BLUE   , RED    , BLUE   , RED    , GREEN  , RED    , YELLOW , RED    }, // №15 B->R->B->R->G->R->Y->R
    { RED    , GREEN  , BLUE   , RED    , GREEN  , RED    , YELLOW , BLUE   }, // №16 R->G->B->R->G->R->Y->B
    { YELLOW , BLUE   , RED    , BLUE   , YELLOW , GREEN  , RED    , GREEN  }, // №17 Y->B->R->B->Y->G->R->G
    { BLUE   , GREEN  , RED    , GREEN  , BLUE   , GREEN  , RED    , YELLOW }, // №18 B->G->R->G->B->G->R->Y
    { GREEN  , YELLOW , GREEN  , BLUE   , GREEN  , YELLOW , GREEN  , BLUE   }, // №19 G->Y->G->B->G->Y->G->B
    { GREEN  , YELLOW , GREEN  , YELLOW , BLUE   , RED    , YELLOW , BLUE   }, // №20 G->Y->G->Y->B->R->Y->B
    { GREEN  , YELLOW , RED    , GREEN  , BLUE   , GREEN  , YELLOW , BLUE   }, // №21 G->Y->R->G->B->G->Y->B
    { RED    , GREEN  , RED    , YELLOW , GREEN  , RED    , YELLOW , BLUE   }, // №22 R->G->R->Y->G->R->Y->B
    { GREEN  , BLUE   , RED    , BLUE   , RED    , BLUE   , GREEN  , YELLOW }, // №23 G->B->R->B->R->B->G->Y
    { GREEN  , RED    , YELLOW , GREEN  , BLUE   , RED    , GREEN  , YELLOW }, // №24 G->R->Y->G->B->R->G->Y
    { GREEN  , YELLOW , GREEN  , BLUE   , GREEN  , YELLOW , GREEN  , RED    }, // №25 G->Y->G->B->G->Y->G->R
    { GREEN  , BLUE   , RED    , YELLOW , BLUE   , GREEN  , RED    , YELLOW }, // №26 G->B->R->Y->B->G->R->Y
    { GREEN  , BLUE   , GREEN  , YELLOW , GREEN  , YELLOW , BLUE   , YELLOW }, // №27 G->B->G->Y->G->Y->B->Y
    { BLUE   , RED    , BLUE   , RED    , YELLOW , RED    , GREEN  , RED    }, // №28 B->R->B->R->Y->R->G->R
    { BLUE   , RED    , GREEN  , BLUE   , YELLOW , BLUE   , RED    , YELLOW }  // №29 B->R->G->B->Y->B->R->Y
};

const uint8_t *getLedColourList(const uint8_t variant)
{
    if (variant >= 30)
    {
        return NULL;
    }

    return ledColour[variant];
}

uint8_t ledColourSize(void)
{
    return 8;
}
