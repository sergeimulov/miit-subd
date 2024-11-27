#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <sstream>

class Vector {
private:
    int* data;          // ������ ���������
    size_t size;        // ���������� ���������
    size_t capacity;    // ����������� �������

    void increaseCapacity(); // ���������� �����������

public:
    Vector();               // �����������
    ~Vector();              // ����������

    void push_back(int value); // ���������� ��������
    int at(size_t index) const; // ������ � ��������
    void update(size_t index, int value); // ���������� ��������
    void erase(size_t index); // �������� ��������

    size_t getSize() const;   // ��������� �������
    std::string toString() const; // �������������� � ������

    // ���������� ����������
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};

#endif // VECTOR_H