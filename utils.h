#pragma once
#include "framework.h"

template <typename T>
T get_correct_number(T min_num, T max_num)
{
    T x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min_num || x > max_num)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        //cout << "¬ведите число от " << min_num << " до " << max_num<<":";
        cout << "Type number from " << min_num << " to " << max_num<<":";
    }
    return x;
}
