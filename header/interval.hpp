#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <random>

class Interval
{
public:
    float min;
    float max;

    Interval();

    Interval(float Min , float Max);

    float GetSize();

    bool Contains(float Value);

    float RandNum();
};

#endif // INTERVAL_HPP