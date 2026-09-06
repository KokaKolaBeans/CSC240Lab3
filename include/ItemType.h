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
    ItemType();
    ItemType(int val);        // Paramaterized constructor
    void Initialize(int val); // Method constructor (not using this)
    int GetValue() const;
    RelationType ComparedTo(ItemType &someValue);
    void SetValue(int k);
    void Print();

private:
    int value;
};

#endif
