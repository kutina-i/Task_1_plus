#pragma once
#include <iostream>

class DArr {
private:
    int* arr;
    int size;
public:
    static constexpr int defSize = 10;

    DArr();
    DArr(int size);
    DArr(int size, int n);
    DArr(const DArr& dinamic);
    DArr(DArr&& dinamic);
    ~DArr();

    int getSize() const;
    int getElem(const int i) const;
    void resize(int newSize);

    DArr& operator=(const DArr& dinamic);
    DArr& operator=(DArr&& dinamic);

    int& operator[](const int index) const;

    friend bool operator== (const DArr& d1, const DArr& d2);
    friend bool operator!= (const DArr& d1, const DArr& d2);

    friend bool operator> (const DArr& d1, const DArr& d2);
    friend bool operator<= (const DArr& d1, const DArr& d2);

    friend bool operator< (const DArr& d1, const DArr& d2);
    friend bool operator>= (const DArr& d1, const DArr& d2);

    friend DArr operator+(const DArr& d1, const DArr& d2);

    friend std::ostream& operator<<(std::ostream& out, const DArr& d1);
    friend std::istream& operator>>(std::istream& in, DArr& d1);
};