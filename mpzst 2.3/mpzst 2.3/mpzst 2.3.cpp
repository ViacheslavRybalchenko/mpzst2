#include <vector>
#include <cmath>
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

std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n);
    int left = 0;
    int right = n - 1;

    for (int pos = n - 1; pos >= 0; pos--) {
        if (std::abs(nums[left]) > std::abs(nums[right])) {
            result[pos] = nums[left] * nums[left];
            left++;
        }
        else {
            result[pos] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}

int main() {
    setupConsole();

    std::cout << "--- Завдання 3 ---" << std::endl;
    std::vector<int> nums1 = { -4, -1, 0, 3, 10 };
    std::cout << "Вхід: ";
    printVector(nums1);

    std::vector<int> result1 = sortedSquares(nums1);
    std::cout << "Вивід: ";
    printVector(result1);

    return 0;
}