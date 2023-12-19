#include "container.h"

bool is_odd_pair(pair<string, int> p)
{
    return p.second&1;
}

bool is_even_pair(pair<string, int> p)
{
    return !(p.second & 1);
}