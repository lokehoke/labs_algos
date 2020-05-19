#include <string>

#include "BitField.h"

constexpr int STELEM = static_cast<int>(sizeof(TELEM)) * 8;

TBitField::TBitField()
{
    BitLen = 0;
    pMem = nullptr;
    MemLen = 0;
}

TBitField::TBitField(int len)
{
    BitLen = len;
    MemLen = (len % STELEM == 0 ? len / STELEM : len / STELEM + 1);
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf)
    : BitLen(bf.BitLen), MemLen(bf.MemLen)
{
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = bf.pMem[i];
    }
}

TBitField &TBitField::operator=(const TBitField &bf)
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    delete[] pMem;
    pMem = new TELEM[MemLen];

    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = bf.pMem[i];
    }

    return *this;
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const
{
    return n / STELEM;
}

TELEM TBitField::GetMemMask(const int n) const
{
    return 1 << (n % 32);
}

int TBitField::GetLength(void) const
{
    return BitLen;
}

void TBitField::SetBit(const int n)
{
    if ((n >= 0) && (n < BitLen))
    {
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    }
}

void TBitField::ClrBit(const int n)
{
    if ((n >= 0) && (n < BitLen))
    {
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    }
}

int TBitField::GetBit(const int n) const
{
    if ((n >= 0) && (n < BitLen))
    {
        return ((pMem[GetMemIndex(n)] & GetMemMask(n)) != 0 ? 1 : 0);
    }
    else
    {
        return 0;
    }
}

int TBitField::operator==(const TBitField &bf)
{
    if (BitLen == bf.BitLen)
    {
        for (int i = 0; i < MemLen; ++i)
        {
            if (bf.pMem[i] != pMem[i])
            {
                return 0;
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

TBitField TBitField::operator|(const TBitField &bf)
{
    int len = BitLen;
    if (bf.BitLen > len)
    {
        len = bf.BitLen;
    }

    TBitField temp(len);
    for (int i = 0; i < MemLen; ++i)
    {
        temp.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; ++i)
    {
        temp.pMem[i] |= bf.pMem[i];
    }

    return temp;
}

TBitField TBitField::operator&(const TBitField &bf)
{
    int len = BitLen;
    if (bf.BitLen > len)
    {
        len = bf.BitLen;
    }

    TBitField temp(len);
    for (int i = 0; i < MemLen; ++i)
    {
        temp.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; ++i)
    {
        temp.pMem[i] &= bf.pMem[i];
    }

    return temp;
}

TBitField TBitField::operator~(void)
{
    int len = BitLen;
    TBitField tmp(len);
    for (int i = 0; i < MemLen; ++i)
    {
        tmp.pMem[i] = ~pMem[i];
    }

    return tmp;
}

std::istream &operator>>(std::istream &istr, TBitField &bf)
{
    delete[] bf.pMem;

    std::string str;
    istr >> str;

    bf.BitLen = static_cast<int>(str.size());
    bf.MemLen = (bf.BitLen % STELEM == 0 ? bf.BitLen / STELEM : bf.BitLen / STELEM + 1);
    bf.pMem = new TELEM[bf.MemLen];

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '0')
        {
            bf.ClrBit(i);
        }
        else if (str[i] == '1')
        {
            bf.SetBit(i);
        }
    }

    return istr;
}

std::ostream &operator<<(std::ostream &os, const TBitField &bf)
{
    int len = bf.GetLength();
    for (int i = 0; i < len; ++i)
    {
        os << bf.GetBit(i);
    }

    return os;
}
