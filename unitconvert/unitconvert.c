#ifndef __UNITCONVERT_H__
#define __UNITCONVERT_H__

#include "unitconvert.h"

length convert(length source, UNIT target_unit)
{
    if (source.unit == FOOT && target_unit == INCH) 
    {
        return (length) { source.value * 12, target_unit };
    }
    return source;
}

#endif

