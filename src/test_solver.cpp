#include <iostream>
#include "choleskysolver.hpp"

int main() {
    // Тест 1: Матрица 3x3
    {
        Matrix A1(3, 3);
        A1(0, 0) = 4;  A1(0, 1) = 12; A1(0, 2) = -16;
        A1(1, 0) = 12; A1(1, 1) = 37; A1(1, 2) = -43;
        A1(2, 0) = -16; A1(2, 1) = -43; A1(2, 2) = 98;

        Matrix b1(3, 1);
        b1(0, 0) = 1;
        b1(1, 0) = 2;
        b1(2, 0) = 3;

        LinearSolver solver1(A1, b1);
        Matrix x1 = solver1.solve();

        std::cout << "Тест 1: Решение x1:\n" << x1 << std::endl;
        std::cout << "Проверка:\n" << A1 * x1 << "\n" << b1 << std::endl;
    }

    // Тест 2: Матрица 4x4
    {
        Matrix A2(4, 4);
        A2(0, 0) = 25; A2(0, 1) = 15; A2(0, 2) = -5; A2(0, 3) = 10;
        A2(1, 0) = 15; A2(1, 1) = 18; A2(1, 2) = 0;  A2(1, 3) = 6;
        A2(2, 0) = -5; A2(2, 1) = 0;  A2(2, 2) = 11; A2(2, 3) = -2;
        A2(3, 0) = 10; A2(3, 1) = 6;  A2(3, 2) = -2; A2(3, 3) = 14;

        Matrix b2(4, 1);
        b2(0, 0) = 1;
        b2(1, 0) = 2;
        b2(2, 0) = 3;
        b2(3, 0) = 4;

        LinearSolver solver2(A2, b2);
        Matrix x2 = solver2.solve();

        std::cout << "\nТест 2: Решение x2:\n" << x2 << std::endl;
        std::cout << "Проверка:\n" << A2 * x2 << "\n" << b2 << std::endl;
    }

    // Тест 3: Матрица 2x2 (простой случай)
    {
        Matrix A3(2, 2);
        A3(0, 0) = 4; A3(0, 1) = 1;
        A3(1, 0) = 1; A3(1, 1) = 3;

        Matrix b3(2, 1);
        b3(0, 0) = 1;
        b3(1, 0) = 2;

        LinearSolver solver3(A3, b3);
        Matrix x3 = solver3.solve();

        std::cout << "\nТест 3: Решение x3:\n" << x3 << std::endl;
        std::cout << "Проверка:\n" << A3 * x3 << "\n" << b3 << std::endl;
    }

    // Тест 4: Матрица 3x3 (случай с нулевыми элементами)
    {
        Matrix A4(3, 3);
        A4(0, 0) = 1; A4(0, 1) = 0; A4(0, 2) = 0;
        A4(1, 0) = 0; A4(1, 1) = 2; A4(1, 2) = 0;
        A4(2, 0) = 0; A4(2, 1) = 0; A4(2, 2) = 3;

        Matrix b4(3, 1);
        b4(0, 0) = 1;
        b4(1, 0) = 2;
        b4(2, 0) = 3;

        LinearSolver solver4(A4, b4);
        Matrix x4 = solver4.solve();

        std::cout << "\nТест 4: Решение x4:\n" << x4 << std::endl;
        std::cout << "Проверка:\n" << A4 * x4 << "\n" << b4 << std::endl;
    }

    return 0;
}
