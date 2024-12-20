#include "lib_aoc.hpp"

void run_single_day(std::string& day)
{
    if (day == "01")
    {
        day_01::run();
    }
    else if (day=="02")
    {
        day_02::run();
    }
    else if (day=="03")
    {
        day_03::run();
    }
    else if (day=="04")
    {
        day_04::run();
    }
    else if (day=="05")
    {
        day_05::run();
    }
    else if (day=="06")
    {
        day_06::run();
    }
    else if (day=="07")
    {
        day_07::run();
    }
    else if (day=="08")
    {
        day_08::run();
    }
    else if (day=="09")
    {
        day_09::run();
    }
    else if (day=="10")
    {
        day_10::run();
    }
    else if (day=="11")
    {
        day_11::run();
    }
}

void run_all()
{
    day_01::run();
    day_02::run();
    day_03::run();
    day_04::run();
    day_05::run();
    day_06::run();
    day_07::run();
    day_08::run();
    day_09::run();
    day_10::run();
    day_11::run();
}