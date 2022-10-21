#ifndef UNITCONVERT_H_
#define UNITCONVERT_H_

typedef enum 
{
    YARD=36, FOOT=12, INCH=1
} UNIT;

typedef struct 
{
    double value;
    UNIT unit;
} length;

length convert(length, UNIT);

#endif

