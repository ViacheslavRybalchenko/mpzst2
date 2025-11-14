#include <vector>
#include <algorithm>
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

std::vector<int> sortArrayByParity(std::vector<int>& nums) {
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
        if (nums[readIndex] % 2 == 0) {
            std::swap(nums[writeIndex], nums[readIndex]);
            writeIndex++;
        }
    }
    return nums;
}

int main() {
    setupConsole();

    std::cout << "--- Завдання 10 ---" << std::endl;
    std::vector<int> nums1 = { 3, 1, 2, 4 };
    std::cout << "Вхід: ";
    printVector(nums1);

    std::vector<int> result = sortArrayByParity(nums1);

    std::cout << "Вивід: ";
    printVector(result);

    return 0;
}