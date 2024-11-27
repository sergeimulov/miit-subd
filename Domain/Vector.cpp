#include "Vector.h" // Подключение заголовочного файла Vector
#include <sstream>  // Для работы с потоками строк

// Реализация конструктора по умолчанию
Vector::Vector() : data(nullptr), size(0), capacity(0) {}

// Реализация деструктора
Vector::~Vector() {
    delete[] data; // Освобождение памяти, выделенной для массива
}

// Реализация метода для увеличения вместимости
void Vector::increaseCapacity() {
    capacity = (capacity == 0) ? 1 : capacity * 2; // Увеличение вместимости в 2 раза (или установка на 1)
    int* newData = new int[capacity]; // Выделение новой памяти
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i]; // Копирование элементов
    }
    delete[] data; // Освобождение старой памяти
    data = newData; // Переназначение указателя
}

// Реализация метода добавления элемента
void Vector::push_back(int value) {
    if (size == capacity) {
        increaseCapacity(); // Увеличение вместимости, если необходимо
    }
    data[size++] = value; // Добавление элемента и увеличение размера
}

// Реализация метода получения элемента по индексу
int Vector::at(size_t index) const {
    if (index >= size) { // Проверка на выход за пределы массива
        throw std::out_of_range("Index out of range"); // Генерация исключения
    }
    return data[index]; // Возврат элемента
}

// Реализация метода обновления элемента
void Vector::update(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value; // Обновление элемента
}

// Реализация метода удаления элемента
void Vector::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) { // Сдвиг элементов
        data[i] = data[i + 1];
    }
    --size; // Уменьшение размера
}

// Реализация метода получения размера
size_t Vector::getSize() const {
    return size;
}

// Реализация метода преобразования вектора в строку
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

// Реализация перегрузки оператора вывода
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << vec.toString(); // Вывод строки, представленной toString()
    return os;
}

// Реализация перегрузки оператора ввода
std::istream& operator>>(std::istream& is, Vector& vec) {
    size_t newSize;
    is >> newSize; // Чтение нового размера
    vec.size = newSize;
    vec.capacity = newSize;
    delete[] vec.data; // Освобождение старой памяти
    vec.data = new int[newSize]; // Выделение новой памяти
    for (size_t i = 0; i < newSize; ++i) {
        is >> vec.data[i]; // Чтение элементов
    }
    return is;
}
