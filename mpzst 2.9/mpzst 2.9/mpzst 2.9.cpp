#include <vector>
#include <algorithm>
#include <iostream>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h> 
#endif

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

void printVector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> replaceElements(std::vector<int>& arr) {
    int n = arr.size();
    int maxSoFar = -1;

    for (int i = n - 1; i >= 0; i--) {
        int currentValue = arr[i];
        arr[i] = maxSoFar;
        maxSoFar = std::max(maxSoFar, currentValue);
    }
    return arr;
}

int main() {
    setupConsole();

    std::cout << "--- Завдання 9 ---" << std::endl;
    std::vector<int> arr1 = { 17, 18, 5, 4, 6, 1 };
    std::cout << "Вхід: ";
    printVector(arr1);

    std::vector<int> result = replaceElements(arr1);

    std::cout << "Вивід: ";
    printVector(result);

    return 0;
}