#include "DArr.h"

DArr::DArr() {
    arr = new int[defSize];
    size = defSize;
}

DArr::DArr(int size) {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

DArr::DArr(int size, int n) {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = n;
    }
}

//копирование
DArr::DArr(const DArr& dinamic) {
    size = dinamic.size;
    arr = new int[size];
    for (int i = 0; i < dinamic.size; ++i) {
        arr[i] = dinamic.arr[i];
    }
}

//перемещение
DArr::DArr(DArr&& dinamic): arr(dinamic.arr), size(dinamic.size)
{
    dinamic.arr = nullptr;
}

DArr::~DArr()
{
    delete[] arr;
}

int DArr::getSize() const {
    return size;
}

int DArr::getElem(const int i) const {
    if (i >= size) {
        throw std::exception("Низзя");
    }
    return arr[i];
}
void DArr::resize(const int newSize) {
    int* newArray = new int[newSize];
    if (size >= newSize)
    {
        for (int i = 0; i < newSize; i++) {
            newArray[i] = arr[i];
        }
        delete[] arr;
        size = newSize;
        arr = newArray;
    }
    if (size < newSize)
    {
        
        for (int i = 0; i < size; i++) {
            newArray[i] = arr[i];
        }
        for (int i = size; i < newSize; i++) {
            newArray[i] = 0;
        }
        delete[] arr;
        size = newSize;
        arr = newArray;
    }
}

//присваивание
DArr& DArr::operator=(const DArr& diname) {
    if (&diname != this && *this != diname)
    {
        delete[] arr;
        size = diname.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = diname.arr[i];
        }
    }
    return *this;
}

//перемещение
DArr& DArr::operator=(DArr&& dinamic)
{
    if (&dinamic != this && *this != dinamic)
    {
        delete[] arr;
        size = dinamic.size;
        arr = dinamic.arr;
        dinamic.arr = nullptr;
        return *this;
    }
    delete[] dinamic.arr;
    return *this;
}

int& DArr::operator[](const int index) const {
    if (index >= getSize())
        throw std::exception("Низзя");
    return arr[index];
}

bool operator== (const DArr& d1, const DArr& d2) {
    if (d1.size != d2.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] != d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator != (const DArr& d1, const DArr& d2)
{
    return !(d1 == d2);
}
 
bool operator> (const DArr& d1, const DArr& d2)
{
    const int minSize = std::min(d1.size, d2.size);
    for (int i = 0; i < minSize; i++) {
        if (d1.arr[i] > d2.arr[i]) {
            return true;
        }
        else if (d1.arr[i] < d2.arr[i])
        {
            return false;
        }
    }
    return minSize != d1.size;
}

bool operator>= (const DArr& d1, const DArr& d2)
{
    return d1 > d2 || d1 == d2;
}

bool operator< (const DArr& d1, const DArr& d2)
{
    return !(d1 >= d2);
}

bool operator<= (const DArr& d1, const DArr& d2)
{
    return !(d1 > d2);
}

DArr operator+(const DArr& d1, const DArr& d2) {
    DArr result = DArr(d1.size + d2.size);
    for (int i = 0; i < d1.size; i++) {
        result.arr[i] = d1.arr[i];
    }
    for (int j = d1.size; j < (d1.size + d2.size); j++) {
        result.arr[j] = d2.arr[j - d1.size];
    }
    return result;
}

std::ostream& operator<< (std::ostream& out, const DArr& dinamic)
{
    out << "DArr(";
    for (int i = 0; i < dinamic.getSize(); i++) {
        out << dinamic.arr[i] << ", ";
    }
    out << ")";

    return out;
}

std::istream& operator>> (std::istream& in, DArr& dinamic)
{
    in >> dinamic.size;
    for (int i = 0; i < dinamic.getSize(); i++) {
        in >> dinamic.arr[i];
    }
    return in;
}
