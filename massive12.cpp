#include <iostream>
#include <iomanip>
#include <string>

int main() {
    int count;
    std::cout << "Введите количество проданных товаров: ";
    std::cin >> count;

    if (count <= 0) {
        std::cout << "количество товаров." << std::endl;
        return 0;
    }

    std::string* names = new std::string[count];
    int* quantities = new int[count];
    double* prices = new double[count];

    for (int i = 0; i < count; i++) {
        std::cout << "Введите название товара: ";
        std::cin >> names[i];
        std::cout << "Введите количество проданных единиц товара: ";
        std::cin >> quantities[i];
        std::cout << "Введите цену за единицу товара: ";
        std::cin >> prices[i];
    }

    double totalSales = 0;
    for (int i = 0; i < count; i++) {
        totalSales += quantities[i] * prices[i];
    }

    double averagePrice = totalSales / count;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Общая сумма продаж: " << totalSales << std::endl;
    std::cout << "Средняя цена за единицу товара: " << averagePrice << std::endl;

    // Сортировка товаров по названиям
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                std::swap(names[j], names[j + 1]);
                std::swap(quantities[j], quantities[j + 1]);
                std::swap(prices[j], prices[j + 1]);
            }
        }
    }

    std::cout << "Отсортированный список товаров:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << names[i] << " - " << quantities[i] << " шт. - " << prices[i] << " руб." << std::endl;
    }

    delete[] names;
    delete[] quantities;
    delete[] prices;

    return 0;
}

