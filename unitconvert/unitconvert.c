#include "unitconvert.h"

double factor(UNIT source, UNIT target);

length convert(length source, UNIT target_unit)
{
    double scale = ((double) source.unit) / target_unit;
    return (length) { source.value * scale, target_unit};
}

