#ifndef UNITCONVERT_H_
#define UNITCONVERT_H_

typedef enum 
{
    FOOT, INCH, YARD
} UNIT;

typedef struct 
{
    double value;
    UNIT unit;
} length;

length convert(length, UNIT);

#endif

