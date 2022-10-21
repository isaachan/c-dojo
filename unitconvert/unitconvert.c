#ifndef __UNITCONVERT_H__
#define __UNITCONVERT_H__

#include "unitconvert.h"

length convert(length source, UNIT target_unit)
{
    if (source.unit == FOOT && target_unit == INCH) 
    {
        return (length) { source.value * 12, target_unit };
    }
    else if (source.unit == INCH && target_unit == FOOT)
    {
        return (length) { source.value * (1.0 / 12), target_unit };
    }
    else if (source.unit == YARD && target_unit == FOOT)
    {
        return (length) { source.value * 3, target_unit };
    }
    else if (source.unit == FOOT && target_unit == YARD)
    {
        return (length) { source.value * (1.0 / 3), target_unit };
    }
    else 
    {
        return source;
    }
}

#endif

