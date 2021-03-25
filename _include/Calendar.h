#ifndef CALENDAR_H
#define CALENDAR_H

#ifndef JOSEPH
#define JOSEPH

#include "test.h"

#endif
#include "Compute.h"



enum class Month
{
    january = 12,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};



typedef struct Week
{
    const uint8_t week_size_small  = 3;
    const uint8_t week_size_normal = 4;
    const uint8_t week_size_large  = 5;
} Weeks;

struct Calendar
{
    Month month;
    Weeks week;
};

#define One_Quartal     3

#define january     Month::january
#define february    Month::february
#define march       Month::march
#define april       Month::april
#define may         Month::may
#define june        Month::june
#define july        Month::july
#define august      Month::august
#define september   Month::september
#define october     Month::october
#define november    Month::november
#define december    Month::december

#endif // !CALENDAR_H