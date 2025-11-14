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

void printVector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

void duplicateZeros(std::vector<int>& arr) {
    int n = arr.size();
    int possibleDups = 0;
    int lastIndex = n - 1;

    for (int left = 0; left <= lastIndex - possibleDups; left++) {
        if (arr[left] == 0) {
            if (left == lastIndex - possibleDups) {
                arr[lastIndex] = 0;
                lastIndex--;
                break;
            }
            possibleDups++;
        }
    }

    int readIndex = lastIndex - possibleDups;
    int writeIndex = lastIndex;

    for (int i = readIndex; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[writeIndex] = 0;
            writeIndex--;
            arr[writeIndex] = 0;
            writeIndex--;
        }
        else {
            arr[writeIndex] = arr[i];
            writeIndex--;
        }
    }
}

int main() {
    setupConsole();

    std::cout << "--- Завдання 4 ---" << std::endl;
    std::vector<int> arr1 = { 1, 0, 2, 3, 0, 4, 5, 0 };
    std::cout << "Вхід: ";
    printVector(arr1);

    duplicateZeros(arr1);
    std::cout << "Вивід: ";
    printVector(arr1);

    return 0;
}