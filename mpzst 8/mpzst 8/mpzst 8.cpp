#include <vector>
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

bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();

    if (n < 3) {
        return false;
    }

    int i = 0;

    while (i + 1 < n && arr[i] < arr[i + 1]) {
        i++;
    }

    if (i == 0 || i == n - 1) {
        return false;
    }

    while (i + 1 < n && arr[i] > arr[i + 1]) {
        i++;
    }

    return i == n - 1;
}

int main() {
    setupConsole();

    std::cout << "--- Çàâäàííÿ 8 ---" << std::endl;
    std::cout << std::boolalpha;

    std::vector<int> arr1 = { 0, 3, 2, 1 };
    std::cout << "Âõ³ä: {0, 3, 2, 1}" << std::endl;
    std::cout << "Âèâ³ä: " << validMountainArray(arr1) << std::endl;

    std::vector<int> arr2 = { 3, 5, 5 };
    std::cout << "Âõ³ä: {3, 5, 5}" << std::endl;
    std::cout << "Âèâ³ä: " << validMountainArray(arr2) << std::endl;

    std::vector<int> arr3 = { 2, 1 };
    std::cout << "Âõ³ä: {2, 1}" << std::endl;
    std::cout << "Âèâ³ä: " << validMountainArray(arr3) << std::endl;

    return 0;
}