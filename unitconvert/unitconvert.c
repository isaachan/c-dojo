#include <stddef.h>
#include "unitconvert.h"

length convert(length source, UNIT target_unit)
{
    double scale = ((double) source.unit) / target_unit;
    return (length) { source.value * scale, target_unit};
}

