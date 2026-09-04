#include "ItemType.h"
#include <iostream>
using namespace std;

void ItemType::Initialize(int val)
{
    value = val;
}
int ItemType::GetValue() const
{
    return value;
}

RelationType ItemType::ComparedTo(ItemType &someValue)
{
    if (value == someValue.GetValue())
    {
        return EQUAL;
    }
    else if (someValue.GetValue() > value)
    {
        return LESS;
    }
    return GREATER; // (someStudent.GetStatus() < status)
}

void ItemType::SetValue(int k) { value = k; }

void ItemType::Print()
{
    cout << value;
}
