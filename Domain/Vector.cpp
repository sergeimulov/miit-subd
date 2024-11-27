#include "Vector.h" // ����������� ������������� ����� Vector
#include <sstream>  // ��� ������ � �������� �����

// ���������� ������������ �� ���������
Vector::Vector() : data(nullptr), size(0), capacity(0) {}

// ���������� �����������
Vector::~Vector() {
    delete[] data; // ������������ ������, ���������� ��� �������
}

// ���������� ������ ��� ���������� �����������
void Vector::increaseCapacity() {
    capacity = (capacity == 0) ? 1 : capacity * 2; // ���������� ����������� � 2 ���� (��� ��������� �� 1)
    int* newData = new int[capacity]; // ��������� ����� ������
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i]; // ����������� ���������
    }
    delete[] data; // ������������ ������ ������
    data = newData; // �������������� ���������
}

// ���������� ������ ���������� ��������
void Vector::push_back(int value) {
    if (size == capacity) {
        increaseCapacity(); // ���������� �����������, ���� ����������
    }
    data[size++] = value; // ���������� �������� � ���������� �������
}

// ���������� ������ ��������� �������� �� �������
int Vector::at(size_t index) const {
    if (index >= size) { // �������� �� ����� �� ������� �������
        throw std::out_of_range("Index out of range"); // ��������� ����������
    }
    return data[index]; // ������� ��������
}

// ���������� ������ ���������� ��������
void Vector::update(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value; // ���������� ��������
}

// ���������� ������ �������� ��������
void Vector::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) { // ����� ���������
        data[i] = data[i + 1];
    }
    --size; // ���������� �������
}

// ���������� ������ ��������� �������
size_t Vector::getSize() const {
    return size;
}

// ���������� ������ �������������� ������� � ������
std::string Vector::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < size; ++i) {
        oss << data[i];
        if (i < size - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

// ���������� ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << vec.toString(); // ����� ������, �������������� toString()
    return os;
}

// ���������� ���������� ��������� �����
std::istream& operator>>(std::istream& is, Vector& vec) {
    size_t newSize;
    is >> newSize; // ������ ������ �������
    vec.size = newSize;
    vec.capacity = newSize;
    delete[] vec.data; // ������������ ������ ������
    vec.data = new int[newSize]; // ��������� ����� ������
    for (size_t i = 0; i < newSize; ++i) {
        is >> vec.data[i]; // ������ ���������
    }
    return is;
}
