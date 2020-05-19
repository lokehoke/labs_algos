#pragma once
#include "BitField.h"
#include <iostream>

class TSet
{
private:
    int MaxPower;       // максимальная мощность множества
    TBitField BitField; // битовое поле для хранения хар-го вектора
public:
    TSet(int mp);
    TSet(const TSet &s);       // конструктор копирования
    TSet(const TBitField &bf); // конструктор преобразования типа
    operator TBitField();      // преобразование типа к битовому полю

    int GetMaxPower(void) const;     // максимальная мощность множества
    void InsElem(const int n);       // включить элемент в множество
    void DelElem(const int n);       // удалить элемент из множества
    int IsMember(const int n) const; // проверить наличие элемента в

    int operator==(const TSet &s);  // сравнение
    TSet &operator=(const TSet &s); // присваивание
    TSet operator+(const int n);    // включение элемента в множество
    TSet operator+(const TSet &s);  // объединение
    TSet operator*(const TSet &s);  // пересечение
    TSet operator-(void);           // дополнение

    friend std::istream &operator>>(std::istream &istr, TSet &bf);
    friend std::ostream &operator<<(std::ostream &ostr, const TSet &bf);
};
