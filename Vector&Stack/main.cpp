#include "D:\Vector+Stack\Vector&Stack\Domain\Vector.cpp" // ����������� ���������� ��� �������������� � ��������
#include <iostream> // ��� ����������� ������� �����/������

void handleInvalidInput(std::istream& input, std::ostream& output) {
    if (input.fail()) {
        input.clear(); // ���������� ���� ������
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ���������� ������ � ������
        output << "������: ������� ������������ ��������. ���������� �����.\n";
    }
}

void runVectorInterface(std::istream& input, std::ostream& output) {
    Vector vec; // ������� ������ �������
    bool exit = false; // ���� ���������� ������
    int choice; // ���������� ��� �������� ������ ������������

    while (!exit) {
        // ����� ���� � �������� �����
        output << "\n����:\n";
        output << "1. �������� �������\n";
        output << "2. �������� ������� �� �������\n";
        output << "3. �������� �������\n";
        output << "4. ������� �������\n";
        output << "5. �������� ���� ������\n";
        output << "6. ��������� ������\n";
        output << "������� ��� �����: ";
        output.flush(); // �������������� ������ ������ � �����

        input >> choice; // ��������� ����� ������������ �� �������� ������
        handleInvalidInput(input, output); // �������� ������������ �����

        if (input.fail()) {
            continue; // ���� ���� ������������, ���������� ���������� ����� ������� ��������
        }

        switch (choice) {
        case 1: { // ���������� ��������
            int value;
            output << "������� ��������: ";
            output.flush();
            input >> value;
            handleInvalidInput(input, output); // �������� ������������ �����

            if (input.fail()) {
                break;
            }

            vec.push_back(value); // ��������� �������� � ������
            output << "������� ��������.\n";
            break;
        }
        case 2: { // ������ ��������
            size_t index;
            output << "������� ������: ";
            output.flush();
            input >> index;
            handleInvalidInput(input, output); // �������� ������������ �����

            if (input.fail()) {
                break;
            }

            try {
                output << "�������: " << vec.at(index) << "\n"; // ������� �������
            }
            catch (const std::out_of_range& e) {
                output << "������: " << e.what() << "\n"; // ��������� ������ �� �������
            }
            break;
        }
        case 3: { // ���������� ��������
            size_t index;
            int value;
            output << "������� ������: ";
            output.flush();
            input >> index;
            handleInvalidInput(input, output); // �������� ������������ �����

            if (input.fail()) {
                break;
            }

            output << "������� ����� ��������: ";
            output.flush();
            input >> value;
            handleInvalidInput(input, output); // �������� ������������ �����

            if (input.fail()) {
                break;
            }

            try {
                vec.update(index, value); // ��������� ��������
                output << "������� ��������.\n";
            }
            catch (const std::out_of_range& e) {
                output << "������: " << e.what() << "\n"; // ��������� ������ �� �������
            }
            break;
        }
        case 4: { // �������� ��������
            size_t index;
            output << "������� ������: ";
            output.flush();
            input >> index;
            handleInvalidInput(input, output); // �������� ������������ �����

            if (input.fail()) {
                break;
            }
            try {
                vec.erase(index); // ������� �������
                output << "������� ������.\n";
            }
            catch (const std::out_of_range& e) {
                output << "������: " << e.what() << "\n"; // ��������� ������ �� �������
            }
            break;
        }
        case 5: { // ����� ����� �������
            output << "������� ������: " << vec.toString() << "\n"; // ���������� toString()
            break;
        }
        case 6: { // ���������� ������
            exit = true; // ������������� ���� ���������� ������
            break;
        }
        default: {
            output << "�������� �����. ���������� �����.\n";
            break;
        }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ������ ����������������� ���������� � �������������� ����������� �������
    runVectorInterface(std::cin, std::cout);

    return 0; // ���������� ���������
}
