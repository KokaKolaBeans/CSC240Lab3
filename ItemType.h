#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum RelationType
{
    LESS,
    EQUAL,
    GREATER
};

class ItemType
{
public:
    void Initialize(int val);
    int GetValue() const;
    RelationType ComparedTo(ItemType &someValue);
    void SetValue(int k);
    void Print();

private:
    int value;
};

#endif
