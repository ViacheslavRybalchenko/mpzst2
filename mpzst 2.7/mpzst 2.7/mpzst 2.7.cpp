#include <vector>
#include <unordered_set>
#include <iostream>

#ifdef _WIN32
#include <windows.h> 
#endif

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

bool checkIfExist(std::vector<int>& arr) {
    std::unordered_set<int> seen;

    for (int num : arr) {
        if (seen.count(num * 2)) {
            return true;
        }
        if (num % 2 == 0 && seen.count(num / 2)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    setupConsole();

    std::cout << "--- Завдання 7 ---" << std::endl;
    std::vector<int> arr1 = { 10, 2, 5, 3 };
    std::cout << std::boolalpha;

    std::cout << "Вхід: {10, 2, 5, 3}" << std::endl;
    std::cout << "Вивід: " << checkIfExist(arr1) << std::endl;

    std::vector<int> arr2 = { 3, 1, 7, 11 };
    std::cout << "Вхід: {3, 1, 7, 11}" << std::endl;
    std::cout << "Вивід: " << checkIfExist(arr2) << std::endl;

    return 0;
}