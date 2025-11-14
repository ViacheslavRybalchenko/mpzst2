#include <vector>
#include <string>    
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

int findNumbers(std::vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
        int numDigits = std::to_string(num).length();
        if (numDigits % 2 == 0) {
            count++;
        }
    }
    return count;
}
int main() {
    setupConsole(); 

    std::vector<int> nums1 = { 12, 345, 2, 6, 7896 };
    std::cout << "--- Завдання 2 ---" << std::endl;
    std::cout << "Вхід: {12, 345, 2, 6, 7896}" << std::endl;
    std::cout << "Вивід: " << findNumbers(nums1) << std::endl;

    std::vector<int> nums2 = { 555, 901, 482, 1771 };
    std::cout << "Вхід: {555, 901, 482, 1771}" << std::endl;
    std::cout << "Вивід: " << findNumbers(nums2) << std::endl;

    return 0;
}