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

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int k = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    setupConsole();

    std::cout << "--- Завдання 6 ---" << std::endl;
    std::vector<int> nums1 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    std::cout << "Вхід: { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }" << std::endl;

    int k = removeDuplicates(nums1);

    std::cout << "Вивід (k): " << k << std::endl;

    std::cout << "Масив: [ ";
    for (int i = 0; i < k; i++) {
        std::cout << nums1[i] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}