#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <sstream>

class Vector {
private:
    int* data;          // Массив элементов
    size_t size;        // Количество элементов
    size_t capacity;    // Вместимость массива

    void increaseCapacity(); // Увеличение вместимости

public:
    Vector();               // Конструктор
    ~Vector();              // Деструктор

    void push_back(int value); // Добавление элемента
    int at(size_t index) const; // Доступ к элементу
    void update(size_t index, int value); // Обновление элемента
    void erase(size_t index); // Удаление элемента

    size_t getSize() const;   // Получение размера
    std::string toString() const; // Преобразование в строку

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};

#endif // VECTOR_H