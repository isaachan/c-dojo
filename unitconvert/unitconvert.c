#ifndef __UNITCONVERT_H__
#define __UNITCONVERT_H__

#include "unitconvert.h"

double factor(UNIT source, UNIT target);

length convert(length source, UNIT target_unit)
{
    double scale = 0;
    if (source.unit == FOOT && target_unit == INCH) 
    {
        scale = 12;
    }
    else if (source.unit == INCH && target_unit == FOOT)
    {
        scale = 1.0/12;
    }
    else if (source.unit == YARD && target_unit == FOOT)
    {
        scale = 3;
    }
    else if (source.unit == FOOT && target_unit == YARD)
    {
        scale = 1.0/3;
    }
    else if (source.unit == YARD && target_unit == INCH)
    {
        scale = 36;
    }
    else if (source.unit == INCH && target_unit == YARD)
    {
        scale = 1.0/36;
    }
    else 
    {
        scale = 1;
    }
    return (length) { source.value * scale, target_unit};
}

#endif

