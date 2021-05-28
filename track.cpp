#include "track.h"


int Track::getFirst() const
{
    return first;
}

void Track::setFirst(int value)
{
    first = value;
}

int Track::getLast() const
{
    return last;
}

void Track::setLast(int value)
{
    last = value;
}

Track::Track(int _a, int _b)
{
    first=_a;
    last=_b;
}
