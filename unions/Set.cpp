#include "Set.h"

TSet::TSet(int mp)
    : MaxPower(mp), BitField(mp)
{
}

TSet::TSet(const TSet &s)
    : MaxPower(s.MaxPower), BitField(s.BitField)
{
}

TSet::TSet(const TBitField &bf)
    : MaxPower(bf.GetLength()), BitField(bf)
{
}

TSet &TSet::operator=(const TSet &s)
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const
{
    return MaxPower;
}

void TSet::InsElem(const int n)
{
    BitField.SetBit(n);
}

void TSet::DelElem(const int n)
{
    BitField.ClrBit(n);
}

int TSet::IsMember(const int n) const
{
    return BitField.GetBit(n);
}

int TSet::operator==(const TSet &s)
{
    return BitField == s.BitField;
}

TSet TSet::operator+(const int n)
{
    TSet temp(BitField);
    temp.InsElem(n);
    return temp;
}

TSet TSet::operator+(const TSet &s)
{
    TSet temp(BitField | s.BitField);
    return temp;
}

TSet TSet::operator*(const TSet &s)
{
    TSet temp(BitField & s.BitField);
    return temp;
}

TSet TSet::operator-(void)
{
    TSet temp(~BitField);
    return temp;
}

std::istream &operator>>(std::istream &istr, TSet &bf)
{
    istr >> bf.BitField;
    bf.MaxPower = bf.BitField.GetLength();
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const TSet &bf)
{
    ostr << bf.BitField;
    return ostr;
}
